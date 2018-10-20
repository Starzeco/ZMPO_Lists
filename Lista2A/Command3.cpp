#include <iostream>
#include "sstream"
#include <vector>

#include "Command3.h"

using namespace std;

void Command3::RunCommand(){
        cout<<"Ktory obiekt chcesz usunac?"<<endl;
            deleteChosenObject(iGetAnyInt());
    }

    void Command3::deleteChosenObject(int i_index){
    if(i_index>=0 && i_index<list.size()){
        delete list.at(i_index);
        list.erase(list.begin()+i_index);


    }else{
        cout<<"Zly Indeks"<<endl;
    }


}
