#pragma once
#include <iostream>
#include <string>
using namespace std;
class Address {
private:
	std::string house;
	std::string street;
	std::string city;
	std::string country;

public:
	bool equals(const Address& address)const;
	void print_address()const;
	Address copy_address()const;

	Address(std::string house, std::string street, std::string city, std::string country);
	Address();
	void sethouse(string h);
	void setcity(string c);
	void setcountry(string c);
	void setstreet(string s);
	string gethouse()const;
	string getcity()const;
	string getcountry()const;
	string getstreet()const;
	friend istream& operator>>(istream& in, Address& a);
};
