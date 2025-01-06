#include "Address.h"
#include "Contact.h"
#include "Group.h"
#include"list_of_groups.h"
#include "ContactsBook.h"
#include"HistoryObjects.h"
#include"History.h"
#include<iostream>
#include"stdexcept"
#include<fstream>
#include<string>
#include<ctime>
#include<chrono>
using namespace std;
string getTime()
{
	// current date/time based on current system
	time_t now = time(0);
	// convert now to string form
	string dt = ctime(&now);
	return dt;
}

int main()
{
	getTime();
	int  ch =0, a, b; int s=0; string f, l;
	cout << "enter the the number of contacts you want in the contact book\n";
	cin >> s;
	ContactsBook obj1(s); //Group obj(s);
	HistoryObjects histList(s);
	groupsList grplist(s);
	//obj1.load_from_file("file.txt");
	while (ch != 20)
	{
		cout << "1. Add New Contact\n";
		cout << "2. Merge Duplicates\n";
		cout << "3. Store To File(input file name)\n";
		cout << "4. Load From File(input file name)\n";
		cout << "5. Print Contacts Sorted(input choice, fist_name last_name)\n";
		cout << "6. Print Contacts\n";
		cout << "7. Search contacts (all three choices)\n";
		cout << "8. Display Count of Contacts\n";
		cout << "9. View Details of a single Contact \n";
		cout << "10. Print History of Searched Contacts \n";
		cout << "11. Create a Group\n";
		cout << "12. Add Contact to Available Groups\n";
		cout << "13. Remove Contact from a Group\n";
		cout << "14. View All Groups a Contact is in\n";
		cout << "15. delete a Group\n";
		cout << "16. Search string in All Attributes of Contacts\n";
		cout << "17. Enter a String to Search character by character in attributes of contacts\n";
		cout << "20. Exit\n";
		cin>>ch;
		if (ch == 1)
		{
			Contact c;
			cin >> c;
			obj1.add_contact(c);
		}
		else if (ch == 2)
		{
			obj1.merge_duplicates();
		}
		else if (ch == 3)
		{
			string file;
			cout << "Enter File Name to save data: \n";
			cin >> file;
			obj1.save_to_file(file);

		}
		else if (ch == 4)
		{
			string file;
			cout << "Enter File Name to load data: \n";
			cin >> file;
			obj1.load_from_file(file);

		}
		else if (ch == 5)
		{

			string f;
			cout << "Enter F for firstname and l for last name: \n";
			cin >> f;
			obj1.print_contacts_sorted(f);


		}
		else if (ch == 6)
		{
			obj1.print_contacts();


		}
		else if (ch == 7)
		{
			int ch;
			cout << "1. Search Based on First Name and Last Name\n";
			cout << "2. Search Based on Phone Number\n";
			cout << "3. Search Based on Address\n";
			cin >> ch;
			if (ch == 1)
			{
				
				cout << "enter First Name and Last name\n";
				cin >> f >> l;
				if (obj1.search_contact(f, l) != NULL)
				{
					Contact p = *(obj1.search_contact(f, l));
					cout << p;
					History obj(getTime(), " Searched By First and Last Name", p.getId());
					histList.Addhistory(obj);
					histList.save_to_file("searchhistory.txt");
				}
				else
					cout << "No First and Last name  match Found\n";

			}
			else if (ch == 2)
			{
				string f;
				cout << "Enter Phone Number\n";
				cin >> f;
				if (obj1.search_contact(f) != NULL)
				{
					Contact p = *(obj1.search_contact(f));
					cout << p;

					History obj(getTime(), " Searched by phone number", p.getId());
					histList.Addhistory(obj); 
					histList.save_to_file("searchhistory.txt");
				}
				else
					cout << "No Phone number match Found\n";
			}
			else if (ch == 3)
			{
				Address f;
				cout << "Enter Address\n";
				cin >> f;
				if (obj1.search_contact(f) != NULL)
				{
					Contact p = *(obj1.search_contact(f));
					cout << p;
					History obj(getTime(), " searched by email", p.getId());
					histList.Addhistory(obj);
					histList.save_to_file("searchhistory.txt");

				}
				else
					cout << "No Email Address match Found\n";
			}
		}
		else if (ch == 8)
		{
			cout << "Total Contacts Count: " << obj1.total_contacts() << endl;

		}
		else if (ch == 9)
		{
			cout << "Total Contacts Count: " << obj1.total_contacts() << endl;
			if (obj1.total_contacts() > 0)
			{
				cout << "enter Contact no to view details\n";

				cin >> a;
				obj1.view_contact(a - 1);
				cout << "Enter 1 to update the Contact details\n";
				cout << "Enter 2 to delete the Contact\n";
				cin >> b;
				if (b == 1)
				{
					obj1.update_contact(a - 1);
				}
				else if (b == 2)
				{
					obj1.delete_contact(a - 1);
				}
				else
					cout << "wrong input\n";
			}
			else
				cout << "no contacts added plz add contacts first\n";
		}
		else if (ch == 10)
		{
			
			cout << "History of searched contacts:\n ";
			histList.PrintReverse();
			cout << "enter 1 to view top5 viewed contacts\n";
			cin >> a;
			if (a == 1)
			{
				histList.getTop5("frequentlysearched.txt",obj1);
			
			}
			else
				cout << "wrong input\n";
		}
		else if (ch == 11)
		{
			string n;
			cout << "enter Group name\n"; cin >> n;
			cout << "enter Group size\n"; cin >> s;
			Group obj(s, n);
			//cin >> obj;
			grplist.addgroup(obj);
			grplist.save_to_file("groups.txt");
		}
		else if (ch == 12)
		{
			{
				if (obj1.total_contacts() > 0&&grplist.getgrpcount()>0)
				{
					cout << "Available Groups: \n";
					grplist.view(obj1);
					cout << "choose a group to Add Contact\n";
					cin >> a;
					obj1.print_contacts();
					cout << "enter a Contact id to add to grp\n";
					cin >> b;
					grplist.add(a - 1, b - 1);
					grplist.save_to_file("groups.txt");
				}
				else
					cout << "add contacts or grp first \n";

			}
		}
		else if (ch == 13)
		{
		
			cout << "Available Groups: \n";
			grplist.view(obj1);
			cout << "choose a group to Remove Contact\n";
			cin >> a;
			cout << "enter a Contact id to remove\n";
			cin >> b;
			grplist.remove(a - 1, b - 1);
		}
		else if (ch == 14)
		{
			
			obj1.print_contacts();
			cout << "enter a Contact id to check it's groups\n";
			cin >> b;
			grplist.check(b - 1);
		}
		else if (ch == 15)
		{
			if (grplist.getgrpcount() > 0)
			{
				cout << "Available Groups: \n";
				grplist.view(obj1);
				cout << "choose a group to delete\n";
				cin >> a;
				grplist.delete_grp(a - 1);
				grplist.save_to_file("groups.txt");
			}
			else
				cout << "create grps first\n";
		}
		else if (ch == 16)
		{
			cout << "Enter a String to Search in All Attributes of Contacts\n";
			cin >> f;
			obj1.Allsearch_contact(f);
		}
		else if (ch == 17)
		{

			cout << "Enter a String to Search character by character in attributes of contacts\n";
			cin >> f;
			obj1.Allsearch_Now(f);
		}
		else if(ch==20)
		{
			cout << "Exiting..\n";
			break;
		}
		else
		{
			cout << "invalid input\n";
		}
		system("pause");
		system("cls");
	}

	system("pause");
	return 0;
}