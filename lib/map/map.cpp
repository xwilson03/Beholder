#include "map.h"

#include <QVBoxLayout>


MapGraphicsScene::MapGraphicsScene(
    QWidget* parent
)
: QGraphicsScene(parent)
{
    setBackgroundBrush(QBrush(Qt::black));
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
