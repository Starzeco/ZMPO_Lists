#include <iostream>
#include "sstream"
#include <vector>
#include "CCommand.h"
#include "CTableHandler.h"

using namespace std;

class Command8:public CCommand,CTableHandler{

public:
    void RunCommand();
    void changeElementInCTable(int i_index,int i_indexC,int i_newValue);

};
