#include "iostream"
#include "sstream"
#pragma once
#include <iostream>


using namespace std;


class CMenuItem{

protected:
    string s_command;
    string s_name;

public:
    virtual void run()=0;
    virtual void toString()=0;
    virtual string getCommand()=0;
    virtual ~CMenuItem(){};




};
