#include <iostream>
#include "sstream"
#include <vector>
#include "CCommand.h"
#include "CTableHandler.h"

using namespace std;

class Command3:public CCommand,CTableHandler{

public:
    void RunCommand();
    void deleteChosenObject(int i_index);


};
