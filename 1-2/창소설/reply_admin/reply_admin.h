#ifndef __REPLY_ADMIN__
#define __REPLY_ADMIN__

#include <string>

#define MAX_SIZE 1024

class ReplyAdmin{
public:
	ReplyAdmin();
	~ReplyAdmin();
	int getChatCount(ReplyAdmin* chatlist);
	bool addChat(string _chat);
	bool removeChat(int _index);
	bool removeChat(int* _indices, int _count);
	bool removeChat(int _start, int _end);

private:
	string* chats;
}

#endif