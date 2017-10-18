/**
  * This file is the example code for learning part of c++ string.
  * @author Hyeongwon Jang
  * @since 2016-10-09
  */
#include <iostream>
#include <string>
#include <cstddef>

using namespace std;

int main(void) {
    string str;
    string temp;
    
    /* Just assign does
       allocating and initializing string contents. */
    str = "Let's learn ";
    temp = "String!";
    cout << "str contains :" << str << endl;
    cout << "temp contains :" << temp << endl;
    
    /* Just adding does
       concatenating two strings. */
    str = str + temp;
    cout << "str = str + temp now contains :" << str << endl;
    
    /* Function length() and size() 
       returns the number of characters in string. */
    cout << "Length of str is : " << str.length() << endl;
    cout << "Size of str is : " << str.size() << endl;
    
    /* Function at(pos)
       returns pos-th elements in string. */
    cout << "4th character in str : " << str.at(4) << endl;
    //cout << "100th character in str : " << str.at(100) << endl; // this is error.

    /* Function find(seq)
       returns the first position of seq found from string.
       If not found, returns string::npos. */
    cout << "First index of \"learn\" : " << str.find("learn") << endl;
    cout << "First index of \"learnx\" : " << str.find("learnx") << endl;

    /* Function find_first_of(str), find_first_of(str, pos)
       returns the first position of charcter in str found from string. */
    temp = str;
    size_t found = temp.find_first_of("aeiou");
    while (found != string::npos) {
        temp[found] = '*';
        /* find characters in "aeiou" from 'found + 1' index in temp string. */
        found = temp.find_first_of("aeiou", found + 1);
    }
    cout << "[" << str << "] changes into [" << temp << "]" << endl;

    /* Function substr(pos, len)
       returns substring from string starting pos index to len bytes. */
    temp = "Let's";
    size_t pos = str.find(temp);
    size_t len = temp.length();
    string substr = str.substr(pos, len);
    cout << "Substring in str 5 bytes from index 0  :"<< substr << endl;

    /* Function erase(pos, len)
       returns substring erased from string starting pos index to len bytes. */
    str.erase(pos, len);
    cout << "After erasing str 5 bytes from index 0 :" << str << endl;

    /* Function stoi(str)
       returns valid integer from the string format.
       This function needs to be compiled in c++11. */
    temp = "123";
    int number = stoi(temp);
    cout << number << endl; // number stores 123 integer. 

    return 0;
}
