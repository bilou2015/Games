#include "PhysicalEngine.h"
#include "Entity.h"
#include "Team.h"
#include "math.h"
#include "Avatar.h"
#include "Ball.h"
#include "GraphicalEngine.h"
#include "Keyboardengine.h"
#include <iostream>
#include <QTimeLine>
#include <QGraphicsItemAnimation>

#include <time.h>

PhysicalEngine::PhysicalEngine(Kernel * kernel){
    m_kernel=kernel;
}

//Compute a next position of entity then move it at entity class

void PhysicalEngine::computeNextPosition(Entity * entity,int direction){
    switch( direction){
    case KeyBoardEngine::Right:{
        entity->moveEntity(QPointF(entity->x() + entity->getSpeed(),entity->y()));
        break;
    }
    case KeyBoardEngine::Left:{
        entity->moveEntity(QPointF(entity->x() - entity->getSpeed(),entity->y()));
        break;
    }
    case KeyBoardEngine::Up:{
        entity->moveEntity(QPointF(entity->x(),entity->y() - entity->getSpeed()));

        break;
    }
    case KeyBoardEngine::Down:{
        entity->moveEntity(QPointF(entity->x(),entity->y() + entity->getSpeed()));

        break;
    }
    case KeyBoardEngine::LeftUp:{
        entity->moveEntity(QPointF(entity->x() - entity->getSpeed(),entity->y() - entity->getSpeed()));


        break;
    }
    case KeyBoardEngine::RightUp:{
        entity->moveEntity(QPointF(entity->x() + entity->getSpeed(),entity->y() - entity->getSpeed()));
        break;
    }
    case KeyBoardEngine::LeftDown:{
        entity->moveEntity(QPointF(entity->x() - entity->getSpeed(),entity->y() + entity->getSpeed()));

        break;
    }
    case KeyBoardEngine::RightDown:{
        entity->moveEntity(QPointF(entity->x() + entity->getSpeed(),entity->y() + entity->getSpeed()));

        break;
    }

    default:
        break;
    }

}


//Check colision beetween two graphics entity

bool PhysicalEngine::checkCollide(Entity *entity1,Entity *entity2)
{
    if((entity2->x() >= entity1->x() + entity1->getPix().rect().width())
            || (entity2->x() + entity2->getPix().rect().width() <= entity1->x())
            || (entity2->y() >= entity1->y() + entity1->getPix().rect().height())
            || (entity2->y() + entity2->getPix().rect().height() <= entity1->y()))
        return false;
    else
        return true;
}


qreal PhysicalEngine::computeTimeOfMove(Entity *entity, const QPointF &end){
    return (this->getDistance(entity->pos(),end)/(qreal)entity->getSpeed())*10;

}

//distance entre deux point
qreal PhysicalEngine::getDistance(QPointF const& x1,QPointF const& x2){
    return sqrt(pow((x1.x()-x2.x()),2)+ pow( x1.y()-x2.y(),2));
}

//Animate a translation of entity

void PhysicalEngine::animTranslation(Entity *entity, QPointF const& end, qreal const& time, bool scaled){
    QPropertyAnimation *anim=new QPropertyAnimation(entity,"pos");
    anim->setDuration(time);
    if(scaled)
        this->scale(entity,time);
    anim->setStartValue(entity->pos());
    entity->moveEntity(end);
    anim->setEndValue(end);
    anim->setEasingCurve(QEasingCurve::OutQuad);
    anim->start(QPropertyAnimation::DeleteWhenStopped);

}


void PhysicalEngine::scale(Entity *entity, const qreal &time){
    QPropertyAnimation *anim=new QPropertyAnimation(entity,"scale");
    anim->setDuration(time);
    anim->setStartValue(1);
    anim->setKeyValueAt(0.001,2);
    anim->setEndValue(1);
    anim->setEasingCurve(QEasingCurve::InCubic);
    anim->start();
}


QPointF PhysicalEngine::randomPoint(qreal x1, qreal x2, qreal y1, qreal y2 ){
    srand (time(NULL));
    return QPointF( (rand() % (int)(x2-x1) + (int)x2 ),(rand() % (int) (y2-y1) + (int)y2));
}

