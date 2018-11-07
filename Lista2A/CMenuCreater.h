#pragma once
#include "CMenu.h"
#include "CMenuCommand.h"
#include <string>

using namespace std;


class CMenuCreater{

private:
    static string cMenuToString(CMenu *cmenu);
    static string cMenuCommandToString(CMenuCommand *cmenuCommand);
    static bool writeToFile(string cmenu);
   // static string readFromFile(string fileName);
    static CMenu* readCMenu(string cmenuToRead);
    static CMenuCommand* readCMenuCommand(string cmenuCommandToRead);
//    static CMenu* createCMenuFromString(string path);
   // static int findPositionOfClosingBracket(string menu);
public:
    static int findPositionOfClosingBracket(string menu);
    static string readFromFile(string fileName);
    static CMenu* createCMenuFromString(string path);
    static bool serialize(CMenu *cmenu);



};
