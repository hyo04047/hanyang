/**
 * this file is ...
 * @author
 *	@since
 */

#include "reply_admin.h"

ReplyAdmin::ReplyAdmin() {
  /* TODO: Implement here. */
	this->chats = new string[NUM_OF_CHAT];
}

ReplyAdmin::~ReplyAdmin() {
  /* TODO: Implement here. */
	delete[] chats;
}

int ReplyAdmin::getChatCount() {
  /* TODO: Implement here. */
	int i;
 	for(i = 0; i < NUM_OF_CHAT; ++i){
 	string s = this->chats[i];
 	if(s.empty() == true){
 		break;
 		}
 	}
 	return i;
}

bool ReplyAdmin::addChat(string _chat) {
  /* TODO: Implement here. */
	int count = getChatCount();
	this->chats[count] = _chat;

	return true;
}

bool ReplyAdmin::removeChat(int _index) {
  /* TODO: Implement here. */
	int count = getChatCount();
	for(int i = _index; i < count - 1; i++){
		this->chats[i] = this->chats[i + 1];
	}
	this->chats[count - 1].erase();
	return true;
}

bool ReplyAdmin::removeChat(int *_indices, int _count) {
  /* TODO: Implement here. */
	int count = getChatCount();
	//cout << count << "\n";
	int count2 = count;
  	for(int i = 0; i < _count; i++){
  		for(int j = _indices[_count - i - 1]; j < count2; j++){
  			this->chats[j] = this->chats[j + 1];

  			count--;
  		}  			
  		this->chats[count2 - 1].erase();
  		count2--;
  	}
  	//this->chats[count - 1].erase();
  	return true;
}

bool ReplyAdmin::removeChat(int _start, int _end) {
  /* TODO: Implement here. */
	int count = getChatCount();
	if(_start < 0) _start = 0;
	if(_end > count - 1) _end = count - 1;
	for(int i = 0; i < count - _end; i++){
		this->chats[_start + i] = this->chats[_end + i + 1];
	}
	count = count - _end + _start - 1;
	//cout << count << "\n";
	for(int i = count; i < count + _end - _start + 1; i++){	
		this->chats[i].erase();
	}
	return true;
}

void ReplyAdmin::printChat() {
  int count = getChatCount();
  for(int i=0; i< count; ++i)
  {
    cout << i << " " << chats[i] << endl;
  }
}
