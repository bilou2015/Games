#ifndef AVATAR_H
#define AVATAR_H
#include "Entity.h"

class Team;
class Avatar: public Entity
{
public:

    Avatar(QPixmap const&  pixAvatar);    
    //void sPass();
    void sShoot();
    void sSpeed();
    Team *getTeam();
    void setTeam(Team *team);
    void setDirection(int direction);
    char getDirection();


private:
    Team * m_team;
    int m_direction;
};

#endif // AVATAR_H
