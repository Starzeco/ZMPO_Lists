#include <iostream>
#include "sstream"
#include <vector>

#include "Command7.h"

using namespace std;

Command7::Command7(CTableHandler &handler):ListGiver(handler){}

void Command7::RunCommand(){
        cout<<"Wybierz indeks obiektu"<<endl;

            printOutObject(iGetAnyInt());
    }

    void Command7::printOutObject(int i_index){
    if(i_index>=0 && i_index<handler->getList().size()){
        handler->getList().at(i_index)->toString();
        //list[i_index]->toString();
    }else{
        cout<<"Zly Indeks"<<endl;
    }



}
