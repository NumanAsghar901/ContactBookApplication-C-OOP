#include "ContactsBook.h"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
void ContactsBook::add_contact(Contact& contact)
{
	if (this->full())
	{
		contact.setId(contacts_count+1);
		cout << "resizing contact list\n";
		this->resize_list(); 
		contacts_list[contacts_count] = contact;
		contacts_count++; 
		cout << "contact added successfully\n";
	}
	else
	{
		contact.setId(contacts_count+1);
		contacts_list[contacts_count] = contact;
		contacts_count++;
		cout << "contact added successfully\n";
	}
}
void ContactsBook::view_contact(int i)
{
	cout << contacts_list[i];
}
void ContactsBook::update_contact(int i)
{
	cin >> contacts_list[i];
	cout << "contact updated successfully\n";
}
void ContactsBook::delete_contact(int j)
{
	int k = 0;
	Contact* temp = new Contact[size_of_contacts];
	for (int i = 0; i < contacts_count; i++)
	{
		if (i == j)
			continue;
		temp[k] = *(contacts_list[i].copy_contact()); k++;
	}
	delete[]contacts_list;
	contacts_list = temp;
	contacts_count--;
	cout << "contact deleted successfully\n";
}
int ContactsBook::total_contacts()const
{
	return contacts_count;
}

bool ContactsBook::full()
{
	if (contacts_count >= size_of_contacts)
	{
		return true;
	}
	else
		return false;
}

void ContactsBook::resize_list()
{
	this->size_of_contacts += 2;
	Contact* temp = new Contact[size_of_contacts];

	for (int i = 0; i < contacts_count; i++)
	{
		temp[i] = *(contacts_list[i].copy_contact());
	}
	delete[]contacts_list; contacts_list = NULL;
	contacts_list = temp;

}
void ContactsBook::Allsearch_contact(string str)const
{
	bool found = false;
	cout << "Contacts that match the given string \n";
	for (int i = 0; i < contacts_count; i++)
	{
		Address* A = (contacts_list[i].getAddress());

		if (contacts_list[i].getMobileNumber() == str || contacts_list[i].getEmailAddress() == str ||
			contacts_list[i].getFirstName() == str ||contacts_list[i].getLastName()==str || A->gethouse() == str || A->getcity() == str
			|| A->getstreet() == str || A->getcountry() == str)

		{
			cout << contacts_list[i]; found = true; 
			contacts_list[i].setSearchcount(contacts_list[i].getSearchCount() + 1);
		}
	}
	if (found == false)
		cout << "no exact match found\n";
}
void ContactsBook::Allsearch_Now(const string& str) const
{
	bool found = false;
	cout << "Contacts that match the given string:\n";
	for (int i = 0; i < contacts_count; i++) {
		if (isMatch(contacts_list[i], str))
		{
			cout << contacts_list[i];
			found = true; 
			contacts_list[i].setSearchcount(contacts_list[i].getSearchCount()+1);
		}
	}
	if (!found)
		cout << "No exact match found\n";
}
bool ContactsBook::isMatch(const Contact& contact, const string& query) const
{
	int contact_index = 0;
	int query_index = 0;
	while (contact_index < contact.getFirstName().size()) {
		if (contact.getFirstName()[contact_index] == query[query_index])
		{
			query_index++;
			if (query_index == query.size())
				return true; 
		}
		else 
		{
			query_index = 0;
		}
		contact_index++;
	}

	contact_index = 0;
	while (contact_index < contact.getLastName().size()) {
		if (contact.getLastName()[contact_index] == query[query_index]) {
			query_index++;
			if (query_index == query.size())
				return true;
		}
		else {
			query_index = 0;
		}
		contact_index++;
	}

	contact_index = 0;
	while (contact_index < contact.getMobileNumber().size()) {
		if (contact.getMobileNumber()[contact_index] == query[query_index]) {
			query_index++;
			if (query_index == query.size())
				return true;
		}
		else {
			query_index = 0;
		}
		contact_index++;
	}

	contact_index = 0;
	while (contact_index < contact.getEmailAddress().size()) {
		if (contact.getEmailAddress()[contact_index] == query[query_index]) {
			query_index++;
			if (query_index == query.size())
				return true;
		}
		else {
			query_index = 0;
		}
		contact_index++;
	}

	Address* addr = contact.getAddress();
	contact_index = 0;
	while (contact_index < addr->gethouse().size()) {
		if (addr->gethouse()[contact_index] == query[query_index]) {
			query_index++;
			if (query_index == query.size())
				return true;
		}
		else {
			query_index = 0;
		}
		contact_index++;
	}

	contact_index = 0;
	while (contact_index < addr->getstreet().size()) {
		if (addr->getstreet()[contact_index] == query[query_index]) {
			query_index++;
			if (query_index == query.size())
				return true;
		}
		else {
			query_index = 0;
		}
		contact_index++;
	}

	contact_index = 0;
	while (contact_index < addr->getcity().size()) {
		if (addr->getcity()[contact_index] == query[query_index]) {
			query_index++;
			if (query_index == query.size())
				return true;
		}
		else {
			query_index = 0;
		}
		contact_index++;
	}

	contact_index = 0;
	while (contact_index < addr->getcountry().size()) {
		if (addr->getcountry()[contact_index] == query[query_index]) {
			query_index++;
			if (query_index == query.size())
				return true;
		}
		else {
			query_index = 0;
		}
		contact_index++;
	}

	return false;
}


Contact* ContactsBook::search_contact(string first_name, string last_name)
{
	Contact* ptr = NULL;
	for (int i = 0; i < contacts_count; i++)
	{
		if (contacts_list[i].getFirstName() == first_name &&
			contacts_list[i].getLastName() == last_name)
		{
			contacts_list[i].setSearchcount(contacts_list[i].getSearchCount() + 1); 
			ptr = contacts_list[i].copy_contact();
			break;
		}
	}
	return ptr;
}

Contact* ContactsBook::search_contact(string phone)
{
	Contact* ptr = NULL;
	for (int i = 0; i < contacts_count; i++)
	{
		if (contacts_list[i].getMobileNumber() == phone)
		{
			contacts_list[i].setSearchcount(contacts_list[i].getSearchCount()+ 1);
			ptr = contacts_list[i].copy_contact();
			break;
		}
	}
	
   return ptr;
}
int ContactsBook::get_contacts_count()const
{
	return contacts_count;
}
Contact* ContactsBook::search_contact(const Address& address)
{
	Contact* ptr = NULL; bool found = false;
	for (int i = 0; i < size_of_contacts && found == false; i++)
	{
		Address* A = contacts_list[i].getAddress();
		if (A->equals(address))
		{
			contacts_list[i].setSearchcount(contacts_list[i].getSearchCount() + 1);
			ptr = contacts_list[i].copy_contact();
			break;
		}
	}
	return ptr;
}
ContactsBook::ContactsBook() :contacts_count(0), size_of_contacts(0), contacts_list(NULL) {}
ContactsBook::ContactsBook(int size_of_list)
{
	contacts_list = new Contact[size_of_list];
	contacts_count = 0;
	size_of_contacts = size_of_list;
}
ContactsBook::~ContactsBook()
{
	delete[] contacts_list;
	contacts_list = NULL;
}
void ContactsBook::print_contacts_sorted(string choice)
{
	Contact* temp = new Contact[size_of_contacts];
	temp = sort_contacts_list(temp, choice);

	for (int i = 0; i < contacts_count; i++)
	{
		cout << temp[i] << endl;
	}

}

Contact* ContactsBook::sort_contacts_list(Contact* temp_list, string choice)
{
	if (choice == "f" || choice == "F") {

		int upper = 97, lower = 65; int count = 0;
		int size_of_abc = 26;
		for (int i = 0; i < size_of_abc; i++)
		{
			for (int k = 0; k < size_of_contacts; k++)
			{
				string temp = contacts_list[k].getFirstName();
				if (temp[0] == upper || temp[0] == lower)
				{
					temp_list[count] = *(contacts_list[k].copy_contact());
					count++;
				}
			}
			upper++; lower++;
		}
		return temp_list;
	}
	else if (choice == "l" || choice == "L")
	{
		int upper = 97, lower = 65; int j = 0;
		int size_of_abc = 26;
		for (int i = 0; i < size_of_abc; i++)
		{
			for (int k = 0; k < size_of_contacts; k++)
			{
				string temp = contacts_list[k].getLastName();
				if (temp[0] == upper || temp[0] == lower)
				{
					temp_list[j] = *(contacts_list[k].copy_contact());
					j++;
				}
			}
			upper++; lower++;
		}
		return temp_list;
	}
	else
	{
		cout << "wrong choice entered\n";
		return contacts_list;
	}
}

void ContactsBook::merge_duplicates()
{
	int count = 0, l = 0;
	for (int i = 0; i < contacts_count; i++)
	{
		for (int j = 1; j < contacts_count; j++)
		{
			if (contacts_list[i].equals(contacts_list[j]))
			{
				contacts_list[j].removeEquals();
				count++;
				Contact* temp = new Contact[size_of_contacts - 1];
				for (int k = 0; k < size_of_contacts; k++)
				{
					if (j != k)
					{
						temp[l] = *(contacts_list[k].copy_contact()); l++;
						//temp[l].setId(l);
					}
				}
				delete[]contacts_list;
				contacts_list = temp;
				contacts_count--; 
				size_of_contacts--;
			}
		}
	}
	cout << count << " contacts merged successfully\n";

}

void ContactsBook::load_from_file(string file_name)
{
	ifstream read(file_name);
	if (!read)
	{
		cout << "file not opened";
	}
	else
	{
		int count;
		read >> count;

		for (int i = 0; i < count; i++)
		{
			string temp; Contact c; Address* a = new Address;
			read >> temp;
			c.setFirst_name(temp);
			read >> temp;
			c.setLast_name(temp);
			read >> temp;
			c.setMobile_number(temp);
			read >> temp;
			c.setEmail_address(temp);
			read >> temp;
			a->sethouse(temp);
			read >> temp;
			a->setstreet(temp);
			read >> temp;
			a->setcity(temp);
			read >> temp;
			a->setcountry(temp);
			c.setAddress(a);

			add_contact(c);
		}
		cout << "data loaded from file successfully\n";
	}

}

Contact* ContactsBook::getContactlist()
{
	return contacts_list;
}
void ContactsBook::save_to_file(string file_name)
{
	ofstream write(file_name);
	if (!write)
	{
		cout << "file not opened\n";
	}
	else
	{
		write << contacts_count << endl;
		for (int i = 0; i < contacts_count; i++)
		{
			write << contacts_list[i];
		}
		write.close();
		cout << "data written successfully.Go check the file\n";
	}

}

void ContactsBook::print_contacts()
{
	if (contacts_count == 0)
	{
		cout << "No contacts added, plz add contacts first\n";
	}
	for (int i = 0; i < contacts_count; i++)
	{
		
		cout << contacts_list[i];
	}

}