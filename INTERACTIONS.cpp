#include "INTERACTIONS.h"

Account Interactions::logIn() {
	char charInput;
	int accntNumInput;
	int pinInput;
	cout << "Returning User? [Y]/[N]: ";
	cin >> charInput;
	if (charInput == 'N') { // Create new account [N]
		Account newAccount;
		cout << endl << "Please enter a new account number: ";
		cin >> accntNumInput;
		newAccount.set_accntNum(accntNumInput);
		cout << endl << "Please enter a four digit pin: ";
		cin >> pinInput;
		newAccount.set_pin(pinInput);
		newAccount.set_bal(0);
	}
	else { // Authorization [Y]
		Account currAccount;
		char input;
		cout << endl << "Please enter your account number: ";
		cin >> accntNumInput;
		cout << endl << "Please enter your 4 digit pin: ";
		cin >> pinInput;
		currAccount = database.find(accntNumInput);
		while (pinInput != currAccount.get_pin()) { // Pin matches db

			cout << "Incorrect login information." << endl;
			cin >> pinInput;
		}
		cout << "Login Successful." << endl << endl;
			return currAccount;
		}
	}
void Interactions::displayBal(Account& user) {
	cout << endl << endl << "CURRENT BALANCE:  $" << user.get_bal() << endl << endl;
}
void Interactions::initiateTransfer(Account& user) {
	int recipientAccntNum;
	float amt;
	cout << endl << "Please enter the recipient's account number: ";
	cin >> recipientAccntNum;
	cout << endl << "Enter the amount you'd like to send: ";
	cin >> amt;

	Account recipient = database.find(recipientAccntNum);
	transfer(user, recipient, amt);

}

bool Interactions::logOut(char input) {
	return (input == 'L');
}

void Interactions::endATM() {
	exit(EXIT_SUCCESS);
}