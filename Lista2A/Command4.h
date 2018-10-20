#include <iostream>
#include "sstream"
#include <vector>
#include "CCommand.h"
#include "CTableHandler.h"

using namespace std;

class Command4:public CCommand,CTableHandler{

public:
    void RunCommand();
    void deleteAllElements();

};
