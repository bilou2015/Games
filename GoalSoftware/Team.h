#ifndef TEAM_H
#define TEAM_H
#include "Entity.h"
#include <QPixmap>

class Avatar;
class Cage;
class Team
{
public:   
    Team(int i);
    QPixmap *getPixMap(int i);
    Avatar *getDefender();
    Avatar *getStriker();
    Avatar *getGoalKeeper();
    Avatar *getFocusedAvatar();
    void setFocusedAvatar(Avatar *avatar);
    void changeFocusedAvatar(Avatar * focusedAvatar);
    void setConterCag(Cage *cage);
    Cage * getConterCag();
    int getNbGoal();
    void setNbGoal(int nbGoal);
    void initialiseTeam(int i);
    Avatar* getReceiverOfBall();
    char getName();
    void setName(char name);


private:
    int m_nbGoal;
    Cage *m_ConterCage;
    QPixmap *m_tabPixAvatar[8];
    Avatar *m_defender;
    Avatar *m_striker;
    Avatar *m_goalKeeper;
    Avatar *m_focusedAvatar;
    QString m_team[3];
    char m_name;
};

#endif // TEAM_H
