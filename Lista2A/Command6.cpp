#include <iostream>
#include "sstream"
#include <vector>

#include "Command6.h"

using namespace std;

void Command6::RunCommand(){
        cout<<"Ktory obiekt chcesz skolnowac?"<<endl;
            copyObjectAndAddIt(iGetAnyInt());
    }

    void Command6::copyObjectAndAddIt(int i_index){
    if(i_index>=0 && i_index<list.size()){
        list.push_back(list[i_index]->copyObject2());
    }else{
        cout<<"Zly Indeks"<<endl;
    }



}
