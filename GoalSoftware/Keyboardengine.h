#ifndef KEYBOARDENGINE_H
#define KEYBOARDENGINE_H
#include <QKeyEvent>


class Avatar;
class Ball;
typedef struct  playerKeyPress playerKeyPress;
struct playerKeyPress{
    bool Left;
    bool Right;
    bool Up;
    bool Down;
    bool Space;
    bool pass;
    bool longPass;
    bool shoot;
    playerKeyPress(){
        Left=false;
        Right=false;
        Up=false;
        Down=false;
        Space=false;
        pass=false;
        longPass=false;
        shoot=false;
    }
};



class Kernel;
class GraphicalEngine;
class Team;
class KeyBoardEngine
{
private:
    playerKeyPress m_Player[2];

    Kernel * m_kernel;
public:
    enum Direction {Right,Left,Up,Down,RightUp,LeftUp,LeftDown,RightDown};
    KeyBoardEngine(Kernel *kernel);
    void TimeEvent(QTimerEvent *);
    void pressEvent(QKeyEvent *event);
    void releaseEvent(QKeyEvent *event);
    void keyEventManager();
    void directionManager(Avatar *avatar, Ball *ball, int direction);  
    void BallPassManager(Avatar *avatar,Ball *ball,bool scaled);
    void BallShootManager(Avatar *avatar, Ball *ball);
    void GoalManager(int direction);
};

#endif // KEYBOARDENGINE_H
