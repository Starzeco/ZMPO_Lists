#include "MenuSearch.h"
#include "CMenuCommand.h"

using namespace std;



void MenuSearch::searchForPath(CMenu *current,string &commandName,string path){
    //cout<<commandName<<endl;
    if(!current){
        current=cmenu;

    }
    if(current!=cmenu){
            path+=" -> ";
        }
    path+=current->getCommand();
    vector<CMenuItem *> menuItems=current->getList();
    for(int i_i=0;i_i<menuItems.size();i_i++){
      /*  if(dynamic_cast<CMenuCommand *>(menuItems[i_i]) && commandName==menuItems[i_i]->getCommand()){
            cout<<path<<"->"<<commandName<<endl;
        }else if(dynamic_cast<CMenu *>(menuItems[i_i]) && commandName==menuItems[i_i]->getCommand()){
            cout<<path<<"->"<<commandName<<endl;
        }else{
            path +="->";
            path +=menuItems[i_i]->getCommand();
            searchForPath(dynamic_cast<CMenu *>(menuItems[i_i]),commandName,path);
        }*/


        if(menuItems[i_i]->getCommand()==commandName){
            cout<<path<<" -> "<<menuItems[i_i]->getCommand()<<endl;
        }
        if(CMenu *next=dynamic_cast<CMenu *>(menuItems[i_i])){
            searchForPath(next,commandName,path);
        }

    }

}




void MenuSearch::setCMenu(CMenu &cmenuGiven){
    cmenu=&cmenuGiven;

}
