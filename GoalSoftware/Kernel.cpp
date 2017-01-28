#include "Kernel.h"
#include "GraphicalEngine.h"
#include "PhysicalEngine.h"
#include "Keyboardengine.h"
#include "Avatar.h"
#include "Team.h"


Kernel::Kernel()
{
    m_graphicalEngine=new GraphicalEngine(this);
    m_physicalEngine=new PhysicalEngine(this);
    m_keyBoardEngine=new KeyBoardEngine(this);
}

void Kernel::updateGraphics(){

}

GraphicalEngine * Kernel::getGraphicalEngine(){
    return this->m_graphicalEngine;
}

PhysicalEngine * Kernel::getPhysicalEngine(){
    return this->m_physicalEngine;
}

KeyBoardEngine * Kernel::getKeyBoardEngine(){
    return this->m_keyBoardEngine;
}

void Kernel::run(){
    this->m_graphicalEngine->showFullScreen();

}
