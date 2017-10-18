#include "bank_account.h"
#include <fstream>
#include <stdio.h>
#include <sstream>

using namespace std;

Account::Account(const std::string& name, unsigned int balance, double interest_rate)
		: name_(name), balance_(balance), interest_rate_(interest_rate) { }

Account::~Account() { }

// void Account::Deposit(unsigned int amount) {
// /* implement here*/
// }

// bool Account::Withdraw(unsigned int amount) {
// /* implement here*/

// }

unsigned int Account::ComputeExpectedBalance( unsigned int n_years_later) const {
/* implement here*/
	int result = balance_;
	for(int i = 0; i < n_years_later; i++){
		result += balance_ * interest_rate_;
	}
	return result;
}

SavingAccount::SavingAccount(const std::string& name, int balance, double interest_rate)
		: Account(name, balance, interest_rate) { }

SavingAccount::~SavingAccount() { }

unsigned int SavingAccount::ComputeExpectedBalance( unsigned int n_years_later) const {
/* implement here*/
	double result = balance_;
	for(int i = 0; i < n_years_later; i++){
		result *= (1 + interest_rate_);
	}
	int result_ = result;
	return result_;
}

// Account* CreateAccount(const std::string& type, const std::string& name, unsigned int balance, double interest_rate) {
// /* implement here*/

// }

bool SaveAccounts(const std::vector<Account*>& accounts, const std::string& filename) {
/* implement here*/
	ofstream file(filename);
	for(std::vector<Account*>::const_iterator it = accounts.begin(); it != accounts.end(); it++){
		file << (*it)->name() << " " << (*it)->type() << " " << (*it)->balance() << " " << (*it)->interest_rate() << endl;
	}
	file.close();
	return true;
}

bool LoadAccounts(const std::string& filename, std::vector<Account*>& accounts) {
/* implement here*/
	ifstream file(filename);
	string temp1, name, type, balance, interest_rate;
	int index;
	unsigned int balance_;
	double interest_rate_;
	while(getline(file, temp1)){
		index = temp1.find(" ");
		name = temp1.substr(0, index);
		temp1 = temp1.substr(index + 1);

		index = temp1.find(" ");
		type = temp1.substr(0, index);
		temp1 = temp1.substr(index + 1);

		index = temp1.find(" ");
		balance = temp1.substr(0, index);
		temp1 = temp1.substr(index + 1);
		istringstream buffer(balance);
		buffer >> balance_;

		interest_rate = temp1;
		istringstream buffer2(interest_rate);
		buffer2 >> interest_rate_;

		if(type == "checking"){
			Account* ptr = new Account(name, balance_, interest_rate_);
			accounts.push_back(ptr);
		}
		else if(type == "saving"){
			SavingAccount* ptr2 = new SavingAccount(name, balance_, interest_rate_);
			accounts.push_back(ptr2);
		}
	}
	return true;
}
