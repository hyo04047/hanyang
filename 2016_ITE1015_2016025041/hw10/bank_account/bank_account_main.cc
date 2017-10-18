#include "bank_account.h"
#include <iostream>
#include <sstream>

using namespace std;

int getAccountIndex(const vector<Account*>& accounts, const string &name) {
/* implement here*/
	int temp;
	for(int i = 0; i < accounts.size(); i++){
		if(accounts[i]->name() == name){
			temp = i;
		}
	}
	return temp;
}

void addAccount(vector<Account*> &accounts) {
/* implement here*/
	string name, type, balance, rate;
	unsigned int balance_int; 
	double rate_;
	cin >> name >> type >> balance >> rate;
	istringstream buffer(balance);
	buffer >> balance_int;
	istringstream buffer2(rate);
	buffer2 >> rate_;

	if(type == "saving"){
		SavingAccount* ptr = new SavingAccount(name, balance_int, rate_);
		accounts.push_back(ptr);
	}
	else{
		Account* ptr2 = new Account(name, balance_int, rate_);
		accounts.push_back(ptr2);
	}
}

void deleteAccount(vector<Account*> &accounts) {
/* implement here*/
	// cout << "delete" << endl;
	string name;
	cin >> name;
	for(std::vector<Account*>::iterator it = accounts.begin(); it != accounts.end(); it++){
		if((*it)->name() == name){
			accounts.erase(it);
			break;
		}
	}
}

void showAccounts(const vector<Account*> &accounts) {
	/* implement here*/
	for(std::vector<Account*>::const_iterator it = accounts.begin(); it != accounts.end(); it++){
		cout << (*it)->name() << " " << (*it)->type() << " " << (*it)->balance() << " " << (*it)->interest_rate() << endl;
	}
}

void afterAccounts(const vector<Account*> &accounts) {
/* implement here*/
	unsigned int n;
	cin >> n;
	for(std::vector<Account*>::const_iterator it = accounts.begin(); it != accounts.end(); it++){
		cout << (*it)->name() << " " << (*it)->type() << " " << (*it)->ComputeExpectedBalance(n) << " " << (*it)->interest_rate() << endl;
	}
}

void saveAccounts(const vector<Account*> &accounts) {
/* implement here*/
	string file_name;
	cin >> file_name;
	SaveAccounts(accounts, file_name);
}

void loadAccounts(vector<Account*> &accounts) {
/* implement here*/
	string file_name;
	cin >> file_name;
	LoadAccounts(file_name, accounts);
}

int main() {
	string cmd;
	vector<Account*> accounts;


	do { cin >> cmd;
		if(cmd=="add") addAccount(accounts);
		else if(cmd=="delete") deleteAccount(accounts);
		else if(cmd=="show") showAccounts(accounts);
		else if(cmd=="after") afterAccounts(accounts);
		else if(cmd=="save") saveAccounts(accounts);
		else if(cmd=="load") loadAccounts(accounts);

	} while(cmd!="quit");

	return 0;
}