#include "GraphicalEngine.h"
#include "Scene.h"
#include "Keyboardengine.h"
#include "QDebug"

GraphicalEngine::GraphicalEngine(Kernel *kernel)
{

    this->m_kernel=kernel;
    m_scene=new Scene();
    this->setScene(m_scene);
    this->setFocusPolicy(Qt::StrongFocus);
    this->scale(0.8,0.71);
    startTimer(32);

}

Scene * GraphicalEngine::getScene(){
    return this->m_scene;
}

void GraphicalEngine::setEngineScene(Scene * scene){
    this->m_scene=scene;
}

void GraphicalEngine::timerEvent(QTimerEvent * event){
    this->m_kernel->getKeyBoardEngine()->TimeEvent(event);
}


void GraphicalEngine::keyPressEvent(QKeyEvent *event){
 this->m_kernel->getKeyBoardEngine()->pressEvent(event);
}

void GraphicalEngine::keyReleaseEvent(QKeyEvent *event){
 this->m_kernel->getKeyBoardEngine()->releaseEvent(event);
}



