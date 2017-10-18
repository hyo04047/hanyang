/**
 * this file is ...
 * @author
 *	@since
 */

#include <iostream>
#include <string>
#include <sstream>
#include "reply_admin.h"

using namespace std;

bool replyOperation(ReplyAdmin *_replyAdmin)
{
	while(true){
	    string inputs;
	    getline(cin, inputs);
	    
	    if(inputs == "#quit") return false;
	    else if(inputs.find("#remove") != string::npos)
	    {
	      /* TODO: implements here. */
	    	string input_type = inputs.substr(8, inputs.size() - 8);
	    	
	    	if(((input_type.find('-') < input_type.length())) && (input_type.find(',') < input_type.length())) break;

	    	else if(input_type.find('-') < input_type.length()){
	    		int left_index = input_type.find('-') - 1;
	    		int right_index = input_type.find('-') + 1;
	    		int value_left_index, value_right_index;

	    		value_left_index = atoi(&input_type[left_index]);
	    		value_right_index = atoi(&input_type[right_index]);

				_replyAdmin->removeChat(value_left_index, value_right_index);    		
	    	}

	    	else if(input_type.find(',') < input_type.length() && input_type.find(',') > 0){
	    		int arr[NUM_OF_CHAT];
	    		int count_ = 0;
	    		int howmany = _replyAdmin->getChatCount();
	    		while(input_type.find(',') > 0 && input_type.find(',') < input_type.length()){
	    			int value_left_index;
	    			int left_index = input_type.find(',') - 1;

	    			if(left_index < howmany){
	    				value_left_index = atoi(&input_type[left_index]);
	    				arr[count_] = value_left_index;
	    				count_++;
	    			}

	    			input_type.erase(0, 2);
	    			
	    			//_replyAdmin->printChat();
	    		}
	    		int last_int;
	    		last_int = atoi(&input_type[0]);
	    		if(last_int < howmany){
	    			arr[count_] = last_int;
	    		}

	    		//cout << count_ << "\n";

	    		_replyAdmin->removeChat(arr, count_ + 1);
	    	}

	    	else{
	    		int howmany = _replyAdmin->getChatCount();
	    		int input_int;
	    		if(input_type[0] > 64 && input_type[0] < 91) continue;
	    		if(input_type[0] > 96 && input_type[0] < 123) continue;
	    		istringstream temp5(input_type);
	    		temp5 >> input_int;

	    		if(input_int >= howmany) continue;

	    		_replyAdmin->removeChat(input_int);
	       	}

	       	_replyAdmin->printChat();
	    }
	    else if(inputs.find("#") > inputs.length()){ 
	    	_replyAdmin->addChat(inputs);
	    	_replyAdmin->printChat();
	    } 
	}
	return true;
}

int main(void)
{
    ReplyAdmin *replyAdmin = new ReplyAdmin();

    replyAdmin->addChat("Hello, Reply Administrator!");
    replyAdmin->addChat("I will be a good programmer.");
    replyAdmin->addChat("This class is awesome.");
    replyAdmin->addChat("Professor Lim is wise.");
    replyAdmin->addChat("Two TAs are kind and helpful.");
    replyAdmin->addChat("I think male TA looks cool.");
    
    while(replyOperation(replyAdmin)) { /* Nothing else to do. */ }
    
    delete replyAdmin;
    return 0;
}
