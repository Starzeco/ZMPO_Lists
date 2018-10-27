#include <iostream>
#include "sstream"
#include <vector>
#include "ListGiver.h"
#include "CTableHandler.h"

using namespace std;

class Command2:public ListGiver{

public:
    Command2(CTableHandler &handler);
    void RunCommand();
    void changeLengthForChosenObject(int i_index,int i_newSize);

};
