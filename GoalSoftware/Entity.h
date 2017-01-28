#ifndef ENTITY_H
#define ENTITY_H
#include <QGraphicsItem>
#include <QPainter>
#include "Keyboardengine.h"

class Entity : public QGraphicsObject{
public:
    Entity();
    QPixmap getPix();
    void setPix(QPixmap pix);
    QPainter getPainter();
    QPointF getCentre();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    QRectF boundingRect() const;
    bool collisionWithArea(QPointF positionEntity);
    void moveEntity(QPointF EndPos);
    qreal getSpeed();
    void setSpeed(qreal speed);

private:    
    qreal m_speed;
    QPixmap m_pix;
};

#endif // ENTITY_H
