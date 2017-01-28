#include "Avatar.h"
#include "Team.h"
#include "Ball.h"

Avatar::Avatar(const QPixmap &pixAvatar){
    this->setPix(pixAvatar);
}

//recover a direction of avatar

char Avatar::getDirection(){
    return this->m_direction;
}

// change a direction of avatar

void Avatar::setDirection(int direction){
    switch(direction){
    case KeyBoardEngine::Right:this->setPix(*this->getTeam()->getPixMap(0));
        break;
    case KeyBoardEngine::Left:this->setPix(*this->getTeam()->getPixMap(1));
        break;
    case KeyBoardEngine::Up:this->setPix(*this->getTeam()->getPixMap(2));
        break;
    case KeyBoardEngine::Down:this->setPix(*this->getTeam()->getPixMap(3));
        break;
    case KeyBoardEngine::RightUp :this->setPix(*this->getTeam()->getPixMap(4));
        break;
    case KeyBoardEngine::LeftUp:this->setPix(*this->getTeam()->getPixMap(5));
        break;
    case KeyBoardEngine::LeftDown:this->setPix(*this->getTeam()->getPixMap(6));
        break;
    case KeyBoardEngine::RightDown:this->setPix(*this->getTeam()->getPixMap(7));
        break;
    }

    this->m_direction=direction;
}

//retrieve a team of avatar

Team * Avatar::getTeam(){
    return this->m_team;
}

//set team of avatar

void Avatar::setTeam(Team *team){
    this->m_team=team;
}

