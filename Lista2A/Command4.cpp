#include <iostream>
#include "sstream"
#include <vector>

#include "Command4.h"

using namespace std;

void Command4::RunCommand(){
        cout<<"Usuniete wszystkie elementy "<<endl;
            deleteAllElements();
    }


    void Command4::deleteAllElements(){
    if(list.size()==0){
        cout<<"List jest pusta"<<endl;
    }
    else{
        for(int i=0;i<list.size();i++){
            delete list[i];
        }

    }
    list.clear();


}
