#include<iostream>
#include<string>
#include"Group.h"
#include"list_of_groups.h"
#include"List.h"
#include"ContactsBook.h"
using namespace std;
groupsList::groupsList(int size)
{
	list = new Group[size];
	total_size = size;
	countgrp = 0;
}
void groupsList::add(int i, int id)
{
	list[i].addcontact(id);
}
int groupsList::getgrpcount()
{
	return countgrp;
}
void groupsList::check(int id)
{
	bool found = false;
	for (int i = 0; i < countgrp; i++)
	{
		int* ptr = list[i].getID();
		for (int j = 0; j < list[i].getCount(); j++)
		{
			if (ptr[j] == id)
			{	cout << "contact is in the group: " << i + 1 << endl; found = true;
		    }
		}
	}
	if (found == false)
		cout << "contact is not in any group\n";
}
void groupsList::remove(int i, int id)
{
	if (i <= countgrp)
	{
		list[i].removecontact(id);
	}
	else
		cout << "grp do no exist\n";
}
void groupsList::resizeList()
{
	total_size *= 2;
	Group* temp = new Group[total_size];

	for (int i = 0; i < countgrp; i++)
	{
		temp[i] = list[i];
	}
	list = temp;
}
bool groupsList::full()
{
	if (countgrp >= total_size)
	{
		return true;
	}
	else
		return false;
}
void groupsList::addgroup(Group& obj)
{
	if (full())
	{
		resizeList();
		list[countgrp] = obj;
		countgrp++;
		cout << "grp added\n";
	}
	else
	{
		list[countgrp] = obj;
		countgrp++;
	}
	cout << "grp added\n";
}
// ostream& operator<<(ostream& out, groupsList &obj)
//{
//	 if (obj.countgrp == 0)
//	 {
//		 cout << "no grp created yet, create grps first\n";
//	 }
//	 for (int i = 0; i < obj.countgrp; i++)
//	 {
//
//		 obj.list[i].view_grp()
//		// out<<i+1 <<" " << obj.list[i];
//	 }
//	 return out;
//} 
void groupsList::view(ContactsBook& obj2)
{
	if (countgrp == 0)
	{
		cout << "no grp created yet, create grps first\n";
	}
	for (int i = 0; i < countgrp; i++)
	{
		cout << i + 1 << ".";
		list[i].view_grp(obj2);
		// out<<i+1 <<" " << obj.list[i];
	}
}
void groupsList::delete_grp(int j)
{
	if (countgrp != 0)
	{
		Group* temp = new Group[total_size - 1]; int k = 0;
		for (int i = 0; i < countgrp; i++)
		{
			if (i == j)
				continue;
			temp[k] = list[i]; k++;
		}
	
		list = temp;
		countgrp--;
		cout << "grp deleted successfully\n";
	}
	else
		cout << "you cannot delete grp before adding\n";

}
void groupsList::save_to_file(string file_name)
{
	ofstream write(file_name);
	if (!write)
	{
		cout << "file not opened\n";
	}
	else
	{
		write << "Group members" << countgrp << endl;
		for (int i = 0; i < countgrp; i++)
		{
		
			write << list[i];
		}
		write.close();
		cout << "data of group written successfully.Go check the file\n";
	}

}
groupsList::~groupsList()
{
	delete[]list; list = NULL;
}