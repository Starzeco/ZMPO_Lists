#pragma once
#include <iostream>
#include "sstream"
#include <vector>
#include "CMenuItem.h"


using namespace std;


class CMenu : public CMenuItem
{
public:
    //Konstruktory i destruktory
     CMenu(string s_nameG,string s_commandG);
    ~CMenu();


    //Metody

    void toString();
    string getCommand();
    bool ifCommandExist();
    void run();
    void findCommandAndRun();
    void addCMenu();
  //  void ifItIsOneOfThree();
    void addCMenuCommand();
  //  void deleteM();

    void initializeCMenu();

private:
    std::vector<CMenuItem *>list;
    string s_commandGiven;

};
