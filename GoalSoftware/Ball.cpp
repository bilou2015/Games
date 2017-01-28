#include "Ball.h"
#include "Avatar.h"

Ball::Ball()
{
    this->setPix(QPixmap(":/Other/ball_41.png"));
    this->setPos(834,520);
    this->setSpeed(5.0);
    this->setFlag(GraphicsItemFlag::ItemIsMovable);

}

int Ball::getTaken(){
    return this->m_taken;
}

void Ball::setTaken(int taken){
    this->m_taken=taken;
}

Avatar *Ball::getOwner(){
    return this->m_owner;
}

void Ball::setOwner(Avatar *owner){
    this->m_owner=owner;

}

//set a ball position front of avatar when collide

void Ball::setPosBall(Avatar *avatar){
    switch(avatar->getDirection()){
    case KeyBoardEngine::Right :
        this->setPos(avatar->x()+20,avatar->y()+13);
        break;
    case KeyBoardEngine::Left :
        this->setPos(avatar->x()+7,avatar->y()+13);
        break;
    case KeyBoardEngine::Up :
        this->setPos(avatar->x()+15,avatar->y()+8);
        break;
    case  KeyBoardEngine::Down :
        this->setPos(avatar->x()+15,avatar->y()+20);
        break;
    case KeyBoardEngine::RightUp :
        this->setPos(avatar->x()+18,avatar->y()+13);
        break;
    case KeyBoardEngine::LeftUp :
        this->setPos(avatar->x()+10,avatar->y()+10);
        break;
    case KeyBoardEngine::LeftDown :
        this->setPos(avatar->x()+10,avatar->y()+15);
        break;
    case  KeyBoardEngine::RightDown :
        this->setPos(avatar->x()+18,avatar->y()+15);
        break;

    }
}

//initialize the position of the ball when a goal is scored

void Ball::initialise(){
    this->setPos(834,520);
}


//stock a direction of ball when we move it

void Ball::setDirectioMove(int direction){
    this->m_direction=direction;
}

//retrieve a direction of ball when we move it

int Ball::getDirectioMove(){
    return this->m_direction;
}


//---Method that reports a goal---
bool Ball::but(){
    //---Goal in the right cage---
    if(this->x() > 1585)
    {
        if(this->y() < 586 && this->y() > 454)
        {
            return true;
        }
    }
    //---Goal in the left cage---

    if(this->x() < 85)
    {
        if(this->y() < 586 && this->y() > 454)
        {
            return true;
        }
    }
    return false;

}

//---Method that reports if the ball is offside or not---
bool Ball:: sortieDeBut(){

    //---Goal output ligne of the right side---
    if(this->x() > 1585)
    {
        if(this->y() > 586 || this->y() < 454)
        {
            return true;
        }
    }
    //---Goal output ligne of the left side---
    if(this->x() < 85)
    {
        if(this->y() > 586 || this->y() < 454)
        {
            return true;
        }
    }
    return false;

}
