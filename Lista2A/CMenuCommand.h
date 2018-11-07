#pragma once
#include <iostream>
#include "sstream"
#include <vector>
#include "CMenuItem.h"
#include "CCommand.h"

using namespace std;

class CMenuCommand:public CMenuItem{

public:
    //Konstruktory i destruktory
    CMenuCommand(string s_name,string s_command);
    CMenuCommand(string s_name,string s_command,CCommand *cc_object,string description);
    CMenuCommand(string s_name,string s_command,string description);

    ~CMenuCommand();


    //Metody

    void toString();
    string getCommand();
    void run();
    string getName();
    string getDescription();
private:
    CCommand *ccommand;
    string s_description;



};
