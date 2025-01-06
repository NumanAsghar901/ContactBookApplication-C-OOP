#pragma once
#include<iostream>
#include<string>
#include"ContactsBook.h"
#include"List.h"
using namespace std;
class Group:public ContactsBook
{
public:
	Group(int size,string n);
	Group();
	~Group();
	int* getID();
	void setName(string n);
	void setCount(int c);
	int getCount();
	string getName();
	bool full();
	void resize();
	void addcontact(int i);
	void removecontact(int i);
	void view_grp(ContactsBook& obj2);
	friend ostream& operator<<(ostream& out, Group& obj);
	friend istream& operator>>(istream& out, Group &obj);
	
protected:
	int Ids[100];
	int count_contacts;
	int total;
	string name;
};

