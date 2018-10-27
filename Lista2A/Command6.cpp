#include <iostream>
#include "sstream"
#include <vector>

#include "Command6.h"

using namespace std;

Command6::Command6(CTableHandler &handler):ListGiver(handler){}

void Command6::RunCommand(){
        cout<<"Ktory obiekt chcesz skolnowac?"<<endl;
            copyObjectAndAddIt(iGetAnyInt());
    }

    void Command6::copyObjectAndAddIt(int i_index){
    if(i_index>=0 && i_index<handler->getList().size()){
        handler->getList().push_back(handler->getList().at(i_index)->copyObject2());
        //list.push_back(list[i_index]->copyObject2());
    }else{
        cout<<"Zly Indeks"<<endl;
    }



}
