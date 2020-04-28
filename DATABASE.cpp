#include "DATABASE.h"

Account Database::find(int currAccntNum) {
	for (int i{ 0 }; i < accounts.size(); i) {
		if (currAccntNum == accounts.at(i).get_accntNum()) {
			return accounts.at(i);
		}
		else {
			i += 1;
		}

	}
	//cout << "ERROR: COULD NOT FIND ACCOUNT WITH THAT ACCOUNT NUMBER" << endl;
	return Account();
}