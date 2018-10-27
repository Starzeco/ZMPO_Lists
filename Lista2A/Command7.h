#include <iostream>
#include "sstream"
#include <vector>
#include "ListGiver.h"
#include "CTableHandler.h"

using namespace std;

class Command7:public ListGiver{

public:
    Command7(CTableHandler &handler);
    void RunCommand();
    void printOutObject(int i_index);

};
