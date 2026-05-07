#include "map.h"

#include <QGraphicsScene>
#include <QGraphicsView>


Map::Map(
    QWidget* parent
)
: _graphics_scene(new QGraphicsScene())
, QGraphicsView(parent)
{
}
