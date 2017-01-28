#include "LCDScore.h"

LCDScore::LCDScore()
{
    this->m_ButTeam1 = 0;
    this->m_ButTeam2 = 0;
}


//---Method that increments goals for team1---
int LCDScore::setButTeam1()
{
    return this->m_ButTeam1 = this->m_ButTeam1 +1;
}

//---Method that increments goals for team2---
int LCDScore::setButTeam2()
{
    return this->m_ButTeam2 = this->m_ButTeam2 +1;
}
