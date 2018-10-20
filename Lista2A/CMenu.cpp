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

    }


    void CMenu::toString(){
       cout<<"Nazwa CMenu: "<<s_name<<"("<<s_command<<")"<<endl;

    }
    string CMenu::getCommand(){
        return s_command;
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
        }
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


 /*   void CMenu::addCMenu(){
        cout<<"Podaj nazwa CMenu"<<endl;
        string s_s1;
        cin>>s_s1;
        cout<<"Podaj komende CMenu"<<endl;
        string s_s2;
        cin>>s_s2;
        list.push_back(new CMenu(s_s1,s_s2));
        s_commandGiven="back";
        run();                  // SPRAWDZAĆ JESZCZE CZY JUŻ TAKIEGO NIE MA

    }*/

    void CMenu::initializeCMenu(){
        CCommand *prob=new Command1();
      CMenuItem *teraz=new CMenuCommand("Dodawanie","run1",prob);

      list.push_back(teraz);       // Do usunięcia linijka
      CCommand *prob2=new Command2();
      CMenuItem *teraz2=new CMenuCommand("Zmiana dlugosci danej CTable","run2",prob2);
      list.push_back(teraz2);

      CCommand *prob3=new Command3();
      CMenuItem *teraz3=new CMenuCommand("Usun wybrany element","run3",prob3);
      list.push_back(teraz3);

      CCommand *prob4=new Command4();
      CMenuItem *teraz4=new CMenuCommand("Usun wszystkie CTable","run4",prob4);
      list.push_back(teraz4);

      CCommand *prob5=new Command5();
      CMenuItem *teraz5=new CMenuCommand("Zmien nazwe wybranego elementu","run5",prob5);
      list.push_back(teraz5);

      CCommand *prob6=new Command6();
      CMenuItem *teraz6=new CMenuCommand("Skopiuj wybrany element","run6",prob6);
      list.push_back(teraz6);

      CCommand *prob7=new Command7();
      CMenuItem *teraz7=new CMenuCommand("Wyswietl dany obiekt","run7",prob7);
      list.push_back(teraz7);

      CCommand *prob8=new Command8();
      CMenuItem *teraz8=new CMenuCommand("Zmien element w tablicy w CTable","run8",prob8);
      list.push_back(teraz8);

      CCommand *prob9=new Command9();
      CMenuItem *teraz9=new CMenuCommand("Skopiuj CTable i zmien rozmiar jego tablicy","run9",prob9);
      list.push_back(teraz9);


    }


    void CMenu::addCMenu(){

    }

    void CMenu::addCMenuCommand(){}

  //  void CMenu::deleteM(){}




