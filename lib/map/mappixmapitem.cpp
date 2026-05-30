#include "mappixmapitem.h"

#include <algorithm>
#include <cmath>
#include <numbers>

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsSceneHoverEvent>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QtMath>


MapPixmapItem::MapPixmapItem(const QPixmap& aPixmap)
: QGraphicsPixmapItem(aPixmap)
{
    mOutlinePen = QPen(QColor(0, 100, 255), 2);
    mOutlinePen.setCosmetic(true);

    setFlags(flags() | QGraphicsItem::ItemIsSelectable);
    setAcceptHoverEvents(true);
}

float MapPixmapItem::currentViewZoom() const
{
    const auto views = scene()->views();
    if (views.isEmpty()) return 1.0f;
    return std::sqrt(views.first()->transform().determinant());
}

QRectF MapPixmapItem::boundingRect() const
{
    QRectF r = QGraphicsPixmapItem::boundingRect();
    const float viewZoom = currentViewZoom();
    const float rhX = kRotateHandleRadius / (mScaleX * viewZoom);
    const float rhY = kRotateHandleRadius / (mScaleY * viewZoom);
    const float offs = kRotateHandleOffset / (mScaleY * viewZoom);
    r.adjust(-rhX, -offs - rhY, rhX, 0);
    return r;
}

QPainterPath MapPixmapItem::shape() const
{
    QPainterPath path = QGraphicsPixmapItem::shape();
    const float viewZoom = currentViewZoom();
    const float rhX = kRotateHandleRadius / (mScaleX * viewZoom);
    const float rhY = kRotateHandleRadius / (mScaleY * viewZoom);
    const float offs = kRotateHandleOffset / (mScaleY * viewZoom);
    path.addEllipse(QPointF(pixmap().width() / 2.0f, -offs), rhX, rhY);
    return path;
}

void MapPixmapItem::paint(QPainter* aPainter, const QStyleOptionGraphicsItem* aOption, QWidget* aWidget)
{
    QStyleOptionGraphicsItem opt = *aOption;
    opt.state &= ~QStyle::State_Selected;
    QGraphicsPixmapItem::paint(aPainter, &opt, aWidget);

    if (!isSelected()) return;

    aPainter->save();

    aPainter->setPen(mOutlinePen);
    aPainter->setBrush(Qt::NoBrush);
    aPainter->drawRect(pixmap().rect());

    const float viewZoom = currentViewZoom();
    const float cx = pixmap().width() / 2.0f;
    const float top = 0.0f;
    const float rhX = kRotateHandleRadius / (mScaleX * viewZoom);
    const float rhY = kRotateHandleRadius / (mScaleY * viewZoom);
    const float offs = kRotateHandleOffset / (mScaleY * viewZoom);

    aPainter->setBrush(mOutlinePen.color());
    aPainter->drawEllipse(QPointF(cx, top - offs), rhX, rhY);
    aPainter->drawLine(QPointF(cx, top), QPointF(cx, top - offs + rhY));
    aPainter->setBrush(Qt::NoBrush);

    aPainter->restore();
}

MapPixmapItem::Handle MapPixmapItem::handleAtPos(const QPointF& aPos) const
{
    const float viewZoom = currentViewZoom();

    const float hx = kHandleSize / (mScaleX * viewZoom);
    const float hy = kHandleSize / (mScaleY * viewZoom);

    const float left = 0;
    const float right = pixmap().width();
    const float top = 0;
    const float bottom = pixmap().height();

    const QRectF cornerTL(left, top, hx, hy);
    const QRectF cornerTR(right - hx, top, hx, hy);
    const QRectF cornerBL(left, bottom - hy, hx, hy);
    const QRectF cornerBR(right - hx, bottom - hy, hx, hy);

    const QRectF edgeT(left + hx, top, right - 2 * hx, hy);
    const QRectF edgeB(left + hx, bottom - hy, right - 2 * hx, hy);
    const QRectF edgeL(left, top + hy, hx, bottom - 2 * hy);
    const QRectF edgeR(right - hx, hy, hx, bottom - 2 * hy);

    const QRectF body(left, top, right, bottom);

    if (cornerTL.contains(aPos)) return TopLeft;
    if (cornerTR.contains(aPos)) return TopRight;
    if (cornerBL.contains(aPos)) return BottomLeft;
    if (cornerBR.contains(aPos)) return BottomRight;
    if (edgeT.contains(aPos))    return Top;
    if (edgeB.contains(aPos))    return Bottom;
    if (edgeL.contains(aPos))    return Left;
    if (edgeR.contains(aPos))    return Right;
    if (body.contains(aPos))     return MoveBody;

    if (!isSelected())           return None;

    const float cx = pixmap().width() / 2.0f;
    const float offs = kRotateHandleOffset / (mScaleY * viewZoom);
    const float dx = aPos.x() - cx;
    const float dy = aPos.y() + offs;
    if (((dx * dx) * mScaleX * mScaleX + (dy * dy) * mScaleY * mScaleY) * viewZoom * viewZoom
        < kRotateHandleRadius * kRotateHandleRadius)
        return Rotate;

    return None;
}

QPointF MapPixmapItem::anchorLocal(Handle aHandle) const
{
    const float left    = 0.0;
    const float right   = pixmap().width();
    const float top     = 0.0;
    const float bottom  = pixmap().height();
    const float centerX = right / 2.0;
    const float centerY = bottom / 2.0;

    switch (aHandle) {
        case TopLeft:     return QPointF(right,   bottom);
        case TopRight:    return QPointF(left,    bottom);
        case BottomLeft:  return QPointF(right,   top);
        case BottomRight: return QPointF(left,    top);
        case Top:         return QPointF(centerX, bottom);
        case Bottom:      return QPointF(centerX, top);
        case Left:        return QPointF(right,   centerY);
        case Right:       return QPointF(left,    centerY);
        case Rotate:      return QPointF(centerX, centerY);
    }

    return QPointF();
}

void MapPixmapItem::updateCursor(const QPointF& aPos)
{
    const Handle handle = handleAtPos(aPos);

    if (handle == None) {
        unsetCursor();
        return;
    }

    switch (handle) {
        case Rotate:
            setCursor(Qt::CrossCursor);
            return;
        case MoveBody:
            setCursor(Qt::SizeAllCursor);
            return;
        default:
            break;
    }

    float ldx = 0.0f, ldy = 0.0f;
    switch (handle) {
        case TopLeft:     ldx = -1; ldy = -1; break;
        case TopRight:    ldx =  1; ldy = -1; break;
        case BottomLeft:  ldx = -1; ldy =  1; break;
        case BottomRight: ldx =  1; ldy =  1; break;
        case Top:         ldx =  0; ldy = -1; break;
        case Bottom:      ldx =  0; ldy =  1; break;
        case Left:        ldx = -1; ldy =  0; break;
        case Right:       ldx =  1; ldy =  0; break;
        default:          ldx =  0; ldy =  0; break;
    }

    const auto views = scene()->views();
    float viewRotation = 0.0f;
    if (!views.isEmpty()) {
        const QTransform& t = views.first()->transform();
        viewRotation = qRadiansToDegrees(std::atan2(t.m12(), t.m22()));
    }

    const float totalRotation = mRotation + viewRotation;
    const float rad = qDegreesToRadians(totalRotation);
    const float cosA = std::cos(rad);
    const float sinA = std::sin(rad);
    const float sdx = ldx * cosA - ldy * sinA;
    const float sdy = ldx * sinA + ldy * cosA;

    const float sector = std::round(4.0f * std::atan2(-sdy, sdx) / std::numbers::pi);
    int idx = static_cast<int>(sector) % 8;
    if (idx < 0) idx += 8;

    static const Qt::CursorShape kCursors[] = {
        Qt::SizeHorCursor,   // 0: right
        Qt::SizeBDiagCursor, // 1: up-right
        Qt::SizeVerCursor,   // 2: up
        Qt::SizeFDiagCursor, // 3: up-left
        Qt::SizeHorCursor,   // 4: left
        Qt::SizeBDiagCursor, // 5: down-left
        Qt::SizeVerCursor,   // 6: down
        Qt::SizeFDiagCursor, // 7: down-right
    };
    setCursor(kCursors[idx]);
}

void MapPixmapItem::hoverMoveEvent(QGraphicsSceneHoverEvent* aEvent)
{
    updateCursor(aEvent->pos());
}

void MapPixmapItem::mousePressEvent(QGraphicsSceneMouseEvent* aEvent)
{
    if (aEvent->button() != Qt::LeftButton) {
        QGraphicsPixmapItem::mousePressEvent(aEvent);
        return;
    }

    const Handle handle = handleAtPos(aEvent->pos());
    if (handle == None) {
        QGraphicsPixmapItem::mousePressEvent(aEvent);
        return;
    }

    if (!isSelected()) {
        scene()->clearSelection();
        setSelected(true);
    }

    mActiveHandle = handle;
    mPrevScenePos = aEvent->scenePos();

    if (handle == Rotate) {
        mRotationAtDragStart = mRotation;
        mRotationStartScenePos = aEvent->scenePos();
        aEvent->accept();
        return;
    }

    mDragStartAnchorScene = mapToScene(anchorLocal(handle));
    mScaleXAtDragStart = mScaleX;
    mScaleYAtDragStart = mScaleY;
    aEvent->accept();
}

void MapPixmapItem::mouseMoveEvent(QGraphicsSceneMouseEvent* aEvent)
{
    if (!isSelected() || mActiveHandle == None) {
        QGraphicsPixmapItem::mouseMoveEvent(aEvent);
        return;
    }

    if (mActiveHandle == MoveBody) {
        setPos(pos() + aEvent->scenePos() - mPrevScenePos);
        mPrevScenePos = aEvent->scenePos();
        return;
    }

    if (mActiveHandle == Rotate) {
        const QPointF center = mapToScene(pixmap().width() / 2.0, pixmap().height() / 2.0);
        const QPointF currentVec = aEvent->scenePos() - center;
        const QPointF startVec   = mRotationStartScenePos - center;
        const float currentAngle = std::atan2(currentVec.y(), currentVec.x());
        const float startAngle   = std::atan2(startVec.y(), startVec.x());
        mRotation = mRotationAtDragStart + qRadiansToDegrees(currentAngle - startAngle);

        const float cx = pixmap().width() / 2.0f;
        const float cy = pixmap().height() / 2.0f;
        QTransform t;
        t.translate(cx, cy);
        t.rotate(mRotation);
        t.scale(mScaleX, mScaleY);
        t.translate(-cx, -cy);
        prepareGeometryChange();
        setTransform(t);
        return;
    }

    const QPointF currOffset = aEvent->scenePos() - mDragStartAnchorScene;
    const QPointF startOffset = mPrevScenePos - mDragStartAnchorScene;

    const float rad = qDegreesToRadians(mRotation);
    const float cosA = std::cos(rad);
    const float sinA = std::sin(rad);

    const float localXStart = startOffset.x() * cosA + startOffset.y() * sinA;
    const float localYStart = -startOffset.x() * sinA + startOffset.y() * cosA;
    const float localXCurr = currOffset.x() * cosA + currOffset.y() * sinA;
    const float localYCurr = -currOffset.x() * sinA + currOffset.y() * cosA;

    const float ratioX = (std::abs(localXStart) > 1.0f) ? static_cast<float>(std::max(0.0f, localXCurr / localXStart)) : 1.0f;
    const float ratioY = (std::abs(localYStart) > 1.0f) ? static_cast<float>(std::max(0.0f, localYCurr / localYStart)) : 1.0f;

    switch (mActiveHandle) {
        case TopLeft:
        case TopRight:
        case BottomLeft:
        case BottomRight:
            mScaleX = std::max(0.01f, mScaleXAtDragStart * ratioX);
            mScaleY = std::max(0.01f, mScaleYAtDragStart * ratioY);
            break;
        case Top:
        case Bottom:
            mScaleY = std::max(0.01f, mScaleYAtDragStart * ratioY);
            break;
        case Left:
        case Right:
            mScaleX = std::max(0.01f, mScaleXAtDragStart * ratioX);
            break;
        default:
            break;
    }

    const float cx = pixmap().width() / 2.0f;
    const float cy = pixmap().height() / 2.0f;
    QTransform t;
    t.translate(cx, cy);
    t.rotate(mRotation);
    t.scale(mScaleX, mScaleY);
    t.translate(-cx, -cy);

    prepareGeometryChange();
    setTransform(t);
    setPos(pos() + mDragStartAnchorScene - mapToScene(anchorLocal(mActiveHandle)));
}

void MapPixmapItem::mouseReleaseEvent(QGraphicsSceneMouseEvent* aEvent)
{
    if (mActiveHandle == None) {
        QGraphicsPixmapItem::mouseReleaseEvent(aEvent);
        return;
    }

    mActiveHandle = None;
    aEvent->accept();
    updateCursor(aEvent->pos());
}
