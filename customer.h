#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
#include<iostream>
#include <vector>

using namespace std;
class customer
{
public:
	customer();
	~customer();
	void display();
	void input();
	void saveCustomerInfo(vector<pair<string, string>> &);

private:
	string arr2[8] = {"Customer id", "Customer name", "Mobile no", "E-mai", "Address", "State", "City", "Pincode"};
	string c_n, c_d, mno, email, state, city,pin, addr;
	vector<pair<string, string>> vp;

};



#endif // !CUSTOMER_H
