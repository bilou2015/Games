#include "Entity.h"


Entity::Entity(): QGraphicsObject(){

}


void Entity::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){
    painter->drawPixmap(this->m_pix.rect(),this->m_pix);
}

QRectF Entity::boundingRect() const{
    return this->m_pix.rect();
}


QPixmap Entity::getPix(){
    return this->m_pix;
}

void Entity::setPix(QPixmap pix){
    this->m_pix=pix;
}


QPointF Entity::getCentre(){
    return QPointF(this->x()+this->boundingRect().width()/2,this->y()+this->boundingRect().width()/2);

}

bool Entity::collisionWithArea(QPointF positionEntity){
    if(positionEntity.x()>=0 && positionEntity.y()>=20 && positionEntity.x()<=1650 && positionEntity.y()<=998)
        return true;
    return false;

}

void Entity::moveEntity(QPointF EndPos){
    if (this->collisionWithArea(EndPos)){
    this->setPos(EndPos);
}
}
qreal Entity::getSpeed(){
    return this->m_speed;
}

void Entity::setSpeed(qreal speed){
    this->m_speed=speed;
}
