#ifndef LCDSCREEN_H
#define LCDSCREEN_H

#include <QLCDNumber>
#include <QTimer>
#include <QTime>
class LCDScreen: public QLCDNumber
{
    Q_OBJECT

public:
    LCDScreen();


public slots:
    void setDuration();
private:
    QTimer *timer;
    int duration;
};
#endif // LCDSCREEN_H
