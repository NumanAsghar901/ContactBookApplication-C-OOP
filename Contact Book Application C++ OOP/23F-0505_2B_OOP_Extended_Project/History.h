#pragma once
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class History
{
public:
	
	//History() ;
	//History* copy_history();
	History(string o="", string t="", int i=0);
	void set_data(string a);
	string get_data();
	int get_index();
	friend ostream& operator<<(ostream& out, History& obj);
protected:
	string date_time;
	string data;
	int index;
};
