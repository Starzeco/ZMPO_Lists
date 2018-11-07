#include "iostream"
#include "sstream"
#include <iostream>
#include <vector>
#include "CMenu.h"
#include <string>
#include "CMenuCommand.h"
#include "Command1.h"
#include "Command2.h"
#include "Command3.h"
#include "Command4.h"
#include "Command5.h"
#include "Command6.h"
#include "Command7.h"
#include "Command8.h"
#include "Command9.h"
#include "Command10.h"
#include "CTableHandler.h"
#include "NamesHolder.h"
//#include "MenuSearch.h"

using namespace std;


     CMenu::CMenu(string s_nameG,string s_commandG){

        s_name=s_nameG;
        s_command=s_commandG;

    }

    CMenu::CMenu(string s_nameG,string s_commandG,MenuSearch &menuSearchGiven){

        s_name=s_nameG;
        s_command=s_commandG;
        menuSearch=&menuSearchGiven;

    }

    CMenu::~CMenu(){
        for(int i_i=0;i_i<list.size();i_i++){
            delete list[i_i];

        }
        list.clear();
        cout<<"Usuwam liste CMenu"<<endl;
    }

    void CMenu::printPostOrder(){
        for(int i_i=0;i_i<list.size();i_i++){
            int i_ii=i_i+1;
            cout<<i_ii<<".";
            list[i_i]->toString();
        }
        for(int i_x=0;i_x<list.size();i_x++){
            if(CMenu *next=dynamic_cast<CMenu *>(list[i_x])){
                next->printPostOrder();
            }
        }
    }
    void CMenu::printTree(){
        for(int i_i=0;i_i<list.size();i_i++){
            cout<<list[i_i]->getCommand();
        }
        cout<<""<<endl;
        for(int i_x=0;i_x<list.size();i_x++){
            if(CMenu *next=dynamic_cast<CMenu *>(list[i_x])){
                next->printTree();
            }
        }

    }
    void CMenu::run(){
      s_commandGiven="";
      names.push_back(s_name);
      for(int i=0;i<names.size();i++){
        cout<<names[i]+"-->";
      }
      cout<<""<<endl;

      while(s_commandGiven!="back"){
        cout<<"-----------------"<<endl;
        toString();


      for(int i_i=0;i_i<list.size();i_i++){
            //Edit chyba juz okPrint();
            int i_ii=i_i+1;
            cout<<i_ii<<".";
            list[i_i]->toString();
            /*if(CMenu *next=dynamic_cast<CMenu *>(list[i_i])){
                next->Print();
            }*/

        }
        /*if(s_name=="Menu Glowne"){
            for(int i_i3=0;i_i3<list.size();i_i3++){
            int i_ii3=i_i3+1;
            cout<<i_ii3<<".";
            list[i_i3]->toString();
        }
        }*/


        while(!ifCommandExist()){
            cout<<"Zla komenda, podaj nowa"<<endl;
        }


        findCommandAndRun();   // Wœrodku sprawdza czy to nie back


      }

      names.pop_back();
      for(int is=0;is<names.size();is++){
        cout<<names[is]+"-->";
      }
      cout<<""<<endl;

    }



    void CMenu::toString(){
       cout<<"Nazwa CMenu: "<<s_name<<"("<<s_command<<")"<<endl;

    }
    string CMenu::getCommand(){
        return s_command;
    }
    string CMenu::getName(){
        return s_name;
    }

    bool CMenu::ifCommandExist(){

        std::getline(std::cin,s_commandGiven);
        //cin>>s_commandGiven;
        string token=s_commandGiven.substr(0,5);
        string token2=s_commandGiven.substr(0,7);
        if(s_commandGiven=="back" || token=="help " || token2=="search " /*|| s_commandGiven=="delete"*/){
            return true;
        }
        for(int i_i=0;i_i<list.size();i_i++){
            if(list[i_i]->getCommand()==s_commandGiven){
                return true;
            }
        }
        return false;

    }


    void CMenu::findCommandAndRun(){
        string token=s_commandGiven.substr(0,5);
        string token2=s_commandGiven.substr(0,7);
        if(s_commandGiven!="back" && token!="help " && token2!="search " /*&& s_commandGiven!="delete"*/){
            for(int i_i=0;i_i<list.size();i_i++){
                if(list[i_i]->getCommand()==s_commandGiven){
                    list[i_i]->run();
                }
            }
        }else{
            if(token=="help "){
                string tokenBack=s_commandGiven.substr(5,s_commandGiven.length());
                int i_mean=0;
                for(int i_index=0;i_index<list.size();i_index++){
                   if(tokenBack==list[i_index]->getCommand() && dynamic_cast<CMenuCommand *>(list[i_index])){
                        CMenuCommand *temp=dynamic_cast<CMenuCommand *>(list[i_index]);
                        cout<<temp->getDescription()<<endl;
                        i_mean=1;
                   }
                }
                if(i_mean==0){
                    cout<<"Bledna komenda"<<endl;
                }

            }else{
                if(token2=="search "){
                    string token2Back=s_commandGiven.substr(7,s_commandGiven.length());
                    string path="";
                    menuSearch->searchForPath(NULL,token2Back,path);
                }
            }
        }



    }




   void CMenu::addMenu(CMenuItem *MenuToAdd){
        if(ifCMenuItemExist(MenuToAdd)){
            string mom=MenuToAdd->getName();
            cout<<"Istnieje juz taki CMenuItem"<<endl;
            cout<<mom<<endl;
        }else{
            list.push_back(MenuToAdd);
        }
                          // Nie wiem czy tu takie argumenty trzeba przekazywać ???

    }
    bool CMenu::ifCMenuItemExist(CMenuItem *MenuToAdd){
        for(int i_i=0;i_i<list.size();i_i++){
            if(list[i_i]->getCommand()==MenuToAdd->getCommand() || list[i_i]->getName()==MenuToAdd->getName()){
                return true;
            }
        }
        return false;

    }
    vector<CMenuItem *> CMenu::getList(){
        return list;
    }



    void CMenu::deleteM(string command){
        for(int i_i=0;i_i<list.size();i_i++){
            if(list[i_i]->getCommand()==command){
                delete list[i_i];
                list.erase(list.begin()+i_i);
            }
        }

    }




