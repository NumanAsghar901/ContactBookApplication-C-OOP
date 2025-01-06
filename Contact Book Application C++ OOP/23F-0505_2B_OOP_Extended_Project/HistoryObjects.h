#pragma once
#include"History.h"
#include<iostream>
#include"List.h"
#include<fstream>
#include<string>
using namespace std;
class HistoryObjects:public History
{
public:
	HistoryObjects(int s);
	HistoryObjects();
	~HistoryObjects();
	void getTop5(string file_name,ContactsBook& obj);
	void savetop5_to_file(string file_name, int* ids, int count, ContactsBook& obj);
	void Addhistory(History &obj);
	void resize_history();
	void PrintReverse();
	bool historyfull();
	void save_to_file(string file_name);
private:
	int total_obj;
	int obj_count; 
	History* arr;
	 int top5[5];
	
};

