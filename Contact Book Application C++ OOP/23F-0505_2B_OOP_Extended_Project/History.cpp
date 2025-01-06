#include"History.h"
#include<string>
#include<iostream>
using namespace std;

History::History(string o, string d,int i):date_time(o), data(d),index(i)
{
}
ostream & operator<<(ostream& out, History& obj)
{
	
	out <<"Contact Id: " << obj.index << obj.data << " " << obj.date_time << " \n";
	return out;
}
void History::set_data(string a)
{
	data = a;
}
string History::get_data()
{
	return data;
}int History::get_index()
{
	return index;
}