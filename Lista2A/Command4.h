#include <iostream>
#include "sstream"
#include <vector>
#include "ListGiver.h"
#include "CTableHandler.h"

using namespace std;

class Command4:public ListGiver{

public:
    Command4(CTableHandler &handler);
    void RunCommand();
    void deleteAllElements();

};
