#include "CMenuCreater.h"
#include "CMenu.h"
#include "CMenuCommand.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <bits/stdc++.h>

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
CMenu* CMenuCreater::readCMenu(string cmenuToRead){
    int secondStar=cmenuToRead.find("*",1);
    string name=cmenuToRead.substr(1,secondStar-1);
    int thirdStar=cmenuToRead.find("*",secondStar+1);
    int fourthStar=cmenuToRead.find("*",thirdStar+1);
    string command=cmenuToRead.substr(thirdStar+1,fourthStar-1-thirdStar);
    CMenu *menu=new CMenu(name,command);

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
    if(true){
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
    }
    /*if(true){
        for(int i_i=0;i_i<menu.length() && menu[i_i]!=')';i_i++){
            if(menu[i_i]=='('){
                openingBrackets++;
            }

        }
        for(int i_i=0;i_i<menu.length();i_i++){
            if(menu[i_i]==')'){
                openingBrackets--;
            }
            if(openingBrackets==0){
                return i_i;
            }
        }
    } */
    return -1;

}


CMenu* CMenuCreater::createCMenuFromString(string path){
    //string start=path.substr(0,1);
    string start;
    string cmenuToRead=path.substr(1,path.find(";")-1);
    CMenu *cmenu=readCMenu(cmenuToRead);


    start=path.substr(path.find(";")+1,1);

    while(start!=")"){
        if(start=="["){

            string command=path.substr(path.find("[")+1,path.find("]")-1-path.find("["));
            cmenu->addMenu(readCMenuCommand(command));
            //string newPath;

            if(/*path.find("]")+1==","*/path.substr(path.find("]")+1,1)==","){   // path.substr(path.find("]")+1,1)==","
                    // CHYBA NIE MUSI BYC newPath=path.substr(path.find("]")+2,string::npos);
                    start=path.substr(path.find("]")+2,1);
                    if(start=="["){
                        // TRZEBA ZMIENIC PATH
                        path=path.substr(path.find("]")+2,string::npos);
                    }
            }else{
                    // CHYBA NIE MUSI BYC newPath=path.substr(path.find("]")+1,string::npos);
                    start=")";
                }
            //start=newPath.substr(newPath.find("]")+1,1);
            //path=newPath;
            /*if(start==","){
                    start=newPath.substr(newPath.find(")")+2,1);
                }*/
        }

        if(start=="("){

           // start=path.substr(path.find(";")+1,1);
                string newPath;
                if(path.substr(path.find(";")+1,1)=="["){
                    newPath=path.substr(path.find("(",1),string::npos);
                }else if(path.substr(path.find(";")+1,1)=="("){
                    newPath=path.substr(path.find(";")+1,string::npos);
                }
                //string newPath=path.substr(path.find(";")+1,string::npos);
                //cout<<newPath<<endl;
                /*if(path.substr(path.find(";")+1,1)=="," || path.substr(path.find(";")+1,1)==")" ){      //TU JEST CHYA niepotrzebne po ; zawsze jest nawias ( albo [
                    newPath=path.substr(path.find(";")+3,string::npos);
                }else{
                    newPath=path.substr(path.find(";")+1,string::npos);
                } */
                //string newPath=path.substr(path.find(";")+1,npos);
                cmenu->addMenu(createCMenuFromString(newPath));
                string pom="";

                if(newPath.substr(findPositionOfClosingBracket(newPath)-1,1)==")" /*&& findPositionOfClosingBracket(path)==findPositionOfClosingBracket(newPath)*/){   // I TO JEST TWOJE ZAMKNIECIE

                    if(findPositionOfClosingBracket(path)==findPositionOfClosingBracket(newPath)){ // JE¯ELI closery s¹ te same //  CO JEZELI S¥
                        start=newPath.substr(findPositionOfClosingBracket(newPath),1);
                    }else{

                        start=newPath.substr(findPositionOfClosingBracket(newPath)+1,1);
                        pom=newPath.substr(findPositionOfClosingBracket(newPath)+1,string::npos);
                    }
                    //start=newPath.substr(findPositionOfClosingBracket(newPath),1);


                }else{

                    start=newPath.substr(findPositionOfClosingBracket(newPath)+1,1);
                }

                //start=newPath.substr(findPositionOfClosingBracket(newPath)+1,1);   // TO TRZEBA Z IFOWAC
                //start=newPath.substr(newPath.find(")")+1,1);
                if(pom==""){
                    path=newPath;
                }else{
                    path=pom;
                }
                //path=newPath;
                /*if(start==")"){
                    int i=newPath.find(")");
                    while(newPath.find(")",i)!=-1 && newPath.substr(newPath.find(")",i),1)==")" ){
                        i++;
                    }
                }*/

                if(start==","){


                    start=newPath.substr(findPositionOfClosingBracket(newPath)+2,1);
                    if(newPath.substr(findPositionOfClosingBracket(newPath)+2,1)=="["){
                       /* if(path==pom){

                        }else{
                           path=newPath.substr(findPositionOfClosingBracket(newPath)+2,string::npos);
                        } */

                        path=newPath.substr(findPositionOfClosingBracket(newPath)+2,string::npos);
                    }
                    //path=newPath.substr(findPositionOfClosingBracket(pathToFindPosition)+2,string::npos);
                    //cmenu->addMenu(createCMenuFromString(path));
                }


        }


    }

    return cmenu;
}




