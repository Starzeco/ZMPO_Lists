#include <iostream>
#include "sstream"
#include <vector>
#include "CCommand.h"
#include "CTableHandler.h"

using namespace std;

class Command9:public CCommand,CTableHandler{

public:
    void RunCommand();
    void copyObjectAndChangeSize(int i_index,int i_newLength);


};
