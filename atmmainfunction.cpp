//HAMZA ABBAS 24L3086
//UMAIS KHARAL 24L3032
//ABDULLAH BAJWA 24L3025
//MUHAMMAD ABADULLAH 24L3071





#include"atmfunctions.h"
using namespace std;

int main() {

	intro();

	int choice = 0;

	do {
		
		filetoarray();// TO RETURN DATA FROM FILE TO ARRAYS

		system("cls");// TO CLEAR SYSYTEM SCREEN

		// main menu panel 

		cout << "------------------------------------" << endl;
		cout << "|      PRESS 1 FOR LOGIN           |" << endl;
		cout << "------------------------------------" << endl;
		cout << endl;
		cout << endl;
		cout << "----------------------------------------" << endl;
		cout << "|      PRESS 2 FOR PIN UPDATE          |" << endl;
		cout << "----------------------------------------" << endl;
		cout << endl;
		cout << endl;
		cout << "-----------------------------------------------" << endl;
		cout << "|      PRESS 3 FOR ACCESS TO ADMIN PANEL      |" << endl;
		cout << "-----------------------------------------------" << endl;
		cout << endl;
		cout << endl;
		cout << "----------------------------------------" << endl;
		cout << "|      PRESS 4 TO EXIT PROGRAM          |" << endl;
		cout << "----------------------------------------" << endl;
		cout << endl;
		cout << endl;
		cin >> choice;
		while (choice < 0 && choice>3) {
			cout << "INVALID CHOICE.PLEASE TRY AGAIN" << endl;
			sound();
			cin >> choice;
		}
		if (choice == 1) {
			system("cls");
			int index = login();
			if (index >= 0) {

				int x;

				do {
					system("cls");
					// login panel
					cout << "----------------------------------------" << endl;
					cout << "|      PRESS 1 TO WITHDRAW             |" << endl;
					cout << "----------------------------------------" << endl;
					cout << endl;
					cout << endl;
					cout << "-----------------------------------------" << endl;
					cout << "|      PRESS 2 TO DEPOSIT               |" << endl;
					cout << "-----------------------------------------" << endl;
					cout << endl;
					cout << endl;
					cout << "----------------------------------------" << endl;
					cout << "|      PRESS 3 FOR FUNDS TRANSFER      |" << endl;
					cout << "----------------------------------------" << endl;
					cout << endl;
					cout << endl;
					cout << "---------------------------------------" << endl;
					cout << "|      PRESS 4 FOR MINI STATEMENT     |" << endl;
					cout << "---------------------------------------" << endl;
					cout << endl;
					cout << endl;
					cout << "----------------------------------------" << endl;
					cout << "|      PRESS 5 FOR BALANCE INQUIRY     |" << endl;
					cout << "----------------------------------------" << endl;
					cout << endl;
					cout << "----------------------------------------" << endl;
					cout << "|      PRESS 6 TO EXIT PROGRAM          |" << endl;
					cout << "----------------------------------------" << endl;
					cout << endl;
					cout << endl;
					cin >> x;
					if (x == 1) {
						system("cls");
						withdraw(index);

					}
					if (x == 2) {
						system("cls");
						deposit(index);

					}
					if (x == 3) {
						system("cls");
						fundstransfer(index);

					}
					if (x == 4) {
						system("cls");
						transactionhistory(index);

					}
					if (x == 5) {
						system("cls");
						checkbalance(index);

					}
					if (x == 6) {
						system("cls");
						cout << "*********************THANKS FOR USING ATM.HAVE A GOOD DAY*********************" << endl;

					}
					if (x != 6) {
						cout << endl << endl;
						cout << "Would you like to perform another operation?( 1 for yes and 0 for no)" << endl;
						int y = 0;
						cin >> y;

						while (y < 0 && y>1) {
							cout << "INVALID CHOICE.PLEASE TRY AGAIN" << endl;
							sound();
							cin >> choice;
						}
						if (y == 0) {
							cout << "THANKS FOR USING ATM.HAVE A GOOD DAY" << endl;
							break;
						}

					}
				} while (x != 6);
			}
		}
		if (choice == 2) {
			system("cls");
			updatepin();
		}
		if (choice == 3) {
			system("cls");
			adminpanel();
		}
		if (choice == 4) {
			system("cls");
			cout << "**********************THANK YOU FOR USING ATM.HAVE A GOOD DAY****************8" << endl;
			break;
		}

		if (choice != 4)
		{
			cout << endl;
			cout << "**********************WELCOME BACK TO MAIN MENU*******************************" << endl;
			cout << endl;
			cout << endl;
			cout << "Would you like to perform another operation?( 1 for yes and 0 for no)" << endl;
			cin >> choice;

			while (choice < 0 && choice>1) {
				cout << "INVALID CHOICE.PLEASE TRY AGAIN" << endl;
				sound();
				cin >> choice;
			}

			if (choice == 0) {
				cout << "THANKS FOR USING ATM.HAVE A GOOD DAY" << endl;
				break;
			}
		}

	} while (choice != 4);
}

