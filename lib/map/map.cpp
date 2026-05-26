#include "map.h"
#include "mappixmapitem.h"


#include <QContextMenuEvent>
#include <QDragEnterEvent>
#include <QDragMoveEvent>
#include <QDropEvent>
#include <QFileDialog>
#include <QHBoxLayout>
#include <QMimeData>
#include <QMimeDatabase>
#include <QMimeType>
#include <QMouseEvent>
#include <QPainter>
#include <QPushButton>
#include <QScrollBar>
#include <QStyle>
#include <QUrl>
#include <QVBoxLayout>
#include <QWheelEvent>



MapGraphicsScene::MapGraphicsScene(
    QWidget* aParent
)
: QGraphicsScene(aParent)
{
}

void MapGraphicsScene::drawForeground(QPainter* aPainter, const QRectF &aRect)
{
    QPen gridPen(QColor(0, 0, 0, 40), 1);
    gridPen.setCosmetic(true);
    aPainter->setPen(gridPen);

    const float lineStartX = std::floor(aRect.left() / mCellSize) * mCellSize;
    const float lineStartY = std::floor(aRect.top()  / mCellSize) * mCellSize;

    for (float x = lineStartX; x <= aRect.right(); x += mCellSize) {
        aPainter->drawLine(QPointF(x, aRect.top()), QPointF(x, aRect.bottom()));
    }

    for (float y = lineStartY; y <= aRect.bottom(); y += mCellSize) {
        aPainter->drawLine(QPointF(aRect.left(), y), QPointF(aRect.right(), y));
    }
}

MapGraphicsView::MapGraphicsView(
    QWidget* aParent
)
: QGraphicsView(aParent)
{
    setAcceptDrops(true);
}

void MapGraphicsView::setMode(MapMode aMode)
{
    mCurrentMode = aMode;
    mCurrentOperation = MapOperation::None;

    switch (aMode) {
    case MapMode::Select:
        setCursor(Qt::ArrowCursor);
        setDragMode(QGraphicsView::RubberBandDrag);
        setInteractive(true);
        break;
    case MapMode::Rotate:
        setCursor(Qt::OpenHandCursor);
        setDragMode(QGraphicsView::NoDrag);
        setInteractive(false);
        break;
    }
}

bool MapGraphicsView::isLocalImageUrl(const QUrl& aUrl)
{
    if (!aUrl.isLocalFile()) return false;

    static QMimeDatabase sMimeDb;
    QMimeType mime = sMimeDb.mimeTypeForUrl(aUrl);
    return mime.name().startsWith("image/");
}

bool MapGraphicsView::hasLocalImageUrls(const QMimeData* aData) const
{
    if (!aData->hasUrls()) return false;

    for (const QUrl& url : aData->urls()) {
        if (isLocalImageUrl(url)) return true;
    }

    return false;
}

void MapGraphicsView::dragEnterEvent(QDragEnterEvent* aEvent)
{
    if (hasLocalImageUrls(aEvent->mimeData())) {
        aEvent->acceptProposedAction();
        return;
    }

    QGraphicsView::dragEnterEvent(aEvent);
}

void MapGraphicsView::dragMoveEvent(QDragMoveEvent* aEvent)
{
    if (hasLocalImageUrls(aEvent->mimeData())) {
        aEvent->acceptProposedAction();
        return;
    }

    QGraphicsView::dragMoveEvent(aEvent);
}

void MapGraphicsView::dropEvent(QDropEvent* aEvent)
{
    if (hasLocalImageUrls(aEvent->mimeData())) {
        for (const QUrl& url : aEvent->mimeData()->urls()) {
            if (!isLocalImageUrl(url)) continue;
            emit imageDropped(url.toLocalFile(), mapToScene(aEvent->position().toPoint()));
        }
        aEvent->acceptProposedAction();
        return;
    }

    QGraphicsView::dropEvent(aEvent);
}

void MapGraphicsView::contextMenuEvent(QContextMenuEvent* aEvent)
{
    if (mCurrentOperation != MapOperation::None) {
        return;
    }
    QGraphicsView::contextMenuEvent(aEvent);
}

void MapGraphicsView::mousePressEvent(QMouseEvent* aEvent)
{
    if (mCurrentOperation != MapOperation::None) {
        return;
    }

    if (aEvent->button() == Qt::LeftButton && mCurrentMode == MapMode::Rotate) {
        mCurrentOperation = MapOperation::Rotate;
        mLastMousePos = aEvent->pos();
        setCursor(Qt::ClosedHandCursor);
        return;
    }

    if (aEvent->button() == Qt::MiddleButton) {
        mCurrentOperation = MapOperation::Pan;
        mLastMousePos = aEvent->pos();
        setCursor(Qt::ClosedHandCursor);
        return;
    }

    if (aEvent->button() == Qt::LeftButton && mCurrentMode == MapMode::Select) {
        mCurrentOperation = MapOperation::Select;
    }

    QGraphicsView::mousePressEvent(aEvent);
}

void MapGraphicsView::mouseMoveEvent(QMouseEvent* aEvent)
{
    switch (mCurrentOperation) {
    case MapOperation::Rotate:
    {
        const QPointF center = viewport()->rect().center();
        const float currentAngle = std::atan2(
            aEvent->pos().y() - center.y(),
            aEvent->pos().x() - center.x()
        );
        const float lastAngle = std::atan2(
            mLastMousePos.y() - center.y(),
            mLastMousePos.x() - center.x()
        );

        rotate(qRadiansToDegrees(currentAngle - lastAngle));
        mLastMousePos = aEvent->pos();
        return;
    }
    case MapOperation::Pan:
    {
        const QPoint delta = aEvent->pos() - mLastMousePos;
        mLastMousePos = aEvent->pos();

        horizontalScrollBar()->setValue(horizontalScrollBar()->value() - delta.x());
        verticalScrollBar()->setValue(verticalScrollBar()->value() - delta.y());
        return;
    }
    case MapOperation::Select:
    case MapOperation::None:
        break;
    }

    QGraphicsView::mouseMoveEvent(aEvent);
}

void MapGraphicsView::mouseReleaseEvent(QMouseEvent* aEvent)
{
    const bool doneWithOperation =
        (mCurrentOperation == MapOperation::Rotate && aEvent->button() == Qt::LeftButton)
        || (mCurrentOperation == MapOperation::Pan && aEvent->button() == Qt::MiddleButton)
        || (mCurrentOperation == MapOperation::Select && aEvent->button() == Qt::LeftButton);

    if (doneWithOperation) {
        mCurrentOperation = MapOperation::None;

        if (mCurrentMode == MapMode::Rotate) {
            setCursor(Qt::OpenHandCursor);
        }
        else {
            setCursor(Qt::ArrowCursor);
        }
    }

    if (mCurrentOperation == MapOperation::None) {
        QGraphicsView::mouseReleaseEvent(aEvent);
    }
}

void MapGraphicsView::wheelEvent(QWheelEvent* aEvent)
{
    const float minimumZoom = 0.1;
    const float maximumZoom = 10.0;
    const float zoomFactorPerStep = 1.15;
    const float wheelDegreesPerStep = 15.0;

    const float qtAngleDeltaScaleFactor = 1.0 / 8.0;
    const float degrees = aEvent->angleDelta().y() * qtAngleDeltaScaleFactor;
    const float zoomSteps = degrees / wheelDegreesPerStep;
    const float zoomFactor = std::pow(zoomFactorPerStep, zoomSteps);

    const float newZoomLevel = std::clamp(mZoomLevel * zoomFactor, minimumZoom, maximumZoom);
    const float scaleDelta = newZoomLevel / mZoomLevel;

    const QPointF anchorScene = mapToScene(aEvent->position().toPoint());
    const QPointF anchorViewport = aEvent->position().toPoint();

    setTransformationAnchor(QGraphicsView::AnchorViewCenter);
    scale(scaleDelta, scaleDelta);

    const QPointF delta = anchorViewport - mapFromScene(anchorScene);
    QTransform t = transform();
    t = QTransform::fromTranslate(delta.x(), delta.y()) * t;
    setTransform(t);

    mZoomLevel = newZoomLevel;
}

Map::Map(
    QWidget* aParent
)
: QWidget(aParent)
, mGraphicsScene(new MapGraphicsScene(this))
, mGraphicsView(new MapGraphicsView(this))
{
    mGraphicsView->setScene(mGraphicsScene);
    mGraphicsScene->setSceneRect(-1e4, -1e4, 2e4, 2e4);

    mGraphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    mGraphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    mToolBar = new QWidget(mGraphicsView);
    mToolBar->setObjectName("MapToolBar");
    mToolBar->setStyleSheet(
        "#MapToolBar { "
        "    background-color: #333333; "
        "    border-radius: 8px; "
        "}"
        "#MapToolBar QPushButton { "
        "    background-color: #444444; "
        "    border: none; "
        "    border-radius: 8px; "
        "    min-width: 32px; "
        "    min-height: 32px; "
        "    max-width: 32px; "
        "    max-height: 32px; "
        "}"
        "#MapToolBar QPushButton:hover { "
        "    background-color: #555555; "
        "}"
        "#MapToolBar QPushButton:pressed { "
        "    background-color: #666666; "
        "}"
    );

    auto toolbarLayout = new QHBoxLayout(mToolBar);
    toolbarLayout->setContentsMargins(8, 8, 8, 8);
    toolbarLayout->setSpacing(8);

    mButtonGroup = new QButtonGroup(this);
    mButtonGroup->setExclusive(true);

    mSelectButton = new QPushButton(mToolBar);
    mSelectButton->setIcon(style()->standardIcon(QStyle::SP_FileDialogDetailedView));
    mSelectButton->setToolTip("Select");
    mButtonGroup->addButton(mSelectButton, static_cast<int>(MapMode::Select));
    toolbarLayout->addWidget(mSelectButton);

    mRotateButton = new QPushButton(mToolBar);
    mRotateButton->setIcon(style()->standardIcon(QStyle::SP_BrowserReload));
    mRotateButton->setToolTip("Rotate");
    mButtonGroup->addButton(mRotateButton, static_cast<int>(MapMode::Rotate));
    toolbarLayout->addWidget(mRotateButton);

    mImportButton = new QPushButton(mToolBar);
    mImportButton->setIcon(style()->standardIcon(QStyle::SP_DialogOpenButton));
    mImportButton->setToolTip("Import Image");
    toolbarLayout->addWidget(mImportButton);

    connect(mButtonGroup, &QButtonGroup::idClicked, this, [this](int id) {
        mGraphicsView->setMode(static_cast<MapMode>(id));
    });

    connect(mImportButton, &QPushButton::clicked, this, &Map::importImage);

    connect(mGraphicsView, &MapGraphicsView::imageDropped, this, [this](const QString& aPath, const QPointF& aScenePos) {
        addImage(aPath, aScenePos);
    });

    auto layout = new QVBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->addWidget(mGraphicsView);

    mGraphicsView->setMode(MapMode::Select);
}

void Map::importImage()
{
    const QString path = QFileDialog::getOpenFileName(
        this,
        "Import Image",
        QString(),
        "Images (*.png *.jpg *.jpeg *.bmp *.webp)"
    );

    if (path.isEmpty())
        return;

    const QPointF center = mGraphicsView->mapToScene(
        mGraphicsView->viewport()->rect().center()
    );

    addImage(path, center);
}

void Map::addImage(const QString& aPath, const QPointF& aScenePos)
{
    QPixmap pixmap(aPath);
    if (pixmap.isNull())
        return;

    auto item = new MapPixmapItem(pixmap);
    item->setPos(aScenePos.x() - pixmap.width()  / 2.0,
                 aScenePos.y() - pixmap.height() / 2.0);
    mGraphicsScene->addItem(item);
}

void Map::positionToolbar()
{
    if (!mToolBar || !mGraphicsView) return;

    const int toolbarWidth = mToolBar->sizeHint().width();
    const int toolbarHeight = mToolBar->sizeHint().height();
    const int margin = 10;

    const int x = margin;
    const int y = mGraphicsView->height() - toolbarHeight - margin;

    mToolBar->setGeometry(x, y, toolbarWidth, toolbarHeight);
}

void Map::resizeEvent(QResizeEvent* aEvent)
{
    QWidget::resizeEvent(aEvent);
    positionToolbar();
}
