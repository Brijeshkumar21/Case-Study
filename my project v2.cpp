

#include <iostream>
#include <string>
#include<fstream>
#include"login.h"
using namespace std;

void saveinfo(string, string);

int client = 3;
bool status = false;

int main()
{
	
	login log;
	login* log1;
	while (!status)
	{
		client = log.login_account();
		//cout << "client = " << client;
		while (client != 0 && client != 1)
		{
			cout << "wrong input..." << endl;
			client = log.login_account();
		}

		if (client == 0) {
			cout << "login as Admin..." << endl;
		switch (int x = log.display())
			{
				case 1:
				{
					if (log.input()) {
						//system("cls");
						dashboard dash;
						dash.display();
						status = true;
					}
					break;
				}
				case 2:
				{
					registration reg;
					log1 = &reg;
					int b = log1->display();
					cout << "b= " << b;
					if (b)
					{
						system("cls");
						if (log.input()) {
							system("cls");
							dashboard dash;
							dash.display();
							status = true;
						}

					}
					break;
				}
			}

		}
		else
		{
			cout << "login as employ..." << endl;
			switch (int x = log.display())
			{
			case 1:
			{
				system("cls");
				if (log.input()) {
					//system("cls");
					dashboard dash;
					dash.display();
				}
				break;
			}
			case 2:
			{
				registration reg;
				bool b = reg.display();
				if (b)
				{
					system("cls");
					if (log.input())
					{
						system("cls");
						dashboard dash;
						dash.display();
					}
					break;
				}
			}
			}


		}
	}

	return 0;

}

