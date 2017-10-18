#include <iostream>
#include <string>
#include <map>
#include "message_book.h"

MessageBook::MessageBook() {
    /* Implement Here */

}

MessageBook::~MessageBook() {
    /* Implement Here */
}

void MessageBook::AddMessage(int number, const string& message) {
    /* Implement Here */
    // cout << "2" << endl;
    this->messages_[number] = message;
}

void MessageBook::DeleteMessage(int number) {
    /* Implement Here */
    this->messages_.erase(number);
}

const string& MessageBook::GetMessage(int number) const {
    /* Implement Here */
    std::map<int, string>::const_iterator it = this->messages_.find(number);
    return it->second;
}

bool MessageBook::FindMessage(int number) {
    /* Implement Here */
    if(this->messages_.find(number) != this->messages_.end()){
    	return true;
    }
    else return false;
}
