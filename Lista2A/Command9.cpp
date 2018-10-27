#include <iostream>
#include "sstream"
#include <vector>

#include "Command9.h"

using namespace std;

Command9::Command9(CTableHandler &handler):ListGiver(handler){}

void Command9::RunCommand(){
        cout<<"Podaj index obiektu do skopiowania"<<endl;
            int i_9=iGetAnyInt();
            cout<<"Podaj dlugosc o jaka mamy zmienic dlugosc"<<endl;
            int i_10=iGetAnyInt();
            copyObjectAndChangeSize(i_9,i_10);
    }

    void Command9::copyObjectAndChangeSize(int i_index,int i_newLength){
    if(i_index>=0 && i_index<handler->getList().size()){
        handler->getList().push_back(handler->getList().at(i_index)->copyAndExtend(i_newLength));
        //list.push_back(list[i_index]->copyAndExtend(i_newLength));
    }else{
        cout<<"Zly Indeks"<<endl;
        }        // TUTUTUTUTUTUT
}
