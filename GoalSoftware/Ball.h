#ifndef BALL_H
#define BALL_H
#include "Entity.h"
#include <QPixmap>

class Avatar;
class Ball : public Entity
{
public:
    Ball();

    int getTaken();
    void setTaken(int taken);

    Avatar *getOwner();
    void setOwner(Avatar *owner);

    QPixmap getPixMap();
    void setPixMap(QPixmap pixBall);
    void setPosBall(Avatar * avatar);
    void initialise();
    void setDirectioMove(int direction);
    int getDirectioMove();
    bool but();
    bool sortieDeBut();

private:
    int m_taken;
    int m_direction;
    Avatar * m_owner;
    QPixmap m_pixBall;
};

#endif // BALL_H
