#include "Address.h"
#include<string>
#include<iostream>
using namespace std;
//constructors
Address::Address(std::string house, std::string street, std::string city, std::string country)
{
	this->house = house;
	this->city = city;
	this->country = country;
	this->street = street;
	
}
Address::Address():house("0"),street("0"),city("0"),country("0")
{
	
}
istream& operator>> (istream& in, Address& a)
{
	string h, c, co, s;
	cout << "Enter your house No: \n";
	in >> h;
	a.sethouse(h);
	cout << "Enter your Street No: \n";
	in >> s;
	a.setstreet(s);
	cout << "Enter your City: \n";
	in >> c;
	a.setcity(c);
	cout << "Enter your Country: \n";
	in >> co;
	a.setcountry(co);
	return in;
}

/*
*	Implement getter/setters for all the member variables of Address. Also declare them in the Address.h header file
*
*/
void Address::sethouse(string h)
{
	house = h;
}
void Address::setcity(string c)
{
	city = c;
}void Address::setcountry(string c)
{
	country = c;
}void Address::setstreet(string s)
{
	street = s;
}
string Address::gethouse()const
{
	return house;
}string Address::getcity()const
{
	return city;
}string Address::getcountry()const
{
	return country;
}string Address::getstreet()const
{
	return street;
}

/*
*	Implement the equals function that takes an Address object and checks if it is equal to
*	current object refered by (this pointer)
*	Two addresses are equal if all the attributes of addresses are equal
*/
bool Address::equals(const Address& address)const
{
	/*
	* Todo
	*/
	if (this->house == address.house && this->city == address.city
		&& this->country == address.country && this->street == address.street)
		return true;
	else
	   return false;
}

void Address::print_address()const
{
	/*
	*	Print address on one line as
	*	House, Street, City, Country
	*/
	cout << "Address:  "<<house<<" "<<street<<" " << city << " " <<country<<endl;
}

Address Address::copy_address()const
{
	/*
		return a copy of this
	*/
	Address A1;
	A1.house = this->house;
	A1.street = this->street;
	A1.city = this->city;
	A1.country = this->country;
	return A1;
	
}
