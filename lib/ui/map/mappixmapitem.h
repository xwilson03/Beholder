#pragma once

#include <QGraphicsPixmapItem>
#include <QPen>
#include <QPointF>
#include <QPixmap>


class MapPixmapItem : public QGraphicsPixmapItem
{
public:
    MapPixmapItem(const QPixmap& aPixmap);

    QRectF boundingRect() const override;

    QPainterPath shape() const override;

    void paint(QPainter* aPainter, const QStyleOptionGraphicsItem* aOption, QWidget* aWidget) override;

protected:
    void hoverMoveEvent(QGraphicsSceneHoverEvent* aEvent) override;
    void mousePressEvent(QGraphicsSceneMouseEvent* aEvent) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent* aEvent) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent* aEvent) override;

private:
    enum Handle { None, TopLeft, TopRight, BottomLeft, BottomRight, Top, Bottom, Left, Right, MoveBody, Rotate };
    Handle handleAtPos(const QPointF& aPos) const;
    QPointF anchorLocal(Handle aHandle) const;
    void updateCursor(const QPointF& aPos);
    float currentViewZoom() const;

    Handle  mActiveHandle = None;
    QPointF mPrevScenePos;
    QPointF mDragStartAnchorScene;
    QPen    mOutlinePen;
    float   mScaleX = 1.0;
    float   mScaleY = 1.0;
    float   mScaleXAtDragStart = 1.0;
    float   mScaleYAtDragStart = 1.0;
    float   mRotation = 0.0f;
    float   mRotationAtDragStart = 0.0f;
    QPointF mRotationStartScenePos;

    static constexpr float kHandleSize = 8.0;
    static constexpr float kRotateHandleOffset = 15.0;
    static constexpr float kRotateHandleRadius = 4.0;
};
