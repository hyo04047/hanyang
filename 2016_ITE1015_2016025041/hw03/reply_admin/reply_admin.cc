#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <sstream>
#include <cstring>
#include <string.h>

using namespace std;

const int NUM_OF_CHAT = 200;

int getChatCount(vector<string> _chatList)
{
	int i;
//	for(i=0; i<NUM_OF_CHAT; ++i){
//		string s = _chatList[i];
//		if(s.empty() == true) break;
//	}
	i = _chatList.size();
 	return i;
}

void printChat(vector<string> _chatList)
{
	int count = getChatCount(_chatList);
 	for(int i = 0; i < count; ++i){
 		cout << i << " " << _chatList[i] << endl;
 	}
}

// Implement these functions
//bool addChat(vector<string> _chatList, string _chat){
//	_chatList.push_back(_chat);
	//for(int i = 0; i < NUM_OF_CHAT; i++){
	//	if(_chatList[i].empty()==1){
	//		_chatList[i] = _chat;
	//	}
	//}
//	return true;
//} // returns true when adding chat is succeeded

//bool removeChat(vector *_chatList, int _index){
//	if(){
//		return true;
//	}
//	else
//		return false;
//} // returns true when removing chat is succeeded

// Implement commented (/* */) areas in main function
int main(void)
{
	vector<string> chats;
	//vector<string>::iterator vIt;
	//cout << "variables" << "\n";
	chats.clear();
	chats.push_back("Hello, Reply Administrator!");
	chats.push_back("I will be a good programmer.");
	chats.push_back("This class is awesome.");
	chats.push_back("Professor Lim is wise.");
	chats.push_back("Two TAs are kind and helpful.");
	chats.push_back("I think male TA looks cool.");

	//cout << "input" << "\n";
	printChat(chats);
	
	while(true){
		string command;
		string temp;
		getline(cin, command);
		//cout << "input line" << "\n";
		
		if(command=="#quit") break;
		
		else if(/*command.find("#remove") >= 0 && */command.find("#remove") < command.length()){
 			/* remove chat */
 			//cout << "else if" << "\n";
 			string input_type = command.substr(8, command.size()-8);

 			if(((input_type.find('-') < input_type.length())) && (input_type.find(',') < input_type.length())) break;
 			
 			else if(input_type.find('-') < input_type.length()){
 				//cout << "-" << "\n";
 				int left_index = input_type.find('-') - 1;
 				int right_index = input_type.find('-') + 1;
 				int int_left_index, int_right_index;

 				//cout << "find_index" << "\n";
 				//cout << left_index << " " << right_index << "\n";

 				int_left_index = atoi(&input_type[left_index]);
 				int_right_index = atoi(&input_type[right_index]);

 				int howmany = getChatCount(chats);

 				//cout << howmany << "\n";

 				if(int_right_index >= howmany) int_right_index = howmany - 1;

 				for(int i = int_right_index; i >= int_left_index; i--){
 					chats.erase(chats.begin() + i);
 				}
 			}

 			else if(input_type.find(',') < input_type.length()){
 				//cout << "," << "\n";
 				int arr[NUM_OF_CHAT];
 				int count = 0;
 				int howmany = getChatCount(chats);
 				while(input_type.find(',') > 0 && input_type.find(',') < input_type.length()){
 					int int_left_index;
 					int left_index = input_type.find(',') - 1;

 					//cout << left_index << "\n";
 					if(left_index < howmany){

 					int_left_index = atoi(&input_type[left_index]);

 					//cout << int_left_index << "\n";
 					//if(int_left_index >= howmany) continue;
 					arr[count] = int_left_index;
 					count++;
 					}
 					//cout << arr[count] << "\n";

 					input_type.erase(0, 2);

 					printChat(chats);
 				}
 				int last_int;
 				//cout << "last" << "\n";
 				last_int = atoi(&input_type[0]);
 				if(last_int < howmany){
 				arr[count] = last_int;
 				}
 				for(int i = count; i >= 0; i--){
 					chats.erase(chats.begin() + arr[i]);
 				}
 			}

 			else{
 				int howmany = getChatCount(chats);
 				//cout << "int" << "\n";
 				int input_int;
 				if(input_type[0] > 64 && input_type[0] < 91) continue;
 				if(input_type[0] > 96 && input_type[0] < 123) continue;
 				istringstream temp5(input_type);
 				temp5 >> input_int;

 				//cout << input_int << "\n";

 				if(input_int >= howmany) continue;

 				chats.erase(chats.begin() + input_int);
 			}

 			printChat(chats);
 		}
 		
 		else if(command.find("#") > command.length()){
 			//cout << "else" << "\n";
 			chats.push_back(command);
 			//cout << "push_back" << "\n";
 			printChat(chats);
 		}
 	}
 
 // delete chatting list
 //delete[] chats;
 
 return 0;
}
