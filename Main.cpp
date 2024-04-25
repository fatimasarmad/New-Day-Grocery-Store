#include "Store.h"
#include "Classnames.h"
int main()
{
	int opt=0;
	do {
		cout << "1. Login as an Admin" << endl;
		cout << "2. Login as a Manager" << endl;
		cout << "3. Login as a Customer" << endl;
		cout << "4. Exit" << endl;
		cin >> opt;
		switch (opt)
		{
		case 1:
		{
			Admin a;
			a.Login();

			break;
		}
			
		case 2:
		{
			Manager m;
			if (m.Login("Manager"))
			{
				m.showmenu();
			}
			else
			{
				cout << "Invalid Username or Password" << endl;
			}


			break;
		}
		}
	} while (opt != 4);
	
	cout << "-----------------------------------------------------------" << endl;
	_getch();

	}