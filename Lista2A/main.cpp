#include <iostream>
#include "CMenu.h"
#include "Initialize.h"
using namespace std;

int main()
{
    //cout << "Hello world!" << endl;
    CMenu *menu;
    CTableHandler *handler=new CTableHandler();
    MenuSearch *searcher=new MenuSearch();
    menu=Initializer::initialize(*handler,*searcher);

    menu->run();
    delete menu;
    delete handler;


    /*CMenu menu("Menu Glowne","xxxxx");
    menu.initializeCMenu();
    menu.run();
    */




    return 0;
}
