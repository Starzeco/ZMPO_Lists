#include <iostream>
#include "sstream"
#include <vector>

#include "Command7.h"

using namespace std;

void Command7::RunCommand(){
        cout<<"Wybierz indeks obiektu"<<endl;

            printOutObject(iGetAnyInt());
    }

    void Command7::printOutObject(int i_index){
    if(i_index>=0 && i_index<list.size()){
        list[i_index]->toString();
    }else{
        cout<<"Zly Indeks"<<endl;
    }



}
