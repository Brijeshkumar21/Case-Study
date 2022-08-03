#ifndef LOGIN
#define LOGIN
#include<string>
#include<vector>
#include"product.h"
#include"customer.h"
using namespace std;

class login
{
public:
	login();
	~login();

   virtual int display();        //virtual  funtion
    bool input();
    bool verify(string, string, int*, int*);
    void forget(int);
    int login_account();

private:
    string uname, password;
    int f_un = 2, f_pwd = 2;
};

class registration : public login
{
public:
    registration();
    ~registration();
    int display();
private:
    string arr1[8] = { "First name", "Last name" , "Username", "mobile number","Email-ID", "Security question:: name of your school", "Choose password", "Confirm password" };
    string s1[2];
    int status = 0;
    vector<pair<string, string>> v;
    vector<pair<string, string>>::iterator it;

};
class dashboard : public item, public customer

{
public:
    dashboard();
    ~dashboard();
    void display();

private:

};




#endif // !LOGIN


