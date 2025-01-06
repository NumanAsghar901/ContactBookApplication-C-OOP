
#include "Address.h"
#include "Contact.h"
#include "ContactsBook.h"
//#include"HistoryObjects.h"
//#include"History.h"
#include"Group.h"
#include"list_of_groups.h"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

template<class T>
List_template<T>::List_template(int size)
{
	total_size = size;
	arr = new T[total_size];
	created_objects = 0;
}
template<class T>
List_template<T>::List_template()
{
	total_size = 5;
	arr = new T[total_size];
	created_objects = 0;
}
template<class T>
void List_template<T>::AddItem(T obj)
{
	if (this->full())
	{
		cout << "resizing list\n";
		this->resize_list();
		arr[created_objects] = obj;
		created_objects++;
		cout << "Item added successfully\n";
	}
	else
	{
		arr[created_objects] = obj;
		created_objects++;
		cout << "Item added successfully\n";
	}
}
template<class T>
void List_template<T>::resize_list()
{
	this->total_size += 2;
	T* temp = new T[total_size];

	for (int i = 0; i < created_objects; i++)
	{
		temp[i] = arr[i];
	}

	arr = temp;

}
template<class T>
bool List_template<T>::full()
{
	if (created_objects >= total_size)
	{
		return true;
	}
	else
		return false;
}
template<class T>
void List_template<T>::RemoveItem(int i)
{

}
template<class T>
void List_template<T>::setSize(int s)
{
 total_size=s;
}
template<class T>
T *List_template<T>::getArr()
{
	return arr;
}
template<class T>
T List_template<T>::getSize()
{
	return total_size;
}
template<class T>
List_template<T>::~List_template()
{
	delete arr;
     arr=NULL;
}