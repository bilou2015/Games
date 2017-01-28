#ifndef SCENE_H
#define SCENE_H
#include <QGraphicsScene>
#include "LCDScore.h"
#include "LCDScreen.h"

class Team;
class Field;
class Ball;
class Cage;
class Scene : public QGraphicsScene
{
public:
    Scene();

    Team *getTeam(int i);
    Field * getField();
    Ball *getBall();
    LCDScore * getLcdD();
    LCDScore * getLcdG();

private:
    Team * m_team[2];
    Field * m_field;
    Ball  * m_ball;
    Cage * m_cageD;
    Cage * m_cageG;
    LCDScore *m_lcdD;
    LCDScore *m_lcdG;
    LCDScreen *timeDisplayer;

};

#endif // SCENE_H
