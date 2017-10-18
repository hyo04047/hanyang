#ifndef _MESSAGE_BOOK_H_
#define _MESSAGE_BOOK_H_

using namespace std;

class MessageBook {

public:
    MessageBook();
    ~MessageBook();
    
    void AddMessage(int number, const string& message);
    void DeleteMessage(int number);
    const string& GetMessage(int number) const;
    bool FindMessage(int number);
    map<int, string> messages_;

private:
};

#endif
