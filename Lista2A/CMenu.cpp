#include "iostream"
#include "sstream"
#include <iostream>
#include <vector>
#include "CMenu.h"
#include <string>
#include "CMenuCommand.h"
#include "Command1.h"
#include "Command2.h"

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
      CMenuCommand *teraz=new CMenuCommand("hejka","run1",prob);

      list.push_back(teraz);       // Do usunięcia linijka
      CCommand *prob2=new Command2();
      CMenuCommand *teraz2=new CMenuCommand("Druga kom","run2",prob2);
      list.push_back(teraz2);

      CMenuCommand *teraz3=new CMenuCommand("Trzecia kom Domyslna","run3");
      list.push_back(teraz3);

    }


    void CMenu::addCMenu(){

    }

    void CMenu::addCMenuCommand(){}

  //  void CMenu::deleteM(){}




