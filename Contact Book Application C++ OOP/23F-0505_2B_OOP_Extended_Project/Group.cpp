#include<iostream>
#include<string>
#include"Group.h"
#include"ContactsBook.h"
#include"List.h"
using namespace std;
Group::Group(int size,string n)
{
	
	total = size;
	count_contacts = 0;
	name = n;

}
Group::Group()
{
}
void Group::view_grp( ContactsBook& obj2)
{
	cout << "Group Name: " << name << endl;
	cout << "  Contacts in Group: " << count_contacts << endl;
	for (int i = 0; i < count_contacts; i++)
	{
		if (Ids[i] < 0)
			continue;
		obj2.view_contact(Ids[i]);
	}
}
//ostream& operator<<(ostream& out, Group &obj)
//{
//	out << "Group Name: " << obj.name<<endl;
//	out << "Contacts in Group: " << obj.count_contacts << endl;
//	return out;
//}
//bool Group::full()
//{
//	
//	if (count_contacts >= total)
//	{
//		return true;
//	}
//	else
//		return false;
//}
//void Group::resize()
//{
//	total += 2;
//	int* temp = new int[total];
//
//	for (int i = 0; i < count_contacts; i++)
//	{
//		temp[i] = Ids[i];
//	}
//	delete[]Ids; 
//     Ids = temp;
//}
void Group::addcontact(int i)
{
	
	{
		this->Ids[count_contacts] = i;
		this->count_contacts++;
		cout << "contact added to the group\n";
	}
	
}
void Group::removecontact(int j)
{
	if (count_contacts > 0)
	{
		Ids[j] = -1;
		
		count_contacts--;
		cout << "contact removed from grp successfully\n";
	}
	else
		cout << "you cannot remove contact from grp\n";

}
 istream& operator>>(istream& in, Group &obj)
{
	 
	 int s;
	 string name;
	 cout << "enter grp size\n";
	 in >> s;
	 cout << "enter Group name\n";
	 in >> name;
	 obj.setName(name);
	 obj.setCount(s);
	 return in;
}
int* Group::getID()
{
	return Ids;
}
void Group::setName(string n)
{
	name = n;
}
void Group::setCount(int c)
{
	total = c;
}
int Group::getCount()
{
	return count_contacts;
}
string Group::getName()
{
	return name;
}

ostream& operator<<(ostream& out, Group& obj)
{
	out <<"Group Name: " << obj.name << endl;
	out << "  Contacts in Group: " << obj.count_contacts << endl;
	for (int i = 0; i < obj.count_contacts; i++)
	{
		if (obj.Ids[i] < 0)
			continue;
		out<<"Contact ID: " << obj.Ids[i]<<" is present in group\n";
	}
	return out;
}
Group::~Group
()
{
}