
#include <iostream>
#include "sstream"
#include <vector>
#include "ListGiver.h"
#include "CTableHandler.h"

using namespace std;

class Command1:public ListGiver{

public:
    Command1(CTableHandler &handler);
    void RunCommand();
    void createCTableObjectsDeafult(int i_number);
    void createCTableObjects(int i_number,string s_nazwa,int i_length);


};
