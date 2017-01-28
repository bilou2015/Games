#include "Keyboardengine.h"
#include "GraphicalEngine.h"
#include "Kernel.h"
#include "Team.h"
#include "Avatar.h"
#include "Ball.h"
#include "Cage.h"
#include "PhysicalEngine.h"
#include <iostream>

#include <time.h>


KeyBoardEngine::KeyBoardEngine(Kernel *kernel){
    this->m_kernel=kernel;
}

void KeyBoardEngine::TimeEvent(QTimerEvent *){
    if (m_Player[0].Left && m_Player[0].Up){
        this->directionManager(this->m_kernel->getGraphicalEngine()->getScene()->getTeam(1)->getFocusedAvatar(),this->m_kernel->getGraphicalEngine()->getScene()->getBall(),KeyBoardEngine::LeftUp);
        this->m_kernel->getGraphicalEngine()->getScene()->getBall()->setDirectioMove(LeftUp);
    }

    else
        if (m_Player[0].Right && m_Player[0].Up){
            this->directionManager(this->m_kernel->getGraphicalEngine()->getScene()->getTeam(1)->getFocusedAvatar(),this->m_kernel->getGraphicalEngine()->getScene()->getBall(),KeyBoardEngine::RightUp);
            this->m_kernel->getGraphicalEngine()->getScene()->getBall()->setDirectioMove(RightUp);
        }
        else

            if (m_Player[0].Down && m_Player[0].Left) {
                this->directionManager(this->m_kernel->getGraphicalEngine()->getScene()->getTeam(1)->getFocusedAvatar(),this->m_kernel->getGraphicalEngine()->getScene()->getBall(),KeyBoardEngine::LeftDown);
                this->m_kernel->getGraphicalEngine()->getScene()->getBall()->setDirectioMove(LeftDown);
            }
            else

                if (m_Player[0].Down && m_Player[0].Right) {
                    this->directionManager(this->m_kernel->getGraphicalEngine()->getScene()->getTeam(1)->getFocusedAvatar(),this->m_kernel->getGraphicalEngine()->getScene()->getBall(),KeyBoardEngine::RightDown);
                    this->m_kernel->getGraphicalEngine()->getScene()->getBall()->setDirectioMove(RightDown);}
                else
                    if (m_Player[0].Right){
                        this->directionManager(this->m_kernel->getGraphicalEngine()->getScene()->getTeam(1)->getFocusedAvatar(),this->m_kernel->getGraphicalEngine()->getScene()->getBall(),KeyBoardEngine::Right);
                        this->m_kernel->getGraphicalEngine()->getScene()->getBall()->setDirectioMove(Right);
                    }
                    else
                        if (m_Player[0].Left){
                            this->directionManager(this->m_kernel->getGraphicalEngine()->getScene()->getTeam(1)->getFocusedAvatar(),this->m_kernel->getGraphicalEngine()->getScene()->getBall(),KeyBoardEngine::Left);
                            this->m_kernel->getGraphicalEngine()->getScene()->getBall()->setDirectioMove(Left);
                        }
                        else
                            if (m_Player[0].Down){
                                this->directionManager(this->m_kernel->getGraphicalEngine()->getScene()->getTeam(1)->getFocusedAvatar(),this->m_kernel->getGraphicalEngine()->getScene()->getBall(),KeyBoardEngine::Down);
                                this->m_kernel->getGraphicalEngine()->getScene()->getBall()->setDirectioMove(Down);
                            }
                            else
                                if (m_Player[0].Up) {
                                    this->directionManager(this->m_kernel->getGraphicalEngine()->getScene()->getTeam(1)->getFocusedAvatar(),this->m_kernel->getGraphicalEngine()->getScene()->getBall(),KeyBoardEngine::Up);
                                    this->m_kernel->getGraphicalEngine()->getScene()->getBall()->setDirectioMove(Up);
                                }
                                else
                                    if(m_Player[0].Space){
                                        m_Player[0].Space=false;
                                        if (this->m_kernel->getGraphicalEngine()->getScene()->getTeam(1)->getFocusedAvatar()!=this->m_kernel->getGraphicalEngine()->getScene()->getBall()->getOwner())
                                            this->m_kernel->getGraphicalEngine()->getScene()->getTeam(1)->changeFocusedAvatar(this->m_kernel->getGraphicalEngine()->getScene()->getTeam(1)->getFocusedAvatar());
                                    }
                                    else
                                        if(m_Player[0].longPass){
                                            m_Player[0].longPass=false;
                                            this->BallPassManager(this->m_kernel->getGraphicalEngine()->getScene()->getTeam(1)->getFocusedAvatar(),this->m_kernel->getGraphicalEngine()->getScene()->getBall(),false);
                                        }
                                        else
                                            if(m_Player[0].shoot){
                                                m_Player[0].shoot=false;
                                                this->BallShootManager(this->m_kernel->getGraphicalEngine()->getScene()->getTeam(1)->getFocusedAvatar(),this->m_kernel->getGraphicalEngine()->getScene()->getBall());
                                            }
                                            else
                                                if(m_Player[0].pass){
                                                    m_Player[0].pass=false;
                                                    this->BallPassManager(this->m_kernel->getGraphicalEngine()->getScene()->getTeam(1)->getFocusedAvatar(),this->m_kernel->getGraphicalEngine()->getScene()->getBall(),true);
                                                }


    if (m_Player[1].Left && m_Player[1].Up){
        this->directionManager(this->m_kernel->getGraphicalEngine()->getScene()->getTeam(2)->getFocusedAvatar(),this->m_kernel->getGraphicalEngine()->getScene()->getBall(),KeyBoardEngine::LeftUp);
        this->m_kernel->getGraphicalEngine()->getScene()->getBall()->setDirectioMove(LeftUp);

    }

    else
        if (m_Player[1].Right && m_Player[1].Up){
            this->directionManager(this->m_kernel->getGraphicalEngine()->getScene()->getTeam(2)->getFocusedAvatar(),this->m_kernel->getGraphicalEngine()->getScene()->getBall(),KeyBoardEngine::RightUp);
            this->m_kernel->getGraphicalEngine()->getScene()->getBall()->setDirectioMove(RightUp);
        }
        else

            if (m_Player[1].Down && m_Player[1].Left) {

                this->directionManager(this->m_kernel->getGraphicalEngine()->getScene()->getTeam(2)->getFocusedAvatar(),this->m_kernel->getGraphicalEngine()->getScene()->getBall(),KeyBoardEngine::LeftDown);
                this->m_kernel->getGraphicalEngine()->getScene()->getBall()->setDirectioMove(LeftDown);
            }
            else

                if (m_Player[1].Down && m_Player[1].Right) {
                    this->directionManager(this->m_kernel->getGraphicalEngine()->getScene()->getTeam(2)->getFocusedAvatar(),this->m_kernel->getGraphicalEngine()->getScene()->getBall(),KeyBoardEngine::RightDown);
                    this->m_kernel->getGraphicalEngine()->getScene()->getBall()->setDirectioMove(RightDown);
                }
                else
                    if (m_Player[1].Right){
                        this->directionManager(this->m_kernel->getGraphicalEngine()->getScene()->getTeam(2)->getFocusedAvatar(),this->m_kernel->getGraphicalEngine()->getScene()->getBall(),KeyBoardEngine::Right);
                        this->m_kernel->getGraphicalEngine()->getScene()->getBall()->setDirectioMove(Right);
                    }
                    else
                        if (m_Player[1].Left){
                            this->directionManager(this->m_kernel->getGraphicalEngine()->getScene()->getTeam(2)->getFocusedAvatar(),this->m_kernel->getGraphicalEngine()->getScene()->getBall(),KeyBoardEngine::Left);
                            this->m_kernel->getGraphicalEngine()->getScene()->getBall()->setDirectioMove(Left);
                        }
                        else
                            if (m_Player[1].Down){
                                this->directionManager(this->m_kernel->getGraphicalEngine()->getScene()->getTeam(2)->getFocusedAvatar(),this->m_kernel->getGraphicalEngine()->getScene()->getBall(),KeyBoardEngine::Down);
                                this->m_kernel->getGraphicalEngine()->getScene()->getBall()->setDirectioMove(Down);
                            }
                            else
                                if (m_Player[1].Up) {
                                    this->directionManager(this->m_kernel->getGraphicalEngine()->getScene()->getTeam(2)->getFocusedAvatar(),this->m_kernel->getGraphicalEngine()->getScene()->getBall(),KeyBoardEngine::Up);
                                    this->m_kernel->getGraphicalEngine()->getScene()->getBall()->setDirectioMove(Up);
                                }
                                else
                                    if(m_Player[1].Space){
                                        m_Player[1].Space=false;
                                        if (this->m_kernel->getGraphicalEngine()->getScene()->getTeam(2)->getFocusedAvatar()!=this->m_kernel->getGraphicalEngine()->getScene()->getBall()->getOwner())
                                            this->m_kernel->getGraphicalEngine()->getScene()->getTeam(2)->changeFocusedAvatar(this->m_kernel->getGraphicalEngine()->getScene()->getTeam(2)->getFocusedAvatar());
                                    }
                                    else
                                        if(m_Player[1].longPass){
                                            m_Player[1].longPass=false;
                                            this->BallPassManager(this->m_kernel->getGraphicalEngine()->getScene()->getTeam(2)->getFocusedAvatar(),this->m_kernel->getGraphicalEngine()->getScene()->getBall(),false);
                                        }
                                        else
                                            if(m_Player[1].shoot){
                                                m_Player[1].shoot=false;
                                                this->BallShootManager(this->m_kernel->getGraphicalEngine()->getScene()->getTeam(2)->getFocusedAvatar(),this->m_kernel->getGraphicalEngine()->getScene()->getBall());
                                            }
                                            else
                                                if(m_Player[1].pass){
                                                    m_Player[1].pass=false;
                                                    this->BallPassManager(this->m_kernel->getGraphicalEngine()->getScene()->getTeam(2)->getFocusedAvatar(),this->m_kernel->getGraphicalEngine()->getScene()->getBall(),true);
                                                }
}



void KeyBoardEngine::pressEvent(QKeyEvent *event) {
    switch(event->key()) {
    case (Qt::Key_Left):
        m_Player[0].Left = true;
        break;
    case (Qt::Key_Right):
        m_Player[0].Right = true;
        break;
    case (Qt::Key_Up):
        m_Player[0].Up = true;
        break;
    case (Qt::Key_Down):
        m_Player[0].Down = true;
        break;
    case (Qt::Key_2):
        m_Player[0].pass=true;
        break;
    case (Qt::Key_3):
        m_Player[0].shoot=true;
        break;
    case (Qt::Key_1):
        m_Player[0].longPass=true;
        break;
    case (Qt::Key_0):
        m_Player[0].Space=true;
        break;
    case (Qt::Key_J):
        m_Player[1].pass=true;
        break;
    case (Qt::Key_K):
        m_Player[1].shoot=true;
        break;
    case (Qt::Key_H):
        m_Player[1].longPass=true;
        break;
    case (Qt::Key_Q):
        m_Player[1].Left = true;
        break;
    case (Qt::Key_D):
        m_Player[1].Right = true;
        break;
    case (Qt::Key_Z):
        m_Player[1].Up = true;
        break;
    case (Qt::Key_S):
        m_Player[1].Down = true;
        break;
    case (Qt::Key_Space):
        m_Player[1].Space=true;
        break;
    }
    this->m_kernel->getGraphicalEngine()->update();
}


void KeyBoardEngine::releaseEvent(QKeyEvent *event) {
    switch(event->key()) {

    case Qt::Key_Left :
        m_Player[0].Left = false;
        break;
    case  Qt::Key_Right :
        m_Player[0].Right = false;
        break;
    case Qt::Key_Up :
        m_Player[0].Up = false;
        break;
    case Qt::Key_Down :
        m_Player[0].Down = false;
        break;
    case Qt::Key_Q :
        m_Player[1].Left = false;
        break;
    case  Qt::Key_D :
        m_Player[1].Right = false;
        break;
    case Qt::Key_Z :
        m_Player[1].Up = false;
        break;
    case Qt::Key_S :
        m_Player[1].Down = false;
        break;

    default:
        break;
    }

}




void KeyBoardEngine::directionManager(Avatar *avatar,Ball *ball,int direction){
    avatar->setDirection(direction);
    this->m_kernel->getPhysicalEngine()->computeNextPosition(avatar,direction);
    if(this->m_kernel->getPhysicalEngine()->checkCollide(avatar,ball)){
        ball->setOwner(avatar);
        ball->setTaken(1);
        ball->setSpeed(avatar->getSpeed());
        ball->setPosBall(avatar);
        this->m_kernel->getPhysicalEngine()->computeNextPosition(ball,direction);

    }

    if(ball->but()){
        this->GoalManager(ball->getDirectioMove());
    }
    else if(ball->sortieDeBut()){//---Goal kick---
        //---Throw in the corresponding side---
        if(ball->getDirectioMove() == Right){
            this->m_kernel->getGraphicalEngine()->getScene()->getBall()->setPos(1540,515);
        }
        else if(ball->getDirectioMove() == Left){
            this->m_kernel->getGraphicalEngine()->getScene()->getBall()->setPos(130,515);

        }

    }
}






void KeyBoardEngine::BallPassManager(Avatar *avatar,Ball *ball,bool scaled){
    if(ball->getTaken()){
        ball->setTaken(0);
        QPointF destinationBall=avatar->getTeam()->getReceiverOfBall()->pos();
        qreal time=this->m_kernel->getPhysicalEngine()->computeTimeOfMove(avatar,destinationBall);
        this->m_kernel->getPhysicalEngine()->animTranslation(ball,destinationBall,time,scaled);
        ball->setOwner(NULL);
        avatar->getTeam()->changeFocusedAvatar(avatar->getTeam()->getFocusedAvatar());
    }
}

void KeyBoardEngine::BallShootManager(Avatar *avatar,Ball *ball){

    qreal time;
    if (ball->getTaken()){
        if(avatar->getTeam()->getName()=='1'){
            if (ball->getDirectioMove()==Right || ball->getDirectioMove()==Left){
                if(ball->pos().x()<=1300){
                    time=this->m_kernel->getPhysicalEngine()->computeTimeOfMove(avatar,QPointF(ball->pos().x()+400,ball->pos().y()));
                    this->m_kernel->getPhysicalEngine()->animTranslation(ball,QPointF(ball->pos().x()+400,ball->pos().y()),time,true);
                    ball->setTaken(0);
                }else {
                    QPointF randPos=this->m_kernel->getPhysicalEngine()->randomPoint(1585,1620,500,550);
                    time=this->m_kernel->getPhysicalEngine()->computeTimeOfMove(avatar,randPos);
                    this->m_kernel->getPhysicalEngine()->animTranslation(ball,randPos,time,true);
                    ball->setTaken(0);

                }
            } else
                if (ball->getDirectioMove()==RightUp || ball->getDirectioMove()==LeftUp || ball->getDirectioMove()==RightDown || ball->getDirectioMove()==LeftDown){
                    if(ball->pos().x()<=1300){
                        time=this->m_kernel->getPhysicalEngine()->computeTimeOfMove(avatar,QPointF(ball->pos().x()+400,ball->pos().y()+400));
                        this->m_kernel->getPhysicalEngine()->animTranslation(ball,QPointF(ball->pos().x()+400,ball->pos().y()),time,true);
                        ball->setTaken(0);
                    }else {
                        QPointF randPos=this->m_kernel->getPhysicalEngine()->randomPoint(1585,1620,500,550);
                        time=this->m_kernel->getPhysicalEngine()->computeTimeOfMove(avatar,randPos);
                        this->m_kernel->getPhysicalEngine()->animTranslation(ball,randPos,time,true);
                        ball->setTaken(0);

                    }
                }
        }else
            if(avatar->getTeam()->getName()=='2'){
                if (ball->getDirectioMove()==Right || ball->getDirectioMove()==Left){
                    if(ball->pos().x()>=300){
                        time=this->m_kernel->getPhysicalEngine()->computeTimeOfMove(avatar,QPointF(ball->pos().x()-400,ball->pos().y()));
                        this->m_kernel->getPhysicalEngine()->animTranslation(ball,QPointF(ball->pos().x()-400,ball->pos().y()),time,true);
                        ball->setTaken(0);
                    }else {
                        QPointF randPos=this->m_kernel->getPhysicalEngine()->randomPoint(20,40,500,550);
                        time=this->m_kernel->getPhysicalEngine()->computeTimeOfMove(avatar,randPos);
                        this->m_kernel->getPhysicalEngine()->animTranslation(ball,randPos,time,true);
                        ball->setTaken(0);

                    }
                } else
                    if (ball->getDirectioMove()==RightUp || ball->getDirectioMove()==LeftUp ){
                        if(ball->pos().x()>=300){
                            time=this->m_kernel->getPhysicalEngine()->computeTimeOfMove(avatar,QPointF(ball->pos().x()-400,ball->pos().y()-400));
                            this->m_kernel->getPhysicalEngine()->animTranslation(ball,QPointF(ball->pos().x()-400,ball->pos().y()-400),time,true);
                            ball->setTaken(0);
                        }else {
                            QPointF randPos=this->m_kernel->getPhysicalEngine()->randomPoint(20,40,500,550);
                            time=this->m_kernel->getPhysicalEngine()->computeTimeOfMove(avatar,randPos);
                            this->m_kernel->getPhysicalEngine()->animTranslation(ball,randPos,time,true);
                            ball->setTaken(0);

                        }
                    }
                    else if(ball->getDirectioMove()==RightDown || ball->getDirectioMove()==LeftDown){
                        if(ball->pos().x()>=300){
                            time=this->m_kernel->getPhysicalEngine()->computeTimeOfMove(avatar,QPointF(ball->pos().x()-400,ball->pos().y()+400));
                            this->m_kernel->getPhysicalEngine()->animTranslation(ball,QPointF(ball->pos().x()-400,ball->pos().y()+400),time,true);
                            ball->setTaken(0);
                        }else {
                            QPointF randPos=this->m_kernel->getPhysicalEngine()->randomPoint(20,40,500,550);
                            time=this->m_kernel->getPhysicalEngine()->computeTimeOfMove(avatar,randPos);
                            this->m_kernel->getPhysicalEngine()->animTranslation(ball,randPos,time,true);
                            ball->setTaken(0);

                        }

                    }
            }
    }


    ball->setOwner(NULL);
    ball->setDirectioMove(ball->getDirectioMove());

    if(ball->but())
    {
        this->GoalManager(ball->getDirectioMove());
    }
    else if(ball->sortieDeBut()){//---Goal kick---
        //---Throw in the corresponding side---
        if(ball->getDirectioMove() == Right){
            this->m_kernel->getGraphicalEngine()->getScene()->getBall()->setPos(1540,515);
        }else if(ball->getDirectioMove() == Left){
            this->m_kernel->getGraphicalEngine()->getScene()->getBall()->setPos(130,515);
        }
    }


}

void KeyBoardEngine::GoalManager(int direction){
    //-----------------------------CODE TEST POUR LA GESTION DU BUT---------------------------------------//

    if(direction == Right || direction== RightUp || direction==RightDown)
    {
        //---Changing the score in a goal from the right cage---
        this->m_kernel->getGraphicalEngine()->getScene()->getLcdG()->display(this->m_kernel->getGraphicalEngine()->getScene()->getLcdG()->setButTeam1());
        //---Repositionning of the avatars in the center to give the kick-off---
        this->m_kernel->getGraphicalEngine()->getScene()->getTeam(2)->getStriker()->setPos(830,480);
        this->m_kernel->getGraphicalEngine()->getScene()->getTeam(2)->getStriker()->setDirection(KeyBoardEngine::Down);

        this->m_kernel->getGraphicalEngine()->getScene()->getTeam(2)->getDefender()->setPos(830,530);
        this->m_kernel->getGraphicalEngine()->getScene()->getTeam(2)->getDefender()->setDirection(KeyBoardEngine::Up);
        //---Repositionning avatars in their camps---
        this->m_kernel->getGraphicalEngine()->getScene()->getTeam(1)->getStriker()->setPos(600,507);
        this->m_kernel->getGraphicalEngine()->getScene()->getTeam(1)->getStriker()->setDirection(KeyBoardEngine::Right);
        this->m_kernel->getGraphicalEngine()->getScene()->getTeam(1)->getDefender()->setPos(500,507);
        this->m_kernel->getGraphicalEngine()->getScene()->getTeam(1)->getDefender()->setDirection(KeyBoardEngine::Right);

    }else if (direction == Left){

        //---Changing the score in a goal from the left cage---
        this->m_kernel->getGraphicalEngine()->getScene()->getLcdD()->display(this->m_kernel->getGraphicalEngine()->getScene()->getLcdD()->setButTeam2());
        //---Repositionning of the avatars in the center to give the kick-off---
        this->m_kernel->getGraphicalEngine()->getScene()->getTeam(1)->getStriker()->setPos(825,480);
        this->m_kernel->getGraphicalEngine()->getScene()->getTeam(1)->getStriker()->setDirection(KeyBoardEngine::Down);

        this->m_kernel->getGraphicalEngine()->getScene()->getTeam(1)->getDefender()->setPos(825,530);
        this->m_kernel->getGraphicalEngine()->getScene()->getTeam(1)->getDefender()->setDirection(KeyBoardEngine::Up);

        //---Repositionning avatars in their camps---
        this->m_kernel->getGraphicalEngine()->getScene()->getTeam(2)->getStriker()->setPos(900,507);
        this->m_kernel->getGraphicalEngine()->getScene()->getTeam(2)->getStriker()->setDirection(KeyBoardEngine::Left);

        this->m_kernel->getGraphicalEngine()->getScene()->getTeam(2)->getDefender()->setPos(1200,507);
        this->m_kernel->getGraphicalEngine()->getScene()->getTeam(2)->getDefender()->setDirection(KeyBoardEngine::Left);

    }
    //---Repositionning the ball in the centre--
    this->m_kernel->getGraphicalEngine()->getScene()->getBall()->setPos(834,520);

    this->m_kernel->getGraphicalEngine()->repaint();
}




