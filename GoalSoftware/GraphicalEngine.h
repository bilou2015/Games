#ifndef GRAPHICALENGINE_H
#define GRAPHICALENGINE_H
#include <QGraphicsView>
#include "Engine.h"
#include "Kernel.h"
#include <QKeyEvent>

class Scene;
class GraphicalEngine : public Engine, public QGraphicsView
{
public:
    GraphicalEngine(Kernel *kernel);
    Kernel *getKernel();
    Scene * getScene();
    void setEngineScene(Scene * scene);
    virtual void keyPressEvent(QKeyEvent *event);
    virtual void keyReleaseEvent(QKeyEvent *event);
    void timerEvent(QTimerEvent *event);
private:

        Scene *m_scene;
     Kernel * m_kernel;
};

#endif // GRAPHICALENGINE_H
