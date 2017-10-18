#include <iostream>
#include <sstream>
#include <string>
#include "binary_search.h"

using namespace std;

int main(void) {
    BinarySearch *binary_search = NULL;
    
    while (true) {
        if (binary_search == NULL) { /* First, handle input array. */
            string inputs;
            getline(cin, inputs);
            
            string *argv = new string[inputs.length()]; // More than count.
            string token;
            size_t pos;
            int argc = 0;
            
            /* Parse the input string and
               store each element into argv array. */
            while(true) {
                pos = inputs.find(' '); // Index of first space character.
                token = inputs.substr(0, pos); // First parsed string. 
                
                argv[argc++] = token;
                
                if (pos >= inputs.length()) {
                    break; // Done parsing.
                }
                else {
                    inputs.erase(0, pos + 1); // Delete first string.
                }
            }
            
            int *elements = NULL;
            int elementCount = 0;
            
            /* Make an integer array and
               create BinarySearch class object. */
            for (int i = 0; i < argc; ++i) {
                string arg = argv[i];
                if (arg == "{" && elements == NULL) {
                    elements = new int[argc];
                }
                else if (isdigit(arg[arg.length() - 1])) {
                    int num;
                    istringstream buffer(arg);
                    buffer >> num;

                    elements[elementCount++] = num;
                }
                else if(arg == "}") {
                    binary_search = new BinarySearch(elements, elementCount);
                    
                    //delete elements;
                    elements = NULL;
                    elementCount = 0;
                }
            }
        } else { /* Find input element */
            int element;
            cin >> element;
            
            if(element < -998) break; // Termination.
            
            /* Print out index of element 
               using GetIndex member function. */
            cout << binary_search->GetIndex(element) << endl;
        }
    }
    
    delete binary_search;
    return 0;
}
