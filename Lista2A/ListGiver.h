#include "CCommand.h"
#include "CTableHandler.h"
#pragma once
using namespace std;

class ListGiver:public CCommand{

public:
    ListGiver(CTableHandler &handler);

protected:
    CTableHandler *handler;
    int iGetAnyInt();
};
