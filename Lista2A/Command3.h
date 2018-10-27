#include <iostream>
#include "sstream"
#include <vector>
#include "ListGiver.h"
#include "CTableHandler.h"

using namespace std;

class Command3:public ListGiver{

public:
    Command3(CTableHandler &handler);
    void RunCommand();
    void deleteChosenObject(int i_index);


};
