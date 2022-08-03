#include "login.h"
#include<string>
#include<iostream>
#include<conio.h>

using namespace std;

login::login()
{
    cout << "\n\n\n\t\t\t\tWELCOME TO INVENTORY MANAGEMENT SYSTEM\n\n\n\n"
        << endl;
}

login::~login()
{
}

int login::display()
{
        int x = 0;
        cout << "1.\t login to continue" << endl;
        cout << "2.\t Register now" << endl;
        cin >> x;
        try
        {
            if ( isdigit(x)) {
                throw x;
            }
            else {
                return x;
            }
        }
        catch (char* x)
        {
            cout << "exception occured";
            display();
        }
           
}
 

bool login::input()
{
    cout << "\n\n Enter  the login credential to proceed to dashboard..... \n\n" << endl;
    cout << "\tusername :: ";
    cin >> uname;
    cout << "\tPassword :: ";
    cin >> password;
    bool x = verify(uname, password, &f_un, &f_pwd);

    if (x != true && f_un == 1) {
        int y;
        cout << "\t\t\t incorrect username!!!" << endl;
        cout << "1.\t retry" << endl;
        cout << "2.\t forgot Usernaame" << endl;
        cin >> y;
        if (y == 1) {
            input();
        }
        if (y == 2) {
            forget(1);
        }
    }
    else if (x != true && f_pwd == 1) {
        int y;
        cout << "\t\t\tincorect password!!!" << endl;
        cout << "1.\t retry" << endl;
        cout << "2.\t forgot Usernaame" << endl;
        cin >> y;

        if (y == 1) {
            input();
        }
        if (y == 2) {
            forget(2);
        }
    }
    else if (x == true && f_un == 0 && f_pwd == 0) {
        cout << "congratulations login successfull..." << endl;
        return true;
    }
    else {
        cout << "Something went wrong. " << endl;
        return false;
    }
}


bool login::verify(string name, string password, int* f_n, int* f_p)
{
    (name.compare("brijesh") == 0) ? *f_n = 0 : *f_n = 1;
    (password.compare("885131") == 0) ? *f_p = 0 : *f_p = 1;
    if (*f_n == 0 && *f_p == 0) {
        return true;
    }
    else {
        return false;
    }
}

void login::forget(int c)
{
    int forget_param = c;
    string ph, ans;
    if (forget_param == 1) {
        cout << "Enter your mobile number - ";
        cin >> ph;
        cout << "Answer the security question - \nWhat is the name of your school - ";
        cin >> ans;
        if (ph.compare("8287061408") == 0 && ans.compare("jps") == 0) {
            cout << "Your user name is 'brijesh'.\n\n\n" << "Login to continue";
            input();
        }
    }
    else if (forget_param == 2)
    {
        cout << "Enter your mobile number - ";
        cin >> ph;
        cout << "Answer the security question - \nWhat is the name of your school - ";
        cin >> ans;
        if (ph.compare("8287061408") == 0 && ans.compare("jps") == 0) {
            cout << "Your password is '885131'.\n\n\n" << "Login to continue";
            input();
        }
        else
        {
            cout << "Invalid input!!!" << endl;
            input();
        }
    }
}

int login::login_account()
{
    int x;
    cout << "1.\t login as employ" << endl;
    cout << "2.\t login as admin" << endl;

   cin>>x; //typcast char to int.
    try
    {
        if (isdigit(x)) {
            throw "exception occured";
        }
        else {
            if (x == 1) {
                return 1;
            }
            if (x == 2) {
                return 0;
            }
        }
    }
    catch (char x)
    {
        cout << "exception occured";
        login_account();
    

    }
    //cout << "x = " << x;
   
}


//.........................registration.......................

registration::registration()
{
    system("cls");
    cout << "\t\t\t Register to become a part of this family.\n\n\n"
        << endl
        << "Please provide the following information\n\n"
        << endl;
}

registration::~registration()
{
}

int registration::display()
{

    int k = 7, j = 0;
    for (int i = 0; i < (sizeof(arr1) / sizeof(arr1[0])); i++)
    {

        string s;
        cout << arr1[i] << " - ";
        cin >> s;
        if (i == 6) {
            s1[0] = s;
        }
        if (i == 7) {
            s1[1] = s;
        }

        v.push_back(make_pair(arr1[i], s));
    }
    if (s1[0].compare(s1[1]) == 0)
    {
        cout << "password match"
            << endl;
        v.push_back(make_pair(arr1[7], s1[0]));
        return 1;
    }
    else
    {
        cout << "password not match"
            << endl;
        cout << "choose password" << s1[0] << "\tconfirm passsword" << s1[1] << endl;
        return 0;
    }
}

//......................dashboard.........................

dashboard::dashboard() 
{
    system("cls");
    cout << "\t\t\t DASHBOARD\n\n\n\n\n" << endl;
}

dashboard::~dashboard()
{
}

void dashboard::display()
{
    int y;
    cout << "\t1. Products" << endl;
    cout << "\t2. Customers" << endl;
    cout << "\t3. Generate and search bills" << endl;
    cout << "\t4. Profile" << endl;
    while (true)
    {
        cout << "\tEnter your choice...  ";
        cin >> y;
        switch (y)
        {
        case 1:
        {
            system("cls");
            item::display();
            break;
        }

        
        case 2:
            system("cls");
            customer::display();

            break;
        case 3:


            break;
        case 4:



            break;


        default:
            cout << "Invalid Input! \npress 1 for 'product', press 2 for 'Customers', press 3 for 'Generate and search bills', press 4 for 'Profile'" << endl;
            break;
        }
    }

}

