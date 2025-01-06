#pragma once
using namespace std;
#include<string>
#include<iostream>
#include "Contact.h"
#include "ContactsBook.h"
#include"HistoryObjects.h"
#include"History.h"
#include<iostream>
#include<string>
template<typename T>
class List_template
{
public:
	List_template(int size);
	List_template();
	~List_template();
	bool full();
	void resize_list();
	void AddItem(T obj);
	void RemoveItem(int i);
	 T getSize();
	T* getArr();
	void setSize(int s);

	T *arr;
	int total_size;
	int created_objects;
};


