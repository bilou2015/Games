#ifndef KERNEL_H
#define KERNEL_H

class KeyBoardEngine;
class GraphicalEngine;
class PhysicalEngine;
class Kernel
{
public:
    Kernel();

    void updateGraphics();

    GraphicalEngine *getGraphicalEngine();
    PhysicalEngine *getPhysicalEngine();
    KeyBoardEngine *getKeyBoardEngine();
    void run();

private:
    GraphicalEngine * m_graphicalEngine;
    PhysicalEngine * m_physicalEngine;
    KeyBoardEngine * m_keyBoardEngine;

};

#endif // KERNEL_H
