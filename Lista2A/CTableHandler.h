#include <iostream>
#include "sstream"
#include <vector>
#include "CTable.h"
#pragma once
//#include "CMenu.h"
using namespace std;

class CTableHandler{
public:
    ~CTableHandler();
    //static void clean();
    vector<CTable*> &getList();
private:
   vector<CTable*> list;



};
