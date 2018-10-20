#pragma once
#include <iostream>
#include "sstream"

using namespace std;
class CTable
{
public:
	//Konstruktor

	CTable();
	CTable(string sName, int iTableLen);
	CTable(const CTable &pcOther);
    CTable(const CTable &pcOther,int extend_by);
	//Destruktor
	~CTable();


	//Metody



	void changeLength(int newLength);
	void add(int position, int newValue);
	void printObjectFromTable(int position);
	CTable copyObject(CTable &original);
	void copyTable(CTable &object);
	string toString();
	void initializeWithZeros(int start, int end);
	CTable *copyObject2();

	void showName();


	CTable *copyAndExtend(int i_newSize);

	//Gettery i settery
	int getSize();
	string getName();
    void setName(string sName);
	void setSize(int iSize);

private:

    //Constants
    const int I_DEFAULT_SIZE;
    const string S_DEFAULT_NAME;

    //Variables
	int i_size;
    string s_name;
	int *pi_table;
};
