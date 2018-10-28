#pragma once
#include "CMenu.h"



using namespace std;
class CMenu;

class MenuSearch{


private:
   CMenu *cmenu;

public:
    void searchForPath(CMenu *menu,string &commandName,string path);
    void setCMenu(CMenu &cmenuGiven);




};

