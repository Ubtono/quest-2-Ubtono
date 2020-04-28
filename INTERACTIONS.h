#pragma once
#include "DATABASE.h"

class Interactions {
private: 
	Database database;

public:
	Account logIn();
	void set_database(Database currDatabase) {
		database = currDatabase;
	}

	void displayBal(Account& a);
	void initiateTransfer(Account& a);
	bool logOut(char input);
	void endATM();
};
