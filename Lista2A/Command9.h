#include <iostream>
#include "sstream"
#include <vector>
#include "ListGiver.h"
#include "CTableHandler.h"

using namespace std;

class Command9:public ListGiver{

public:
    Command9(CTableHandler &handler);
    void RunCommand();
    void copyObjectAndChangeSize(int i_index,int i_newLength);


};
