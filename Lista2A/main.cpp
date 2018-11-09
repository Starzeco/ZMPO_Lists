#include <iostream>
#include "CMenu.h"
#include "Initialize.h"
#include "CMenuCreater.h"
using namespace std;

int main()
{
/*

    CMenu *menu;
    CTableHandler *handler=new CTableHandler();
    MenuSearch *searcher=new MenuSearch();
    menu=Initializer::initialize(*handler,*searcher);

    //cout<<CMenuCreater::cMenuToString(menu)<<endl;
   //CMenuCreater::serialize(menu);
   // cout<<CMenuCreater::readFromFile("hej.txt")<<endl;
    menu->run();

    delete menu;
    delete handler;
    delete searcher;

    /*CMenu menu("Menu Glowne","xxxxx");
    menu.initializeCMenu();
    menu.run();
    */
    MenuSearch *searcher=new MenuSearch();
    CMenu *menu=CMenuCreater::deserialize(*searcher);

    menu->run();

    delete menu;
    delete searcher;
    //string p=CMenuCreater::readFromFile("hej.txt");

    //CMenu *menu=CMenuCreater::createCMenuFromString(p);
    //CMenu *menu=CMenuCreater::createCMenuFromString("(*name*,*komenda*;(*name2*,*komenda2*;[*name2a*,*komenda2a*,*helpo*]),(*name3*,*kom3*;[*namname*,*kom3*,*hlp3*]))");
    //menu->run();

    return 0;
}
