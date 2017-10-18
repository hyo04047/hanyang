/**
 * this file is ...
 * @author
 *	@since
 */

#include "reply_admin.h"

ReplyAdmin::ReplyAdmin() {
  /* TODO: Implement here. */
}

ReplyAdmin::~ReplyAdmin() {
  /* TODO: Implement here. */
}

// int ReplyAdmin::getChatCount() {
  /* TODO: Implement here. */
	// int i;
 	// for(i = 0; i < NUM_OF_CHAT; ++i){
 	// string s = this->chats[i];
 	// if(s.empty() == true){
 		// break;
 		// }
 	// }
 	// return i;
// }

bool ReplyAdmin::addChat(string _chat) {
  /* TODO: Implement here. */
	// int count = this->chats.size();
	this->chats.push_back(_chat);

	return true;
}

bool ReplyAdmin::removeChat(int _index) {
  /* TODO: Implement here. */
	this->chats.erase(this->chats.begin() + _index);
	return true;
}

bool ReplyAdmin::removeChat(int *_indices, int _count) {
  /* TODO: Implement here. */
	int count = this->chats.size();
	//cout << count << "\n";
  	for(int i = _count - 1; i >= 0; i--){
 		this->chats.erase(this->chats.begin() + _indices[i]);
  	}
  	//this->chats[count - 1].erase();
  	return true;
}

bool ReplyAdmin::removeChat(int _start, int _end) {
  /* TODO: Implement here. */
	int count = this->chats.size();
	if(_start < 0) _start = 0;
	if(_end > count - 1) _end = count - 1;
	for(int i = _end; i >= _start; i--){
		this->chats.erase(this->chats.begin() + i);
	}
	return true;
}

void ReplyAdmin::printChat() {
  int count = this->chats.size();
  for(int i=0; i< count; ++i)
  {
    cout << i << " " << chats[i] << endl;
  }
}
