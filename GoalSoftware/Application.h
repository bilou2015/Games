#ifndef APPLICATION_H
#define APPLICATION_H
#include <QApplication>

class Kernel;
class Application : public QApplication
{
private:
    Kernel *m_kernel;
public:
    Application(int argc, char **argv);
    int  main();
};

#endif // APPLICATION_H
