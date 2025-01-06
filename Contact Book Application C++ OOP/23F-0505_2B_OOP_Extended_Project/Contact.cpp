#include "Contact.h"
#include<string>
#include<iostream>
#include"Address.h"
using namespace std;
Contact::Contact(string first_name, string last_name,
	string mobile_number,
	string email_address, Address* address, int u) :
	first_name(first_name),
	last_name(last_name),
	mobile_number(mobile_number),
	email_address(email_address),
	address(address)
{
	
	//id = u;
	search_count = 0;
}
Contact::~Contact() {
	address = NULL;
	
}
void Contact::setFirst_name(string f)
{
	first_name = f;
}void Contact::setId(int i)
{
	id = i;
}
void Contact::setLast_name(string l)
{
	last_name = l;

}
void Contact::setMobile_number(string m)
{
	mobile_number = m;
	while (mobile_number.size()!=11&&mobile_number[0]!='0')
	{
		cout << "enter 11 digit phone number: \n";
		cin >> mobile_number;
	}
}
void Contact::setEmail_address(string e)
{
	
	email_address = e;
}void Contact::setSearchcount(int i)
{
	
	search_count = i;
}
void Contact::setAddress(Address *a)
{
	address = a;
}
//getters
int Contact::getId()const
{
	return id;
}int Contact::getSearchCount()const
{
	return search_count;
}
string Contact::getFirstName()const
{
	return first_name;
}

string Contact::getLastName()const
{
	return last_name;
}string Contact::getMobileNumber()const
{
	return mobile_number;
}string Contact::getEmailAddress()const
{
	return email_address;
}
Address *Contact::getAddress()const
{
	return address;
}
ostream& operator<< (ostream& out,const Contact& c)//cout overlaod
{
	out <<c.getId()<<" " << c.getFirstName() << " " << c.getLastName() << " "
		<< c.getMobileNumber() << " " << c.getEmailAddress() << endl;
	Address* ptr = c.getAddress();
	out << ptr->gethouse() << " " << ptr->getstreet() <<" "
		<< ptr->getcity() <<" " << ptr->getcountry() << endl<<endl;
	return out;
}
istream& operator>> (istream& in, Contact& C)//cin overload
{
	string a, b, c, d;
	cout << "Enter First Name: \n";
	in >> a;
	//string a = "o";
	C.setFirst_name(a);
	cout << "Enter Last Name: \n";
	in >> a;
	C.setLast_name(a);
	cout << "Enter Mobile Number:  \n";
	in >> a;
	C.setMobile_number(a);
	cout << "Enter Email: \n";
	in >> a;
	C.setEmail_address(a);
	C.address = new Address;
	Address* ptr = C.getAddress();
	cout << "Enter house No: \n";
	in >> a;
	ptr->sethouse(a);
	cout << "Enter street name: \n";
	in >> a;
	ptr->setstreet(a);
	cout << "Enter city Name: \n";
	in >> a;
	ptr->setcity(a);
	cout << "Enter Country Name: \n";
	in >> a;
	ptr->setcountry(a);
	
	return in;
}
bool Contact::equals(Contact &contact)const
{
	if (contact.first_name == this->first_name && 
		contact.last_name == this->last_name && contact.address == this->address
		&& contact.email_address == this->email_address &&
		contact.mobile_number == this->mobile_number &&
		this->address->equals(*contact.address))
		return true;
	else
		return false;
}
void Contact::removeEquals()
{
	this->first_name ="";
	this->last_name = "";
	this->address = NULL;
	this->email_address = "";
	this->mobile_number = "";
		
}
Contact* Contact::copy_contact()
{
	Contact *C1=new Contact;
	C1->first_name=this->first_name;
	C1->last_name = this->last_name;
	C1->mobile_number = this->mobile_number;
	C1->email_address = this->email_address;
	C1->id = this->id;
	C1->search_count = this->search_count;
	C1->address = new Address;
	C1->address = address;
	return C1;
}
