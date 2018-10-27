#include <iostream>
#include "sstream"
#include <vector>

#include "Command8.h"

using namespace std;

Command8::Command8(CTableHandler &handler):ListGiver(handler){}

void Command8::RunCommand(){
        cout<<"Ktory eleme1t wybierasz?"<<endl;
            int i_7=iGetAnyInt();
            cout<<"Jaki element w tablicy CTable chcesz zmienic?"<<endl;
            int i_8=iGetAnyInt();
            cout<<"Podaj nowa wartosc"<<endl;
            int i_9=iGetAnyInt();
            changeElementInCTable(i_7,i_8,i_9);
    }

    void Command8::changeElementInCTable(int i_index,int i_indexC,int i_newValue){
    if(i_index>=0 && i_index<handler->getList().size()){
        handler->getList().at(i_index)->add(i_indexC,i_newValue);
        //list[i_index]->add(i_indexC,i_newValue);
    }else{
        cout<<"Zly Indeks wektora"<<endl;
    }



}
