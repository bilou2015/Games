#include "Application.h"
#include "Kernel.h"

Application::Application(int argc, char * argv[]): QApplication(argc, argv){
//create a kernel and run it
    m_kernel=new Kernel();
    m_kernel->run();

}
int main(int argc, char **argv){
    Application a(argc,argv);

    return a.exec();
}
