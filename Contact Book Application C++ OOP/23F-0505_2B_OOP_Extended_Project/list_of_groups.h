#pragma once
#include<iostream>
#include<string>
#include"Group.h"
#include"ContactsBook.h"
#include"List.h"
using namespace std;
class groupsList:public ContactsBook
{
public:
	groupsList(int size);
	~groupsList();
	void resizeList();
	bool full();
	void remove(int i, int c);
	void setGrpName(string name);
	void addgroup(Group &obj);
	void add(int i,int c);
	void view( ContactsBook& obj2);
	void check(int id);
	void delete_grp(int j);
	void save_to_file(string file_name);
	int getgrpcount();
private:
	Group* list;
	int total_size;
	int countgrp;
	//List_template<Group>list_obj;
};

