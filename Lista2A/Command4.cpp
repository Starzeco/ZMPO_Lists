#include <iostream>
#include "sstream"
#include <vector>

#include "Command4.h"

using namespace std;

Command4::Command4(CTableHandler &handler):ListGiver(handler){}

void Command4::RunCommand(){
        cout<<"Usuniete wszystkie elementy "<<endl;
            deleteAllElements();
    }


    void Command4::deleteAllElements(){
    if(handler->getList().size()==0){
        cout<<"List jest pusta"<<endl;
    }
    else{
        for(int i=0;i<handler->getList().size();i++){
            delete handler->getList().at(i);
            //delete list[i];
        }

    }
    handler->getList().clear();
    //list.clear();


}
