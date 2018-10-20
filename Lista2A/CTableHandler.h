#include <iostream>
#include "sstream"
#include <vector>
#include "CTable.h"
#pragma once
using namespace std;

class CTableHandler{
public:
    ~CTableHandler();
protected:
    int iGetAnyInt();
    static vector<CTable*> list;

};
