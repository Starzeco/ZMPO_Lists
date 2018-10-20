#include <iostream>
#include "sstream"
#include <vector>
#include "CCommand.h"
#include "CTableHandler.h"

using namespace std;

class Command7:public CCommand,CTableHandler{

public:
    void RunCommand();
    void printOutObject(int i_index);

};
