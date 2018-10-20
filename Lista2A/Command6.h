#include <iostream>
#include "sstream"
#include <vector>
#include "CCommand.h"
#include "CTableHandler.h"

using namespace std;

class Command6:public CCommand,CTableHandler{

public:
    void RunCommand();
    void copyObjectAndAddIt(int i_index);

};
