#include "iostream"
#include "sstream"
#include <iostream>
#include <vector>
#include "CMenuCommand.h"
#include <string>


using namespace std;


CMenuCommand::CMenuCommand(string s_nameG,string s_commandG){
    s_name=s_nameG;
    s_command=s_commandG;

}


CMenuCommand::CMenuCommand(string s_nameG,string s_commandG,CCommand *object){
    s_name=s_nameG;
    s_command=s_commandG;
    ccommand=object;

}


CMenuCommand::~CMenuCommand(){

    delete ccommand;
    cout<<"Usuwam CCommand z CMenuCommand"<<endl;

}

void CMenuCommand::toString(){
    cout<<"Nazwa CMenuCommand: "<<s_name<<"("<<s_command<<")"<<endl;
}


string CMenuCommand::getCommand(){
    return s_command;
}



void CMenuCommand::run(){
    if(ccommand){
    ccommand->RunCommand();
    }else{
        cout<<"Komenda domyœlna"<<endl;
    }
}
