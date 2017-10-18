#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include "message_book.h"

using namespace std;

int main(void) {
    MessageBook* messagebook = new MessageBook();

    while(true) {
        string word;
        getline(cin, word);

        string word_copy = word;
        string word_copy_2;
        int num_index, message_index;
        num_index = word_copy.find(" ");
        word_copy_2 = word_copy.substr(num_index + 1);
        message_index = word_copy_2.find(" ");

        if(word.find("add") < word.length()) {
            /* Implement Here */
            string number_ = word.substr(num_index + 1, message_index);
            if(number_[0] > 64 && number_[0] < 91) continue;
            if(number_[0] > 96 && number_[0] < 123) continue;
            int number;
            istringstream buffer(number_);
            buffer >> number;

            // cout << "1" << endl;

            string content = word.substr(num_index + message_index + 2);

            messagebook->AddMessage(number, content);
        }
        else if (word.find("delete") < word.length()) {
            /* Implement Here */
            string number_ = word.substr(num_index + 1, message_index - num_index - 1);
            if(number_[0] > 64 && number_[0] < 91) continue;
            if(number_[0] > 96 && number_[0] < 123) continue;
            int number;
            istringstream buffer(number_);
            buffer >> number;

            messagebook->DeleteMessage(number);
        } 
        else if (word.find("print") < word.length()) {
            /* Implement Here */
            string number_ = word.substr(num_index + 1, message_index - num_index - 1);
            if(number_[0] > 64 && number_[0] < 91) continue;
            if(number_[0] > 96 && number_[0] < 123) continue;            
            int number;
            istringstream buffer(number_);
            buffer >> number;

            if(messagebook->FindMessage(number)){
                string output = messagebook->GetMessage(number);
                cout << output << endl;
            }
            else
                cout << " " << endl;
        } 
        else if (word.find("list") < word.length()) {
            /* Implement Here */
            for(std::map<int, string>::iterator it = messagebook->messages_.begin(); it != messagebook->messages_.end(); ++it){
                cout << it->first << ": " << it->second << endl;
            }
        } 
        else {
            break;
        }
    }

    return 0;
}
