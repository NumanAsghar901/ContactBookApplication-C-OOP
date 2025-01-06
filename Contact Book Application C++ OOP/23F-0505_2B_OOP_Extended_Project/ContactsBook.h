#pragma once
#include "Address.h"
#include "Contact.h"

//#ifndef BASIC_LIB
//#define BASIC_LIB
//#include <iostream>
//#include <string>
//#endif // !BASIC_LIB
#include<iostream>
#include<string>
using namespace std;
class ContactsBook {
protected:
	Contact *contacts_list; // array of contacts
	int size_of_contacts;   // storage limit
	int contacts_count;     // total contacts currently stored, next contact will be 
	// stored at this count plus 1 index

public:
	void add_contact( Contact& contact);
	int total_contacts()const;
	void view_contact(int i);
	Contact* getContactlist();
	void update_contact(int i);
	void delete_contact(int i);
	Contact* search_contact(std::string first_name, std::string last_name);
	Contact* search_contact(std::string phone);
	Contact* search_contact(const Address& address);
	//Contact* copyBook(Contact* c);
	ContactsBook(int size_of_list);
	ContactsBook();

	void print_contacts_sorted(std::string choice); // Only two choices first_name or last_name
	void merge_duplicates(); // Implement this function that finds and merges all the duplicates
							 // Duplicate means exact equal, this means if
	
	/* 
	*  This function loads contacts from the given file (see details in ContactsBook.cpp)
	*/
	int get_contacts_count()const;
	void load_from_file(std::string file_name);
	void save_to_file(std::string file_name);
	friend istream& operator>> (istream& in, ContactsBook& C);
	void print_contacts();
	~ContactsBook();
	void Allsearch_contact(string str)const;
	void searchNow(string str)const;
	bool isMatch(const Contact& c, const string& query)const;
	void search(const std::string& query);
	void Allsearch_Now(const string& str) const;
private:
	bool full();
	void resize_list();
	Contact *sort_contacts_list(Contact *contacts_list,string choice);
	//Contact* CopyContacts_list();
};
