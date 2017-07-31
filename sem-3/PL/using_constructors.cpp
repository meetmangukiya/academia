/**
 * Problem definition:
 *  Write a C++ program to store the following information of an Account:
 *  Account Holder Name, Account Number and Balance Amount. The Account
 *  holder should be able to deposit and withdraw money and can
 *  check Balance Amount. Use Constructor overloading and Destructors.
 */

#include <iostream.h>
#include <conio.h>
#include <string.h>

class Account {
	char name[100];
	int account_number;
	int balance;
	public:
		Account() {
			cout << "Enter name: ";
			cin >> name;
			cout << "Enter account number: ";
			cin >> account_number;
			cout << "Enter balance: ";
			cin >> balance;
		}

		Account(Account &acc) {
			balance = acc.balance;
			account_number = acc.account_number;
			strcpy(name, acc.name);

			while(1) {
				int choice;
				cout << "\nChoice: ";
				cin >> choice;
				if (choice == 777) break;
				switch (choice) {
					case 1:
						int d_amount;
						cout << "Enter amount to be deposited: ";
						cin >> d_amount;
						balance += d_amount;
						break;
					case 2:
						int w_amount;
						cout << "Enter amount to be withdrawn: ";
						cin >> w_amount;
						balance -= w_amount;
						break;
					case 3:
						cout << "Balance: " << balance;
						break;
					case 4:
						cout << "Account holder name: " << name;
						cout << "Account number: " << account_number;
						break;
					default:
						cout << "1: deposit, 2: withdraw, 3: display, 4: Account info, 777: to exit";
						break;

				}

			}
		}

		~Account() {
			cout << "Destructor is called";
		}

};

int main() {
	clrscr();
	Account meet;
	Account raj(meet);

	getch();
	return 0;
}

/**Output
Enter name: meet
Enter account number: 123
Enter balance: 500

Choice: 1
Enter amount to be deposited: 200

Choice: 2
Enter amount to be withdrawn: 500

Choice: 3
Balance: 200
Choice: 1
Enter amount to be deposited: 800

Choice: 3
Balance: 1000
Choice: 5
1: deposit, 2: withdraw, 3: display, 4: Account info, 777: to exit
Choice: 777
Destructor is calledDestructor is called
*/

