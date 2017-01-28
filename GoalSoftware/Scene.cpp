#include "Scene.h"
#include "Field.h"
#include "Team.h"
#include "Avatar.h"
#include "Ball.h"
#include "Cage.h"

Scene::Scene()
{
    //---field creation
    this->m_field = new Field();
    this->setSceneRect(this->m_field->getPix().rect());
    this->setBackgroundBrush(this->m_field->getPix());

    //--- cage creation---
    this->m_cageD = new Cage();
    QPixmap cageD = QPixmap(":/Cage/RightCage.png");
    this->m_cageD->setPix(cageD);
    this->m_cageD->setPos(1585, 455);
    this->addItem(this->m_cageD);

    this->m_cageG = new Cage();
    QPixmap cageG = QPixmap(":/Cage/LeftCage.png");
    this->m_cageG->setPix(cageG);
    this->m_cageG->setPos(60, 455);
    this->addItem(this->m_cageG);

    //--Ball creation
    this->m_ball=new Ball();
    this->addItem(this->m_ball);

    //--First team creation
    this->m_team[1] = new Team(1);
    this->addItem(this->m_team[1]->getDefender());
    this->addItem(this->m_team[1]->getGoalKeeper());
    this->addItem(this->m_team[1]->getStriker());

    //--Seconde team creation
    this->m_team[2] = new Team(2);
    this->addItem(this->m_team[2]->getDefender());
    this->addItem(this->m_team[2]->getGoalKeeper());
    this->addItem(this->m_team[2]->getStriker());

    // panneanux d'affichage des scores
    this->m_lcdD = new LCDScore();
    this->m_lcdG = new LCDScore();
    this->m_lcdG->setGeometry(700,0,70,50);
    this->m_lcdD->setGeometry(900,0,70,50);
    this->m_lcdD->setSegmentStyle(QLCDNumber::Flat);
    this->m_lcdG->setSegmentStyle(QLCDNumber::Flat);
    this->addWidget(this->m_lcdD);
    this->addWidget(this->m_lcdG);

    //panneau d'affichage du temps
    timeDisplayer = new LCDScreen();
    timeDisplayer->setSegmentStyle(QLCDNumber::Flat);
    timeDisplayer->setGeometry(800,0,70,50);
    this->addWidget(timeDisplayer);


}


Team * Scene::getTeam(int i){
    return this->m_team[i];
}

Field * Scene::getField(){
    return this->m_field;
}

Ball * Scene::getBall(){
    return this->m_ball;
}

LCDScore * Scene::getLcdD()
{
    return this->m_lcdD;
}

LCDScore * Scene::getLcdG()
{
    return this->m_lcdG;
}
