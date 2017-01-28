#ifndef LCDSCORE_H
#define LCDSCORE_H
#include <QLCDNumber>

class LCDScore : public QLCDNumber
{
public:
    LCDScore();
    int setButTeam1();
    int setButTeam2();
private:
   int m_ButTeam1;
   int m_ButTeam2;
};

#endif // LCDSCORE_H
