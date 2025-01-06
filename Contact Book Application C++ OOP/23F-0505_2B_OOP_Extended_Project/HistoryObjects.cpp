#include"History.h"
#include"HistoryObjects.h"
#include<iostream>
using namespace std;
HistoryObjects::HistoryObjects() :obj_count(0), total_obj(0)
{
	arr = NULL; 

}
HistoryObjects::HistoryObjects(int s)

{
	

	arr = new History[s];
	total_obj = s;
	obj_count = 0;
}
void HistoryObjects::PrintReverse()
{
	for (int i = obj_count - 1; i >= 0; i--)
	{
		cout << arr[i];
	}
}
void HistoryObjects::getTop5(string file_name,ContactsBook &obj)
{
	int max_size = obj.get_contacts_count();
	int* ids = new int[max_size];
	int* count = new int[max_size];
	int count_searched=0;
	    for (int j = 0; j < max_size; j++)
		{
			if (obj.getContactlist()[j].getSearchCount() != 0)
			{
				count[count_searched] = obj.getContactlist()[j].getSearchCount();
				ids[count_searched] = obj.getContactlist()[j].getId();
				count_searched++;
			}
		}
		for (int i = 0; i < count_searched; i++) //bubble sort
		{
			for (int j = 0; j < count_searched -i- 1; j++) 
			{
				if (count[j] < count[j + 1])
				{
					swap(count[j], count[j + 1]);
					swap(ids[j], ids[j + 1]);
				}
			}
		}
		delete[]count;
		cout << "Most FrequentLy searched contacts\n";
		if (count_searched > 5)
		{
			for (int i = 0; i < 5; i++)
			{
				obj.view_contact(ids[i]-1);
			}
		}
		else
		{
			for (int i = 0; i < count_searched; i++)
			{
				obj.view_contact(ids[i]-1);
			}
		}
		savetop5_to_file(file_name,ids,count_searched, obj);
	

}
void HistoryObjects::savetop5_to_file(string file_name,int* ids,int count,ContactsBook& obj)
{
	ofstream write(file_name);
	if (!write)
	{
		cout << "file not opened\n";
	}
	else
	{
		write << "Most Frequently Searched Contacts: " << endl;
		for (int i = 0; i < count; i++)
		{
			write << obj.getContactlist()[ids[i]-1];
		}
		write.close();
		cout << "data written successfully.Go check the file\n";
	}

}
void HistoryObjects::Addhistory(History &obj)
{

	if (this->historyfull())
	{
		if (obj.get_index())
			cout << "resizing list\n";
		this->resize_history();
		arr[obj_count] = obj;
		obj_count++;
		cout << "History added successfully\n";
	}
	else
	{
		arr[obj_count] = obj;
		obj_count++;
		cout << "history added successfully\n";
	}
}
bool HistoryObjects::historyfull()
{
	if (obj_count >= total_obj)
	{
		return true;
	}
	else
		return false;
}
void HistoryObjects::resize_history()
{
	this->total_obj += 2;
	History* temp = new History[total_obj];

	for (int i = 0; i < obj_count; i++)
	{
		temp[i] = (arr[i]);
	}
	arr = temp;

}
void HistoryObjects::save_to_file(string file_name)
{
	ofstream write(file_name);
	if (!write)
	{
		cout << "file not opened\n";
	}
	else
	{
		write<<"history count: " << obj_count << endl;
		for (int i = 0; i < obj_count; i++)
		{
			write << arr[i];
		}
		write.close();
		cout << "data written successfully.Go check the file\n";
	}

}
HistoryObjects::~HistoryObjects()
{
	delete[] arr;
	arr = NULL;
}