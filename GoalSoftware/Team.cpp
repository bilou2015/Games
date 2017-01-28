#include "Team.h"
#include "Avatar.h"
#include "Keyboardengine.h"
#include "Cage.h"

Team::Team(int i)
{

    if (i==1){
        this->m_team[i]=":/Team1pix";
        m_name='1';

        // avatar image right
        this->m_tabPixAvatar[0] = new QPixmap(this->m_team[i]+"/kit 90.png");
        // avatar image left
        this->m_tabPixAvatar[1] = new QPixmap(this->m_team[i]+"/kit 270.png");
        // avatar image up
        this->m_tabPixAvatar[2] = new QPixmap(this->m_team[i]+"/kit 0.png");
        // avatar image down
        this->m_tabPixAvatar[3] = new QPixmap(this->m_team[i]+"/kit 180.png");
        //Diagonal Right Up
        this->m_tabPixAvatar[4] = new QPixmap(this->m_team[i]+"/kit 60.png");
        // Diagonal Left Up
        this->m_tabPixAvatar[5] = new QPixmap(this->m_team[i]+"/kit 300.png");
        // Diagonal Left Down
        this->m_tabPixAvatar[6] = new QPixmap(this->m_team[i]+"/kit 240.png");
        // Diagonal Right down
        this->m_tabPixAvatar[7] = new QPixmap(this->m_team[i]+"/kit 120.png");

        this->m_goalKeeper = new Avatar(*this->m_tabPixAvatar[0]);
        this->m_goalKeeper->setTeam(this);
        this->m_goalKeeper->setPos(90,507);
        this->m_goalKeeper->setSpeed(5.0);
        this->m_goalKeeper->setDirection(KeyBoardEngine::Right);


        this->m_defender = new Avatar(*this->m_tabPixAvatar[0]);
        this->m_defender->setTeam(this);
        this->m_defender->setPos(500,507);
        this->m_defender->setSpeed(6);
        this->m_defender->setDirection(KeyBoardEngine::Right);



        this->m_striker = new Avatar(*this->m_tabPixAvatar[0]);
        this->m_striker->setTeam(this);
        this->m_striker->setPos(800,507);
        this->m_striker->setDirection(KeyBoardEngine::Right);
        this->m_focusedAvatar=this->m_striker;
        this->m_striker->setSpeed(6);
    }
    else{
        this->m_team[i]=":/Team2pix";
        m_name='2';

        // avatar image right
        this->m_tabPixAvatar[0] = new QPixmap(this->m_team[i]+"/kit 90.png");
        // avatar image left
        this->m_tabPixAvatar[1] = new QPixmap(this->m_team[i]+"/kit 270.png");
        // avatar image up
        this->m_tabPixAvatar[2] = new QPixmap(this->m_team[i]+"/kit 0.png");
        // avatar image down
        this->m_tabPixAvatar[3] = new QPixmap(this->m_team[i]+"/kit 180.png");
        //Diagonal Right Up
        this->m_tabPixAvatar[4] = new QPixmap(this->m_team[i]+"/kit 60.png");
        // Diagonal Left Up
        this->m_tabPixAvatar[5] = new QPixmap(this->m_team[i]+"/kit 300.png");
        // Diagonal Left Down
        this->m_tabPixAvatar[6] = new QPixmap(this->m_team[i]+"/kit 240.png");
        // Diagonal Right down
        this->m_tabPixAvatar[7] = new QPixmap(this->m_team[i]+"/kit 120.png");

        this->m_goalKeeper = new Avatar(*this->m_tabPixAvatar[1]);
        this->m_goalKeeper->setTeam(this);
        this->m_goalKeeper->setPos(1550,507);
        this->m_goalKeeper->setSpeed(5);
        this->m_goalKeeper->setDirection(KeyBoardEngine::Left);


        this->m_defender = new Avatar(*this->m_tabPixAvatar[1]);
        this->m_defender->setTeam(this);
        this->m_defender->setPos(1200,507);
        this->m_defender->setSpeed(6);
        this->m_defender->setDirection(KeyBoardEngine::Left);

        this->m_striker = new Avatar(*this->m_tabPixAvatar[1]);
        this->m_striker->setTeam(this);
        this->m_striker->setPos(1000,507);
        this->m_striker->setSpeed(6);

        this->m_focusedAvatar=this->m_striker;
        this->m_striker->setDirection(KeyBoardEngine::Left);
    }
this->m_nbGoal=0;

}


QPixmap *Team::getPixMap(int i)
{
    return this->m_tabPixAvatar[i];
}

Avatar * Team::getDefender(){
    return this->m_defender;
}

Avatar *Team::getStriker(){
    return this->m_striker;
}

Avatar *Team::getGoalKeeper(){
    return this->m_goalKeeper;
}

Avatar *Team::getFocusedAvatar(){
    return this->m_focusedAvatar;
}

void Team::setFocusedAvatar(Avatar *avatar)
{
    this->m_focusedAvatar = avatar;

}

void Team::changeFocusedAvatar(Avatar * focusedAvatar){
    if(focusedAvatar==this->m_defender){
        this->m_focusedAvatar=this->m_striker;
    }
    else
        this->m_focusedAvatar=this->m_defender;
}

int Team::getNbGoal(){
return this->m_nbGoal;
}

void Team::setNbGoal(int nbGoal){
this->m_nbGoal=nbGoal;
}

Avatar* Team::getReceiverOfBall(){
if(this->getFocusedAvatar()==this->m_defender){
    return this->m_striker;
}
else
    return this->m_defender;
}

char Team::getName(){
    return m_name;
}

void Team::setName(char name){
    this->m_name=name;
}
