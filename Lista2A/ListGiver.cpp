#include "ListGiver.h"
#include "CTableHandler.h"
using namespace std;

ListGiver::ListGiver(CTableHandler &handler){
    this->handler=&handler;
}

int ListGiver::iGetAnyInt()
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
