#pragma once
#include "CMenu.h"
#include "CMenuCommand.h"
#include <string>
#include "MenuSearch.h"

using namespace std;


class CMenuCreater{

private:
    static string cMenuToString(CMenu *cmenu);
    static string cMenuCommandToString(CMenuCommand *cmenuCommand);
    static bool writeToFile(string cmenu);
    static string readFromFile(string fileName);
    static CMenu* readCMenu(string cmenuToRead,MenuSearch &searcher);
    static CMenuCommand* readCMenuCommand(string cmenuCommandToRead);
    static bool validate(string menu);
    static int findPositionOfClosingBracket(string menu);
    static CMenu* createCMenuFromString(string path,MenuSearch &searcher);
    static bool ifIsEqual(char pom);
public:

    static bool serialize(CMenu *cmenu);
    static CMenu* deserialize(MenuSearch &searcher);


};
