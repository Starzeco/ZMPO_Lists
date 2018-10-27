#include <iostream>
#include "sstream"
#include <vector>
#include "ListGiver.h"
#include "CTableHandler.h"

using namespace std;

class Command8:public ListGiver{

public:
    Command8(CTableHandler &handler);
    void RunCommand();
    void changeElementInCTable(int i_index,int i_indexC,int i_newValue);

};
