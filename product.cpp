#include "product.h"
#include <string>
#include<iostream>
#include<fstream>
#include<istream>
#include<algorithm>

using namespace std;


item::item()
{

	system("cls");
	cout << "\t\t\t PRODUCT\n\n" << endl;

}

item::~item()
{
}

void item::input()
{
	string s;
	int j;
	for (int i = 0; i < 7; i++) {
		cout << arr1[i] << " - ";
		cin >> s;
		vp.push_back(make_pair(arr1[i], s));
	}
	sort(vp.begin(), vp.end());   //sorting
	cout << "Added item" << endl;
	for (int i = 0; i < 7; i++) {
		cout << vp[i].first << " - " << vp[i].second << endl;
	}

	cout << "\t1. Add another item\n\t2. Show menu" << endl;
	cin >> j;
	
		if (j==1) {
			input();
		}
		else if (j==2) {

			cout << "\t1. save and exit\n\t2. Don't save and exit";

			int k;
			cin >> k;
			if (k == 1) {
				saveProduct(vp);
				vp.clear();
				display();
				
			}
			else if (k == 2) {
				vp.clear();
				display();
			}
			else {
				cout << "Invalid input...";

				while (k != 1 && k != 2) {
					cout << "\t1. save and exit\n\t2. Don't save and exit";
					cin >> k;
				}
			}
			display();
		}
		else {
			cout << "Invalid input...";

			while (j != 1 && j != 2) {
				cout << "\t1. Add another item\n\t2. Show menu" << endl;
				cin >> j;
			}
		}

}

void item::saveProduct(vector<pair<string, string>> &svp)
{

	ofstream s;
	s.open("Product.txt", ios::out | ios::app);
	for (int i = 0; i < vp.size(); i++)
	{
		if (i <= (svp.size() - 3)) {
			s << svp[i].first << "-" << svp[i].second;
			s << "\t";
		}
		if (i == (svp.size() - 2)) {
			s << svp[i].first << "-" << svp[i].second;
			s << "\n\n";
		}
		
	}
	s.close();

}


void item::display()
{
	int enter_choice;
	cout << " \t1. Add product" << endl;
	cout << " \t2. Search product" << endl;
	cout << " \t3. Update product" << endl;
	cout << " \t4. Remove product" << endl;
	cout << " \t5. Show product" << endl;
	cout << " \t6. Back to dashboard" << endl;

	cout << "Enter your choice...  ";
	cin >> enter_choice;
	
	switch (enter_choice)
	{
	case 1:
	{
		input();
		break;
	}

	default:
		
		break;
	}

}


//....................add item .............................

