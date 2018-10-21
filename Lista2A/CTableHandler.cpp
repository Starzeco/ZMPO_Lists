#include <iostream>
#include "sstream"
#include <vector>
#include "CTableHandler.h"

using namespace std;

vector<CTable*> CTableHandler::list;

/*CTableHandler::~CTableHandler(){
    for(int i=0;i<list.size();i++){
        delete list[i];
    }

    list.clear();
    cout<<"Usuwam CTable liste"<<endl;
} */


int CTableHandler::iGetAnyInt()
{
    //std::cout << "Wprowadz inta: ";

    int response;
    bool properInteger;
    do {
        std::string string;
        std::stringstream stream;
        std::getline(std::cin, string);
        stream << string;
        properInteger = (bool) (stream >> response);
    } while (!properInteger);

    return response;
}

void CTableHandler::clean(){
    for(int i=0;i<list.size();i++){
        delete list[i];
    }

    list.clear();
    cout<<"Usuwam CTable liste"<<endl;
}

