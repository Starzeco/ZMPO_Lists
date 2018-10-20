#pragma once
#include <iostream>
#include "sstream"
#include <vector>

#include "Command1.h"

using namespace std;




    void Command1::RunCommand(){
        cout<<"Chcesz stworzyc domyslne obiekty to wpisz 1 swoje to 2"<<endl;
            int i_number=iGetAnyInt();

            cout<<"Ile chcesz stworzyc obiektow?"<<endl;
            int i_numberO=iGetAnyInt();

            if(i_number==1){
                createCTableObjectsDeafult(i_numberO);
            }else{
                cout<<"Podaj nazwe"<<endl;
                string s_name;
                cin>>s_name;
                cout<<"Podaj d³ugosc tablicy"<<endl;
                int i_size=iGetAnyInt();

                createCTableObjects(i_numberO,s_name,i_size);
            }

    }

    void Command1::createCTableObjectsDeafult(int i_number){
    if(i_number>0){
        for(int i=0;i<i_number;i++){
              CTable *var;
              var=new CTable();
              list.push_back(var);
    }
    }
    else{
        cout<<"Zla liczba podana"<<endl;
    }
}

void Command1::createCTableObjects(int i_number,string s_nazwa,int i_length){
    if(i_number>0){
        for(int i=0;i<i_number;i++){
            CTable *var;
            var=new CTable(s_nazwa,i_length);
            list.push_back(var);
        }
    }
    else{
        cout<<"Zla liczba podana"<<endl;
    }


}



