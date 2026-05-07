#pragma once

#include <QGraphicsView>
#include <QObject>
#include <QWidget>


class Map : public QGraphicsView
{
    Q_OBJECT

public:
    Map(
        QWidget* parent = nullptr
    );

private:
    QGraphicsScene* _graphics_scene = nullptr;
};
