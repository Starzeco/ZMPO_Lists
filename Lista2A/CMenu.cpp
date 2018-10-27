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

using namespace std;




    CMenu::CMenu(string s_nameG,string s_commandG){

        s_name=s_nameG;
        s_command=s_commandG;

    }

    CMenu::~CMenu(){
        for(int i_i=0;i_i<list.size();i_i++){
            delete list[i_i];

        }
        list.clear();
        cout<<"Usuwam liste CMenu"<<endl;
    }

    void CMenu::run(){
      s_commandGiven="";
      names.push_back(s_name);
      for(int i=0;i<names.size();i++){
        cout<<names[i]+"-->";
      }
      while(s_commandGiven!="back"){
        cout<<"-----------------"<<endl;
        toString();
        for(int i_i=0;i_i<list.size();i_i++){
            //Edit chyba juz ok

            int i_ii=i_i+1;
            cout<<i_ii<<".";
            list[i_i]->toString();
           /* if(i_ii==list.size()){
                i_ii++;
                cout<<i_ii<<".Dodaj CMenu(addm)"<<endl;
                i_ii++;
                cout<<i_ii<<".Dodaj CMenuCommand(addmc)"<<endl;
                i_ii++;
                cout<<i_ii<<".Usun CMenu/CMenuCommand(delete)"<<endl;

            }*/

        }

        while(!ifCommandExist()){
            cout<<"Zla komenda, podaj nowa"<<endl;
        }


        findCommandAndRun();   // Wœrodku sprawdza czy to nie back


      }

      names.pop_back();
      for(int is=0;is<names.size();is++){
        cout<<names[is]+"-->"<<endl;
      }

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
        //string s_commandGiven;
        cin>>s_commandGiven;
        if(s_commandGiven=="back"/* || s_commandGiven=="addm" || s_commandGiven=="addmc" || s_commandGiven=="delete"*/){
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
        if(s_commandGiven!="back" /*&& s_commandGiven!="addm" && s_commandGiven!="addmc" && s_commandGiven!="delete"*/){
            for(int i_i=0;i_i<list.size();i_i++){
                if(list[i_i]->getCommand()==s_commandGiven){
                    list[i_i]->run();
                }
            }
        }/*else{
            if(s_name=="Menu Glowne"){
                CTableHandler::clean();
            }
        }*/
       /* else{
            ifItIsOneOfThree();
        }*/


    }

   /* void CMenu::ifItIsOneOfThree(){
        if(s_commandGiven=="addm"){
            addCMenu();
        }else{
            if(s_commandGiven=="addmc"){
                addCMenuCommand();      // Do zrobienia
            }else{
                if(s_commandGiven=="delete"){
                    deleteM();          // Do zrobienia
                }
            }
        }
    }*/


   void CMenu::addMenu(CMenuItem *MenuToAdd){
        if(ifCMenuItemExist(MenuToAdd)){
            cout<<"Istnieje juz taki CMenuItem"<<endl;
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

  /*  void CMenu::initializeCMenu(){

      CTableHandler *handlero=new CTableHandler();
      CCommand *prob=new Command1(handlero);
      CMenuItem *teraz=new CMenuCommand("Dodawanie","run1",prob);
      //list.push_back(teraz);


      CCommand *prob2=new Command2(handlero);
      CMenuItem *teraz2=new CMenuCommand("Zmiana dlugosci danej CTable","run2",prob2);
      //list.push_back(teraz2);

      CCommand *prob3=new Command3(handlero);
      CMenuItem *teraz3=new CMenuCommand("Usun wybrany element","run3",prob3);
      //list.push_back(teraz3);

      CCommand *prob4=new Command4(handlero);
      CMenuItem *teraz4=new CMenuCommand("Usun wszystkie CTable","run4",prob4);
      //list.push_back(teraz4);

      CCommand *prob5=new Command5(handlero);
      CMenuItem *teraz5=new CMenuCommand("Zmien nazwe wybranego elementu","run5",prob5);
      //list.push_back(teraz5);

      CCommand *prob6=new Command6(handlero);
      CMenuItem *teraz6=new CMenuCommand("Skopiuj wybrany element","run6",prob6);
      //list.push_back(teraz6);

      CCommand *prob7=new Command7(handlero);
      CMenuItem *teraz7=new CMenuCommand("Wyswietl dany obiekt","run7",prob7);
      //list.push_back(teraz7);

      CCommand *prob8=new Command8(handlero);
      CMenuItem *teraz8=new CMenuCommand("Zmien element w tablicy w CTable","run8",prob8);
      //list.push_back(teraz8);

      CCommand *prob9=new Command9(handlero);
      CMenuItem *teraz9=new CMenuCommand("Skopiuj CTable i zmien rozmiar jego tablicy","run9",prob9);
      //list.push_back(teraz9);



      CMenu *menu=new CMenu("Dodawanie","menu1");
      menu->list.push_back(teraz);
      list.push_back(menu);


      CMenu *menu1a=new CMenu("Kopiowanie","menu1a");
      menu1a->list.push_back(teraz6);
      menu1a->list.push_back(teraz9);
      menu->list.push_back(menu1a);

      CMenu *menu2=new CMenu("Usuwanie","menu2");
      menu2->list.push_back(teraz3);
      menu2->list.push_back(teraz4);
      list.push_back(menu2);

      CMenu *menu3=new CMenu("Zmiany","menu3");
      CMenu *menu3a=new CMenu("Zmiany w CTable","menu3a");
      menu3a->list.push_back(teraz2);
      menu3a->list.push_back(teraz5);
      menu3->list.push_back(menu3a);
      CMenu *menu3b=new CMenu("Zmiany w tablicy CTable","menu3b");
      menu3b->list.push_back(teraz8);
      menu3->list.push_back(menu3b);
      list.push_back(menu3);

      list.push_back(teraz7);

    }*/



    /*void CMenu::addCMenu(){

    }

    void CMenu::addCMenuCommand(){} */

    void CMenu::deleteM(string command){
        for(int i_i=0;i_i<list.size();i_i++){
            if(list[i_i]->getCommand()==command){
                delete list[i_i];
                list.erase(list.begin()+i_i);
            }
        }

    }




