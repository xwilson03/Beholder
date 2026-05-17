#include "map.h"

#include <QVBoxLayout>


MapGraphicsScene::MapGraphicsScene(
    QWidget* parent
)
: QGraphicsScene(parent)
{
}

void MapGraphicsScene::drawForeground(QPainter* aPainter, const QRectF &aRect)
{
    // Draw Gridlines
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
    QWidget* parent
)
: QGraphicsView(parent)
{
}

Map::Map(
    QWidget* parent
)
: QWidget(parent)
, _graphics_scene(new MapGraphicsScene(this))
, _graphics_view(new MapGraphicsView(this))
{
    _graphics_view->setScene(_graphics_scene);

    auto layout = new QVBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->addWidget(_graphics_view);
}
