#include "CTable.h"
#include "iostream"
#include <iostream>
#include "sstream"

using namespace std;



CTable::CTable():I_DEFAULT_SIZE(10), S_DEFAULT_NAME("default") {
	i_size = I_DEFAULT_SIZE;
	pi_table = new int[i_size];
	initializeWithZeros(0, i_size);
	s_name = S_DEFAULT_NAME;
	//string s_1="bezp: "^s_name;								//KONSTRUKTOR DOMYŒLNY
	cout << "bezp: "+s_name<< endl;
}

CTable::CTable(string sName, int iTableLen):I_DEFAULT_SIZE(10), S_DEFAULT_NAME("default") {
	i_size = iTableLen;
	s_name = sName;								//KONSTRUKTOR PARAMETRYZOWANY
	pi_table = new int[i_size];
	cout << "parametr: ";

	cout << sName<<endl;

}

CTable::CTable(const CTable &pcOther,int extend_by):I_DEFAULT_SIZE(10), S_DEFAULT_NAME("default"){
    s_name=pcOther.s_name;
    i_size=pcOther.i_size+extend_by;
    pi_table=new int[i_size+extend_by];

    for(int i_i=0;i_i<i_size;i_i++){
        if(i_i>=pcOther.i_size){
            *(pi_table+i_i)=0;
        }else{
         *(pi_table+i_i)=*(pcOther.pi_table+i_i);
        }
    }


}       //DODANE

CTable::CTable(const CTable &pcOther):I_DEFAULT_SIZE(10), S_DEFAULT_NAME("default") {
	s_name = pcOther.s_name;
	i_size = pcOther.i_size;					// KONSTRUKTOR KOPIUJ¥CY
	pi_table = new int[i_size];
	for(int i=0;i<i_size;i++){
        *(pi_table+i)=*(pcOther.pi_table+i);
	}
	//*pi_table = *(pcOther.pi_table);

	cout << "kopiuj: ";
	cout << s_name<<endl;
}

CTable::~CTable() {

	delete[] pi_table;
	cout<<endl;
	cout << "usuwam: ";
	cout << s_name<<endl;

	//DEKONSTRUKTOR Jeszcze do implementacji
}

void CTable::setName(string sName) {
	s_name = sName;
}//void CTable1::setName(string sName)

void CTable::changeLength(int newLength) {
    if(newLength>=0){
        int *pi_table_new;
        pi_table_new = new int[newLength];
        for (int ii = 0; (ii < i_size) && (ii < newLength); ii++)
        {
            pi_table_new[ii] = pi_table[ii];

        }
        setSize(newLength);
        delete[] pi_table;
        pi_table = pi_table_new;
    }else{
        cout<<"Zla Dlugosc podana"<<endl;
    }


	//Musze jeszcze zmieniæ adres komórki ????? Chyba nie, bo przypisa³em wskaŸnikowi globalnemu now¹ wartoœæ i usun¹³em star¹ wartoœæ

}//void CTable1::changeLength(int newLength)

void CTable::add(int position, int newValue) {
	if (position >= i_size || position<0) {
		cout << "Zla pozycja" << endl;
	}
	else {
		pi_table[position] = newValue;
	}

}//void CTable1::add(int position, int newValue)

void CTable::printObjectFromTable(int position) {
	if (position >= i_size || position<0) {
		cout << "Zla pozycja" << endl;
	}
	else {
		cout << pi_table[position] << endl;
	}

}//void CTable1::printObjectFromTable(int position)


CTable CTable::copyObject(CTable &original) {

	return CTable(original);
}//CTable1 CTable1::copyObject(CTable1 original)

CTable *CTable::copyObject2(){
    return new CTable(*this);
}

void CTable::copyTable(CTable &object) {
	delete[] pi_table;
	pi_table = object.pi_table;
}//void CTable1::copyTable(CTable1 object)


string CTable::toString() {


    stringstream ss;
    ss<<i_size;

        // TRZEBA KONWERTOWAĆ INTA DO STRINGA


	string description = s_name + " len: ";
	description +=ss.str()+" ";
	description += " values: [";
	for (int ii = 0; ii < i_size; ii++) {
	    stringstream ss1;
        ss1<<pi_table[ii];
		description += ss1.str();
        if(ii<i_size-1){
            description += ",";
        }

	}
	description += "]";
    cout<<description<<endl;
	return description;
}//string CTable1::toString()



void CTable::initializeWithZeros(int start, int end) {

	if (start >= 0 && start < end) {
		for (int ii = start; ii < end; ii++) {
			pi_table[ii] = 0;
		}

	}

}//void CTable1::initializeWithZeros(int start, int end)


string CTable::getName() {
	return s_name;
}//string CTable1::getName()

int CTable::getSize() {
	return i_size;
}//int CTable1::getSize()

void CTable::showName() {
	cout << s_name;
}

void CTable::setSize(int iSize){
    i_size=iSize;
}


CTable *CTable::copyAndExtend(int i_newSize){      //TUTUTUTUTUTUT
    return new CTable(*this,i_newSize);
}

