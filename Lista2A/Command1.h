
#include <iostream>
#include "sstream"
#include <vector>
#include "CCommand.h"
#include "CTableHandler.h"

using namespace std;

class Command1:public CCommand,CTableHandler{

public:
    void RunCommand();
    void createCTableObjectsDeafult(int i_number);
    void createCTableObjects(int i_number,string s_nazwa,int i_length);


};
