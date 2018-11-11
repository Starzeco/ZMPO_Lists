#include "CMenuCreater.h"
#include "CMenu.h"
#include "CMenuCommand.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <bits/stdc++.h>
#include "MenuSearch.h"

using namespace std;

string CMenuCreater::cMenuToString(CMenu *cmenu){
    stringstream s_CMenuString;
    s_CMenuString<<"("<<"*"<<cmenu->getName()<<"*"<<","<<"*"<<cmenu->getCommand()<<"*"<<";";
    for(int i_i=0;i_i<cmenu->getList().size();i_i++){
        if(CMenu *next=dynamic_cast<CMenu *>(cmenu->getList()[i_i])){
            s_CMenuString<<cMenuToString(next);
        }
        else{
            s_CMenuString<<cMenuCommandToString(dynamic_cast<CMenuCommand *>(cmenu->getList()[i_i]));
        }
        if(i_i!=cmenu->getList().size()-1){
            s_CMenuString<<",";
        }

    }
    s_CMenuString<<")";
    return s_CMenuString.str();


}


string CMenuCreater::cMenuCommandToString(CMenuCommand *cMenuCommand){
    stringstream s_CMenuCommandString;
    s_CMenuCommandString<<"["<<"*"<<cMenuCommand->getName()<<"*"<<","<<"*"<<cMenuCommand->getCommand()<<"*"<<","<<"*"<<cMenuCommand->getDescription()<<"*"<<"]";
    return s_CMenuCommandString.str();


}


bool CMenuCreater::writeToFile(string cmenu){
    ofstream toFileStream;
    toFileStream.open("hej.txt");
    if (toFileStream.is_open()) {
        toFileStream <<cmenu<< endl;
        toFileStream.close();
        return true;
    } else {
        toFileStream.close();
        return false;
    }

}

bool CMenuCreater::serialize(CMenu *cmenu){
    writeToFile(cMenuToString(cmenu));

}

string CMenuCreater::readFromFile(string fileName){
    ifstream fromFileStream(fileName.c_str());
    string menu;
    if (fromFileStream.is_open()) {
        getline(fromFileStream, menu);
    }
    fromFileStream.close();
    return menu;

}
CMenu* CMenuCreater::readCMenu(string cmenuToRead,MenuSearch &searcher){
    int secondStar=cmenuToRead.find("*",1);
    string name=cmenuToRead.substr(1,secondStar-1);
    int thirdStar=cmenuToRead.find("*",secondStar+1);
    int fourthStar=cmenuToRead.find("*",thirdStar+1);
    string command=cmenuToRead.substr(thirdStar+1,fourthStar-1-thirdStar);
    CMenu *menu=new CMenu(name,command,searcher);

    return menu;

}

CMenuCommand* CMenuCreater::readCMenuCommand(string cmenuCommandToRead){
    int secondStar=cmenuCommandToRead.find("*",1);
    string name=cmenuCommandToRead.substr(1,secondStar-1);
    int thirdStar=cmenuCommandToRead.find("*",secondStar+1);
    int fourthStar=cmenuCommandToRead.find("*",thirdStar+1);
    string command=cmenuCommandToRead.substr(thirdStar+1,fourthStar-1-thirdStar);
    int fifthStar=cmenuCommandToRead.find("*",fourthStar+1);
    int sixthStar=cmenuCommandToRead.find("*",fifthStar+1);
    string help=cmenuCommandToRead.substr(fifthStar+1,sixthStar-1-fifthStar);

    CMenuCommand *menucommand=new CMenuCommand(name,command,NULL,help);

    return menucommand;



}

int CMenuCreater::findPositionOfClosingBracket(string menu){
    int openingBrackets=0;

    for(int i_i=0;i_i<menu.length();i_i++){
        if(menu[i_i]=='('){
            ++openingBrackets;
        }else if(menu[i_i]==')'){
                    --openingBrackets;
                    if(openingBrackets==0){
                        return i_i;
                    }
            }
    }


    return -1;

}


CMenu* CMenuCreater::createCMenuFromString(string path,MenuSearch &searcher){

    string start;
    string cmenuToRead=path.substr(1,path.find(";")-1);
    CMenu *cmenu=readCMenu(cmenuToRead,searcher);


    start=path.substr(path.find(";")+1,1);

    while(start!=")"){
        if(start=="["){

            string command=path.substr(path.find("[")+1,path.find("]")-1-path.find("["));
            cmenu->addMenu(readCMenuCommand(command));


            if(path.substr(path.find("]")+1,1)==","){
                    start=path.substr(path.find("]")+2,1);
                    if(start=="["){

                        path=path.substr(path.find("]")+2,string::npos);
                    }
            }else{

                    start=")";
                }

        }

        if(start=="("){


                string newPath;
                if(path.substr(path.find(";")+1,1)=="["){
                    newPath=path.substr(path.find("(",1),string::npos);
                }else if(path.substr(path.find(";")+1,1)=="("){
                    newPath=path.substr(path.find(";")+1,string::npos);
                }

                cmenu->addMenu(createCMenuFromString(newPath,searcher));
                string pom="";

                if(newPath.substr(findPositionOfClosingBracket(newPath)-1,1)==")" ){

                    if(findPositionOfClosingBracket(path)==findPositionOfClosingBracket(newPath)){
                        start=newPath.substr(findPositionOfClosingBracket(newPath),1);
                    }else{

                        start=newPath.substr(findPositionOfClosingBracket(newPath)+1,1);
                        pom=newPath.substr(findPositionOfClosingBracket(newPath)+1,string::npos);
                    }



                }else{

                    start=newPath.substr(findPositionOfClosingBracket(newPath)+1,1);
                }


                if(pom==""){
                    path=newPath;
                }else{
                    path=pom;
                }

                if(start==","){


                    start=newPath.substr(findPositionOfClosingBracket(newPath)+2,1);
                    if(newPath.substr(findPositionOfClosingBracket(newPath)+2,1)=="["){

                        path=newPath.substr(findPositionOfClosingBracket(newPath)+2,string::npos);
                    }

                }


        }


    }

    return cmenu;
}


bool CMenuCreater::validate(string menu){
    if(menu.empty()){
        return false;
    }
    for(int i=0;i<menu.length();i++){
        if(i==0 && menu[i]!='('){
            cout<<"Blad na indeksie a"<<i<<endl;
            return false;
        }
        if(i==menu.length()-1 && menu[i]!=')'){
           cout<<"Blad na indeksie b"<<i<<endl;
           return false;
        }
        if(menu[i]=='('){
            if(menu[i+1]!='*'){
                cout<<"Po nawiasie powinna byc gwiazdka na indeksie c"<<i+1<<endl;
                return false;
            }
            if(menu[i+2]=='*'){
                cout<<"Za krotka nazwa d"<<i+2<<endl;
                return false;
            }



            int indexOfSecondStar=menu.find("*",i+2);
            if(indexOfSecondStar==-1){

                for(int j=i+2;j<menu.length();j++){
                    if(ifIsEqual(menu[j])){

                        cout<<"Przed znakiem powinna byc gwiazdka na indeksie "<<j-1<<endl;
                        return false;

                    }

                }

                cout<<"Po wyrazeniu powinna byc gwiazdka na indeksie "<<menu.length()<<endl;
                return false;

            }


            if(menu[indexOfSecondStar-1]==','){           //Pierwszy warunek niepotrzebny Ale ułątwia myśleni

                cout<<"Powinna byc gwiazdka przed "<<indexOfSecondStar-1<<endl;
                return false;
            }
            if(menu[indexOfSecondStar+1]!=','){
                cout<<"Powinien byc przecinek po indeksie a"<<indexOfSecondStar<<endl;
                return false;
            }
            if(menu[indexOfSecondStar+1]==';'){
                cout<<"Powinien byc przecinek po indeksie b"<<indexOfSecondStar<<endl;
                return false;
            }
            if(menu[indexOfSecondStar-1]=='['){
                if(menu[indexOfSecondStar-2]==';'){
                    cout<<"Powinna byc gwiazdka przed indeksem "<<indexOfSecondStar-2<<endl;

                    return false;
                }else{
                    //Do nothing
                }


            }

                // CHyba wystarczająco przypadków
            for(int j=i+2;j<indexOfSecondStar;j++){
                if(ifIsEqual(menu[j])){
                    cout<<"Zakazany znak a "<<menu[j]<<" w nazwie na indeksie, usun go "<<j<<endl;
                    return false;
                }
            }

            // SPRAWDZANIE 3 GWIAZDKI

            int indexOfThirdStar=menu.find("*",indexOfSecondStar+1);
            if(indexOfThirdStar==-1){

                for(int j1=i+indexOfSecondStar+1;j1<menu.length();j1++){
                    if(ifIsEqual(menu[j1])){

                        cout<<"Przed znakiem powinna byc gwiazdka na indeksie "<<j1-1<<endl;
                        return false;

                    }

                }

                cout<<"Po wyrazeniu powinna byc gwiazdka na indeksie "<<menu.length()<<endl;
                return false;

            }
            if(menu[indexOfThirdStar+1]==';'){
                cout<<"Gwiazdka powinna byc po indeksie a"<<indexOfSecondStar+1<<endl;
                return false;
            }
            if(menu[indexOfThirdStar-1]!=','){
                cout<<"Gwizadka powinna byc po indeksie b"<<indexOfSecondStar+1<<endl;
                return false;
            }

            //SPRAWDZANIE 4 GWIAZDKI

            int indexOfFourthStar=menu.find("*",indexOfThirdStar+1);
            if(indexOfFourthStar==-1){

                for(int j1=i+indexOfThirdStar+1;j1<menu.length();j1++){
                    if(ifIsEqual(menu[j1])){

                        cout<<"Przed znakiem powinna byc gwiazdka na indeksie "<<j1-1<<endl;
                        return false;

                    }

                }

                cout<<"Po wyrazeniu powinna byc gwiazdka na indeksie "<<menu.length()<<endl;
                return false;

            }

            if(menu[indexOfThirdStar+1]=='*'){
                cout<<"Za krótka komenda na indeksie "<<indexOfThirdStar<<endl;
                return false;
            }
            if((menu[indexOfFourthStar-1]=='[' || menu[indexOfFourthStar-1]=='(')&& menu[indexOfFourthStar-2]==';'){
                cout<<"Powinnna byc gwiazdka przed indeksem "<<indexOfFourthStar-2<<endl;
                return false;
            }

            if(menu[indexOfFourthStar+1]!=';'){
                cout<<"Po gwiazdce powinien byc srednik na indeksie "<<indexOfFourthStar+1<<endl;
                return false;
            }
            if(menu[indexOfFourthStar+2]!='(' && menu[indexOfFourthStar+2]!='[' && menu[indexOfFourthStar+2]!=')' ){
                cout<<"Po indeksie "<<indexOfFourthStar+1<<" powinien byc albo ( albo [ albo )"<<endl;
                return false;
            }

            for(int p=i+indexOfThirdStar+1;p<indexOfFourthStar;p++){
                if(ifIsEqual(menu[p])){
                    cout<<"Zakazany znak b "<<menu[p]<<" w nazwie na indeksie, usun go "<<p<<endl;
                    return false;
                }
            }
            //KONIEC SPRAWDZANIA GWIAZDEK w MENU
            //SPRAWDZANIE ZAMKNIEC NAWIASOW OKRAGLYCH


           /* string strToCheckBracket=menu.substr(i,string::npos);
            if(findPositionOfClosingBracket(strToCheckBracket)==-1){
                if(menu[indexOfFourthStar+3]==','){
                    cout<<"Przed przecinkiem powinien byc nawias zamykajacy przed indeksem "<<indexOfFourthStar+3<<endl;
                    return false;
                }
                // NIE WIEM JAK SPRAWDZIC JESZCZE TRZEBA ZROBIC


            } */




        }
        if(menu[i]=='['){
            if(menu[i+1]!='*'){
                cout<<"Komenda powinna zaczynac sie od gwiazdki "<<i+1<<endl;
                return false;
            }
            if(menu[i+2]=='*'){
                cout<<"Za krotka nazwa "<<i+2<<endl;
                return false;
            }
            //DRUGA GWIAZDKA KOMENDA
            int indexOfSecondStar=menu.find("*",i+2);
            if(indexOfSecondStar==-1){

                for(int j1=i+2;j1<menu.length();j1++){
                    if(ifIsEqual(menu[j1])){

                        cout<<"Przed znakiem powinna byc gwiazdka na indeksie "<<j1-1<<endl;
                        return false;

                    }

                }

                cout<<"Po wyrazeniu powinna byc gwiazdka na indeksie "<<menu.length()<<endl;
                return false;

            }
            if(menu[indexOfSecondStar-1]==','){
                cout<<"Przed przecinkiem trzeba postawic gwizadke przed indeksem "<<indexOfSecondStar-1<<endl;
                return false;
            }
            if(menu[indexOfSecondStar+1]!=',' ){
                cout<<"Po gwiazdce powinien byc przecinek po indeksie "<<indexOfSecondStar<<endl;
                return false;
            }
            for(int p=i+2;p<indexOfSecondStar;p++){
                if(ifIsEqual(menu[p])){
                    cout<<"Zakazany znak "<<menu[p]<<" w nazwie na indeksie, usun go "<<p<<endl;
                    return false;
                }
            }

            // 3 GWIAZDKA W KOMENDZIE

            int indexOfThirdStar=menu.find("*",indexOfSecondStar+1);
            if(indexOfThirdStar==-1){

                for(int j1=i+indexOfSecondStar+1;j1<menu.length();j1++){
                    if(ifIsEqual(menu[j1])){

                        cout<<"Przed znakiem powinna byc gwiazdka na indeksie "<<j1-1<<endl;
                        return false;

                    }

                }

                cout<<"Po wyrazeniu powinna byc gwiazdka na indeksie "<<menu.length()<<endl;
                return false;

            }
            if(menu[indexOfThirdStar+1]==','){
                cout<<"Gwiazdka powinna byc po indeksie "<<indexOfSecondStar+1<<endl;
                return false;
            }
            if(menu[indexOfThirdStar-1]==',' && menu[indexOfThirdStar-2]!='*'){
                cout<<"Powinienes postawic gwiazdke po indeksie "<<indexOfSecondStar+1<<" i przed indeksem "<<indexOfThirdStar-1<<endl;
                return false;
            }
            if(menu[indexOfThirdStar+1]==']'){
                cout<<"Powinienes postawic gwiazdke po indeksie "<<indexOfSecondStar+1<<endl;
                return false;
            }

            //4 GWIAZDKA KOMENDY
            int indexOfFourthStar=menu.find("*",indexOfThirdStar+1);
            if(indexOfFourthStar==-1){

                for(int j1=i+indexOfThirdStar+1;j1<menu.length();j1++){
                    if(ifIsEqual(menu[j1])){

                        cout<<"Przed znakiem powinna byc gwiazdka na indeksie "<<j1-1<<endl;
                        return false;

                    }

                }

                cout<<"Po wyrazeniu powinna byc gwiazdka na indeksie "<<menu.length()<<endl;
                return false;

            }
            if(menu[indexOfThirdStar+1]=='*'){
                cout<<"Za krotka komenda "<<indexOfThirdStar<<endl;
                return false;
            }

            if(menu[indexOfFourthStar-1]==','){
                cout<<"Powinienes postawic gwiazdke przed indeksem "<<indexOfFourthStar-1<<endl;
                return false;
            }
            if(menu[indexOfFourthStar+1]==']'){
                cout<<"Powinienes postawic przecinek po indeksie "<<indexOfFourthStar<<endl;
                return false;
            }
            if(menu[indexOfFourthStar+1]!=','){
                cout<<"Powinienes postawic przecinek po indeksie "<<indexOfFourthStar<<endl;
                return false;
            }


            for(int s=i+indexOfThirdStar+1;s<indexOfFourthStar;s++){
                if(ifIsEqual(menu[s])){
                    cout<<"Zakazany znak "<<menu[s]<<" w nazwie na indeksie, usun go "<<s<<endl;
                    return false;
                }
            }
            // 5 GWIAZDKA KOMENDY

            int indexOfFifthStar=menu.find("*",indexOfFourthStar+1);
            if(indexOfFifthStar==-1){

                for(int j1=i+indexOfFourthStar+1;j1<menu.length();j1++){
                    if(ifIsEqual(menu[j1])){

                        cout<<"Przed znakiem powinna byc gwiazdka na indeksie "<<j1-1<<endl;
                        return false;

                    }

                }

                cout<<"Po wyrazeniu powinna byc gwiazdka na indeksie "<<menu.length()<<endl;
                return false;

            }
            if(menu[indexOfFifthStar+1]==']'){
                cout<<"Powinienes postawic gwiazdke po indeksie "<<indexOfFourthStar+1<<endl;
                return false;
            }
            if(menu[indexOfFifthStar-1]!=','){      //Tutaj spr
                cout<<"Powinienes postawic gwiazkde po indeksie "<<indexOfFourthStar+1<<endl;
                return false;
            }


            //6 GWIAZDKA KOMENDY
            int indexOfSixthStar=menu.find("*",indexOfFifthStar+1);
            if(indexOfSixthStar==-1){

                for(int j1=i+indexOfFifthStar+1;j1<menu.length();j1++){
                    if(ifIsEqual(menu[j1])){

                        cout<<"Przed znakiem powinna byc gwiazdka na indeksie "<<j1-1<<endl;
                        return false;

                    }

                }

                cout<<"Po wyrazeniu powinna byc gwiazdka na indeksie "<<menu.length()<<endl;
                return false;

            }
            if(menu[indexOfFifthStar+1]=='*'){
                cout<<"Za krotki help "<<indexOfFifthStar<<endl;
                return false;
            }
            if(menu[indexOfSixthStar-1]=='[' || menu[indexOfSixthStar-1]=='('){
                cout<<"Powinienes postawic gwiazdke przed indeksem "<<indexOfSixthStar-3<<endl;
                return false;
            }
            if(menu[indexOfSixthStar+1]!=']'){
                cout<<"Powinienes postawic nawias kwadratowy zamykajacy po indeksie "<<indexOfSixthStar<<endl;
                return false;
            }



            for(int t=i+indexOfFifthStar+1;t<indexOfSixthStar;t++){
                if(ifIsEqual(menu[t])){
                    cout<<"Zakazany znak "<<menu[t]<<" w nazwie na indeksie, usun go "<<t<<endl;
                    return false;
                }
            }



        }
        if(menu[i]==','){
            if((menu[i-1]==')' || menu[i-1]==']')&& (menu[i+1]!='(' && menu[i+1]!='[')){
                cout<<"Po przecinku powinien być nawias otwierajacy po indeksie "<<i<<endl;
                return false;
            }
        }
        if((menu[i]==')' || menu[i]==']') && i!=menu.length()-1){
            if(menu[i+1]!=',' && (menu[i+1]!=')' && menu[i+1]!=']')){
                cout<<"Brak Przecinka po indeksie "<<i<<endl;
                return false;
            }

        }



    }
    return true;
}

bool CMenuCreater::ifIsEqual(char pom){
    if(pom=='(' || pom==')' || pom=='[' || pom==']' || pom=='*' || pom==';' || pom==','){
        return true;
    }
    else{
        return false;
    }

}



CMenu* CMenuCreater::deserialize(MenuSearch &searcher){

    if(validate(readFromFile("hej.txt"))){
        CMenu *cmenu=createCMenuFromString(readFromFile("hej.txt"),searcher);
        searcher.setCMenu(*cmenu);
        return cmenu;
    }else{

        return NULL;
    }


}




