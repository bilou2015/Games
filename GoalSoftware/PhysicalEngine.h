#ifndef PHYSICALENGINE_H
#define PHYSICALENGINE_H
#include "Engine.h"
#include "Kernel.h"
#include <QPropertyAnimation>
class Ball;
class Avatar;
class Entity;
class PhysicalEngine : public Engine
{
public:
    Kernel * m_kernel;
    PhysicalEngine(Kernel *kernel);

    void computeNextPosition(Entity * entity,int direction);
    void moveBall(Ball * ball, float xMovement, float yMovement);
    bool checkCollide(Entity *entity1,Entity *entity2);
    qreal getDistance(QPointF const& x1,QPointF const& x2);
    qreal computeTimeOfMove(Entity *entity, QPointF const& end);
    void animTranslation(Entity *entity, const QPointF &end, const qreal &time, bool scaled);
    void scale(Entity *entity,qreal const& time);
    QPointF randomPoint(qreal x1, qreal x2, qreal y1, qreal y2 );
    enum Direction {Right,Left,Up,Down,RightUp,LeftUp,LeftDown,RightDown};
};

#endif // PHYSICALENGINE_H
