#include <iostream>
#include "sstream"
#include <vector>
#include "CCommand.h"
#include "CTableHandler.h"

using namespace std;

class Command2:public CCommand,CTableHandler{

public:
    void RunCommand();
    void changeLengthForChosenObject(int i_index,int i_newSize);

};
