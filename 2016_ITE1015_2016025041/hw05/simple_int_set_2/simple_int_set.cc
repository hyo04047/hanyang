/**
  * this file is ...
  * @author
  *	@since
  */

#include "simple_int_set.h"

#include <iostream>
#include <sstream>

using namespace std;

SimpleIntSet::SimpleIntSet() {
	/* TODO: Implement here. */
}

SimpleIntSet::~SimpleIntSet() {
	/* TODO: Implement here. */
}

void SimpleIntSet::Initialize(string text) {
	/* TODO: Implement here. */
	this->elements_.clear();
	string *argv = new string[text.length()]; // More than count.
    string token;
    size_t pos;
    int argc = 0;
    
    /* Parse the input string and
     store each element into argv array. */
    while(true) {
        pos = text.find(' '); // Index of first space character.
        token = text.substr(0, pos); // First parsed string.
        
        argv[argc++] = token;
        
        if (pos >= text.length()) {
            break; // Done parsing.
        }
        else {
            text.erase(0, pos + 1); // Delete first string.
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
            
            if(num == elements[elementCount - 1] && elementCount > 0) continue;
            
            elements[elementCount++] = num;
            this->elements_.insert(num);
        }
        else if(arg == "}") {
            //elements_ = elements;
            //element_count_ = elementCount;
            
            delete elements;
            elements = NULL;
            elementCount = 0;
        }
    }

}

void SimpleIntSet::Print() {
    cout << "{";
    for (std::set<int>::iterator it = this->elements_.begin(); it != this->elements_.end(); it++) {
		cout << " " << *it;
	}
    cout << " }" << endl;
}

SimpleIntSet SimpleIntSet::operator+ (SimpleIntSet& right){
   	// for(std::set<int>::iterator it = elements_.begin(); it != elements_.end(); it++){
    		// this->elements_.insert(*it);
    	// }
   	for(std::set<int>::iterator it = right.elements_.begin(); it != right.elements_.end(); it++){
  		if(elements_.find(*it) == elements_.end()){
   			this->elements_.insert(*it);
   		}
   	}
   	// Sort();
   	return *this;
}

SimpleIntSet SimpleIntSet::operator- (SimpleIntSet& right){
	// cout << "-" << endl;
	set<int> save;
   	for(std::set<int>::iterator it = elements_.begin(); it != elements_.end(); it++){
   		// cout << "for" << endl;
   		if(right.elements_.find(*it) == right.elements_.end()){
   			save.insert(*it);
   		}
   	}
   	elements_ = save;
   	// cout << "end" << endl;
    	// Sort();
   	return *this;
}

SimpleIntSet SimpleIntSet::operator* (SimpleIntSet& right){
	set<int> save2;
   	for(std::set<int>::iterator it = elements_.begin(); it != elements_.end(); it++){
   		if(right.elements_.find(*it) != right.elements_.end()){
   			save2.insert(*it);
   		}
   	}
   	elements_ = save2;
    	// Sort();
   	return *this;
}
	
// void SimpleIntSet::Sort() {
	/* TODO: Implement here. */
	// for (std::set<int>::iterator it = this->elements_.begin(); it != this->elements_.end(); it++) {
		// for (std::set<int>::iterator jt = this->elements_.begin(); jt != this->elements_.end(); jt++) {
			// if (*it < *jt) {
				// int temp = *it;
				// *it = *jt;
				// *jt = temp;
			// }
		// }
	// }
// }

// int *SimpleIntSet::Elements() const {
	// return elements_;
// }

// int SimpleIntSet::ElementCount() const {
	// return element_count_;
// }

