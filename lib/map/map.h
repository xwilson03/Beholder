#pragma once

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QObject>
#include <QWidget>


class MapGraphicsScene : public QGraphicsScene
{
    Q_OBJECT

    float mCellSize = 64.0;

protected:
    void drawForeground(QPainter* aPainter, const QRectF& aRect) override;

public:
    MapGraphicsScene(
        QWidget* parent = nullptr
    );
};


class MapGraphicsView : public QGraphicsView
{
    Q_OBJECT

public:
    MapGraphicsView(
        QWidget* parent = nullptr
    );
};


class Map : public QWidget
{
    Q_OBJECT

public:
    Map(
        QWidget* parent = nullptr
    );

private:
    MapGraphicsScene* _graphics_scene = nullptr;
    MapGraphicsView*  _graphics_view  = nullptr;
};
