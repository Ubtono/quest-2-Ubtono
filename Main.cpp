//#include"ACCOUNT.h" included with database
#include "DATABASE.h"
#include "INTERACTIONS.h"
#include <string>

using namespace std;


int main() {
	/*  Working interface for setting accnt members
	int accntNum1;
	int pin1;
	float bal1;
	Account accnt;
	cout << "enter account num: ";
	cin >> accntNum1;
	accnt.set_accntNum(accntNum1);
	cout << endl << "enter pin: ";
	cin >> pin1;
	accnt.set_pin(pin1);
	//bal1 = find(accntNum1, pin1);
	cout << "enter balance: ";
	cin >> bal1;
	accnt.set_bal(bal1);
	*/

	Account accnt1{ 999, 1234, 100 };
	Account accnt2{ 888, 2345, 250};
	Account accnt3{ 777, 3456, 10000};

	// Testing of pay_in() and pay_out()
	/*
	accnt1.pay_in(100);
	cout << accnt1.get_bal() << endl; // Should return 200  TRUE
	accnt2.pay_out(100);
	cout << accnt2.get_bal() << endl; // Should return 150.50 TRUE
	accnt3.pay_in(-20);
	cout << accnt3.get_bal() << endl; // Should return 10000.75 TRUE
	*/

	// Testing of transfer 
	/*
	transfer(accnt1, accnt2, 25);
	cout << accnt1.get_bal() << " : " << accnt2.get_bal() << endl; // Should return 75 : 275 TRUE
	transfer(accnt3, accnt2, 1000);
	cout << accnt3.get_bal() << " : " << accnt2.get_bal() << endl; // Should return 9000 : 1275 TRUE
	*/

	Database db = Database();
	db.append(accnt1);
	db.append(accnt2);
	db.append(accnt3);

	// Testing of find
	/*
	cout << db.find(999).get_pin() << endl; // Should return 1234 TRUE
	cout << db.find(777).get_pin() << endl; // should return 3456 TRUE
	cout << db.find(666).get_pin() << endl; // Should return error (-1) TRUE
	*/

	Interactions UI;
	UI.set_database(db);
	char input = 'n'; 
	while (input != 'E') {
		cout << "Press S to [S]ign in." << endl << "or E to [E]xit." << endl;
		cin >> input;
		if (input == 'S') {
			Account user = UI.logIn();
			cout << "Welcome User: " << user.get_accntNum() << endl << endl;
			while (UI.logOut(input) == false) {

				cout << endl << "Display [B]alance." << endl;
				cout << "[T]ransfer Funds." << endl << endl;
				cout << "[L]ogout." << endl << endl;

				cin >> input;

				switch (input) {
				case 'B':
					UI.displayBal(user);
					break;
				case 'T':
					UI.initiateTransfer(user);
					break;
				case 'L':
					UI.logOut('L');
				}
			}
		}
	}


	return 0;
}