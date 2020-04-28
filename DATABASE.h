#pragma once
#include <vector>
#include "ACCOUNT.h"

class Database {

private:
	vector<Account> accounts;

public:
	Database() {};
	void append(Account const& a) {
		accounts.push_back(a);
	}
	Account find(int currAccntNum);

};

