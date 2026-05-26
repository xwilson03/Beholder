#pragma once

#include <QButtonGroup>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMimeData>
#include <QObject>
#include <QPointF>
#include <QPushButton>
#include <QString>
#include <QUrl>
#include <QWheelEvent>
#include <QWidget>


enum class MapMode { Select, Rotate };
enum class MapOperation { None, Rotate, Pan, Select };


class MapGraphicsScene : public QGraphicsScene
{
    Q_OBJECT

    float mCellSize = 64.0;

protected:
    void drawForeground(QPainter* aPainter, const QRectF& aRect) override;

public:
    MapGraphicsScene(
        QWidget* aParent = nullptr
    );
};


class MapGraphicsView : public QGraphicsView
{
    Q_OBJECT

public:
    MapGraphicsView(
        QWidget* aParent = nullptr
    );

    void setMode(MapMode aMode);

signals:
    void imageDropped(const QString& aPath, const QPointF& aScenePos);

protected:
    void contextMenuEvent(QContextMenuEvent* aEvent) override;
    void mousePressEvent(QMouseEvent* aEvent) override;
    void mouseMoveEvent(QMouseEvent* aEvent) override;
    void mouseReleaseEvent(QMouseEvent* aEvent) override;
    void wheelEvent(QWheelEvent* aEvent) override;
    void dragEnterEvent(QDragEnterEvent* aEvent) override;
    void dragMoveEvent(QDragMoveEvent* aEvent) override;
    void dropEvent(QDropEvent* aEvent) override;

private:
    bool hasLocalImageUrls(const QMimeData* aData) const;
    static bool isLocalImageUrl(const QUrl& aUrl);

    MapMode mCurrentMode = MapMode::Select;
    MapOperation mCurrentOperation = MapOperation::None;
    QPoint mLastMousePos;
    float mZoomLevel = 1.0;
};


class Map : public QWidget
{
    Q_OBJECT

public:
    Map(
        QWidget* aParent = nullptr
    );

private:
    void importImage();
    void addImage(const QString& aPath, const QPointF& aScenePos);
    void positionToolbar();
    void resizeEvent(QResizeEvent* aEvent) override;

    MapGraphicsScene* mGraphicsScene = nullptr;
    MapGraphicsView*  mGraphicsView  = nullptr;

    QWidget* mToolBar = nullptr;
    QButtonGroup* mButtonGroup = nullptr;
    QPushButton* mSelectButton = nullptr;
    QPushButton* mRotateButton = nullptr;
    QPushButton* mImportButton = nullptr;
};
