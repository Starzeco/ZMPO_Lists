#pragma once
#include <iostream>
#include "sstream"
#include <vector>
#include "CMenuItem.h"
#include "NamesHolder.h"

using namespace std;


class CMenu : public CMenuItem,NamesHolder
{
public:
    //Konstruktory i destruktory
     CMenu(string s_nameG,string s_commandG);
    ~CMenu();


    //Metody

    void toString();
    string getCommand();
    string getName();
    bool ifCommandExist();
    void run();
    void findCommandAndRun();
    void addMenu(CMenuItem *MenuToAdd);
  //  void ifItIsOneOfThree();
   // void addCMenuCommand();
    void deleteM(string command);
    bool ifCMenuItemExist(CMenuItem *MenuToAdd);

    void initializeCMenu();



private:
    std::vector<CMenuItem *>list;
    string s_commandGiven;

};
