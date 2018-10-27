#include <iostream>
#include "sstream"
#include <vector>

#include "Command5.h"

using namespace std;

Command5::Command5(CTableHandler &handler):ListGiver(handler){}

void Command5::RunCommand(){
        cout<<"Ktorego elementu chcesz zmienic nazwe?"<<endl;
            int i_5=iGetAnyInt();
            cout<<"Jaka ma byc nazwa?"<<endl;
            string s_1;
            cin>>s_1;
            changeNameOfChosenElement(i_5,s_1);
    }


    void Command5::changeNameOfChosenElement(int i_index,string s_newName){
    if(i_index>=0 && i_index<handler->getList().size()){
        handler->getList().at(i_index)->setName(s_newName);

        //list[i_index]->setName(s_newName);

    }else{
        cout<<"Zly Indeks"<<endl;
    }

}
