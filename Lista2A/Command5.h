#include <iostream>
#include "sstream"
#include <vector>
#include "CCommand.h"
#include "CTableHandler.h"

using namespace std;

class Command5:public CCommand,CTableHandler{

public:
    void RunCommand();
    void changeNameOfChosenElement(int i_index,string s_newName);

};
