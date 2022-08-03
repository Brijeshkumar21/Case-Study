#ifndef Product_H
#define	PRODUCT_H
#include <string>
#include<iostream>
#include <vector>

using namespace std;

class item
{
public:
	item();
	~item();
	void display();
		void input();
		void saveProduct(vector<pair<string, string>> &);
private:
	string arr1[7] = { "Product id", "Product name", "Type", "Selling price", "Cost price", "Tax", "Product iscription"};
	string p_n, p_d, sp, cp, tax, id;
	vector<pair<string, string>> vp;
};





#endif // !Product

