#include"customer.h"
#include <string>
#include<iostream>
#include <vector>
#include<fstream>
#include<algorithm>

using namespace std;


customer::customer()
{
}

customer::~customer()
{
}

void customer::display()
{
	int enter_choice;
	cout << " \t1. Add customer" << endl;
	cout << " \t2. Search customer" << endl;
	cout << " \t3. Update customer details" << endl;
	cout << " \t4. Remove customer" << endl;
	cout << " \t5. Show customers" << endl;
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
	case 2:
	{
		input();
		break;
	}
	case 3:
	{
		input();
		break;
	}
	case 4:
	{
		input();
		break;
	}
	case 5:
	{
		input();
		break;
	}
	case 6:
	{
		input();
		break;
	}

	default:

		break;
	}
}

void customer::input()
{
	string s;
	int j;
	//cout<<"arr2 = "<<sizeof(arr2)/sizeof(arr2[0]);
	for (int i = 0; i < sizeof(arr2) / sizeof(arr2[0]); i++) {
		cout << arr2[i] << " - ";
		cin >> s;
		vp.push_back(make_pair(arr2[i], s));
	}
	sort(vp.begin(), vp.end());   //sorting
	cout << "Added item" << endl;
	for (int i = 0; i < 8; i++) {
		cout << vp[i].first << " - " << vp[i].second << endl;
	}

	cout << "\t1. Add another item\n\t2. Show menu" << endl;
	cin >> j;

	if (j == 1) {
		input();
	}
	else if (j == 2) {

		cout << "\t1. save and exit\n\t2. Don't save and exit";

		int k;
		cin >> k;
		if (k == 1) {
			saveCustomerInfo(vp);
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



void customer::saveCustomerInfo(vector<pair<string, string>> &svp)
{
	ofstream s;
	s.open("Customer.txt", ios::out | ios::app);
	for (int i = 0; i < svp.size(); i++)
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


