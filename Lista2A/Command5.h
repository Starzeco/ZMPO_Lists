#include <iostream>
#include "sstream"
#include <vector>
#include "ListGiver.h"
#include "CTableHandler.h"

using namespace std;

class Command5:public ListGiver{

public:
    Command5(CTableHandler &handler);
    void RunCommand();
    void changeNameOfChosenElement(int i_index,string s_newName);

};
