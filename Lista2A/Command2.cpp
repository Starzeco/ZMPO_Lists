#pragma once
#include <iostream>
#include "sstream"
#include <vector>

#include "Command2.h"

using namespace std;


Command2::Command2(CTableHandler &handler):ListGiver(handler){}

    void Command2::RunCommand(){
        cout<<"Podaj jak dluga ma byc tablica"<<endl;
            int i_2=iGetAnyInt();

            cout<<"Podaj indeks obiektu"<<endl;
            int i_3=iGetAnyInt();

            changeLengthForChosenObject(i_3,i_2);
    }


    void Command2::changeLengthForChosenObject(int i_index,int i_newSize){
    if(i_index>=0 && i_index<handler->getList().size()){
        handler->getList().at(i_index)->changeLength(i_newSize);
        //list[i_index]->changeLength(i_newSize);
    }
    else{
        cout<<"Zly Indeks"<<endl;
    }


}
