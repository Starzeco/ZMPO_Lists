#include <iostream>
#include "sstream"
#include <vector>
#include "CTableHandler.h"
#include "CTable.h"
using namespace std;



CTableHandler::~CTableHandler(){
    for(int i=0;i<list.size();i++){
        delete list[i];
    }

    list.clear();
    cout<<"Usuwam CTable liste"<<endl;
}
vector<CTable*> &CTableHandler::getList(){
    return list;
}



/*void CTableHandler::clean(){
    for(int i=0;i<list.size();i++){
        delete list[i];
    }

    list.clear();
    cout<<"Usuwam CTable liste"<<endl;
} */

