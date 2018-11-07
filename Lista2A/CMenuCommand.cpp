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

CMenuCommand::CMenuCommand(string s_nameG,string s_commandG,string desc){
    s_name=s_nameG;
    s_command=s_commandG;
    s_description=desc;
}


CMenuCommand::CMenuCommand(string s_nameG,string s_commandG,CCommand *object,string description){
    s_name=s_nameG;
    s_command=s_commandG;
    ccommand=object;
    s_description=description;
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

string CMenuCommand::getDescription(){
    return s_description;
}

string CMenuCommand::getName(){
    return s_name;
}

void CMenuCommand::run(){
    if(ccommand){
    ccommand->RunCommand();
    }else{
        cout<<"Komenda domyœlna"<<endl;
    }
}
