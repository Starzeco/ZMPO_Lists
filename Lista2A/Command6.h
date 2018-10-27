#include <iostream>
#include "sstream"
#include <vector>
#include "ListGiver.h"
#include "CTableHandler.h"

using namespace std;

class Command6:public ListGiver{

public:
    Command6(CTableHandler &handler);
    void RunCommand();
    void copyObjectAndAddIt(int i_index);

};
