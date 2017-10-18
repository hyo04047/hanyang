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
        }
        else if(arg == "}") {
            elements_ = elements;
            element_count_ = elementCount;
            
            //delete elements;
            //elements = NULL;
            //elementCount = 0;
        }
    }

}

void SimpleIntSet::GetUnion(const SimpleIntSet* left,
		const SimpleIntSet* right) {
	/* TODO: Implement here. */
    //cout << "Union" << "\n";
    
    int inequal = 0, k = 0;
    elements_ = new int[MAX_SIZE];
    
    //cout << "1" << "\n";
    
    for(int i = 0; i < left->ElementCount(); i++){
        elements_[i] = left->Elements()[i];
    }
    
    //cout << "2" << "\n";
    
    for(int j = 0; j < right->ElementCount(); j++){
        
        //cout << "j = " << j << "\n";
        
        for(int i = 0; i < left->ElementCount(); i++){
            if(right->Elements()[j] == elements_[i]){
                inequal++;
            }
            
            //cout << "i = " << i << " inequal = " << inequal << "\n";
            
        }
        if(inequal == 0){
            elements_[left->ElementCount() + k] = right->Elements()[j];
            k++;
        }
        inequal = 0;
    }
    
    //cout << "3" << "\n";
    
    element_count_ = left->element_count_ + k;
    Sort();
}

void SimpleIntSet::GetDifference(const SimpleIntSet* left, 
		const SimpleIntSet* right) {
	/* TODO: Implement here. */
    //cout << "Difference" << "\n";
    
    int index = 0, inequal = 0;
    //int copy[MAX_SIZE];
    elements_ = new int[MAX_SIZE];
    
    //cout << "1" << "\n";
    
    for(int i = 0; i < left->ElementCount(); i++){
        for(int j = 0; j < right->ElementCount(); j++){
            if(left->Elements()[i] == right->Elements()[j]){
                inequal++;
            }
        }
        if(inequal == 0){
            elements_[index] = left->Elements()[i];
            index++;
        }
        inequal = 0;
    }
    element_count_ = index;
    Sort();
}

void SimpleIntSet::GetIntersection(const SimpleIntSet* left, 
		const SimpleIntSet* right) {
	/* TODO: Implement here. */
    //cout << "Intersection" << "\n";
    elements_ = new int[MAX_SIZE];
    
    for(int i = 0; i < left->ElementCount(); i++){
        for(int j = 0; j < right->ElementCount(); j++){
            if(left->Elements()[i] == right->Elements()[j]){
                elements_[element_count_] = left->Elements()[i];
                element_count_++;
            }
        }
    }
    Sort();
}

void SimpleIntSet::Print() {
    cout << "{";
    for (int i = 0; i < element_count_; i++) {
		cout << " " << elements_[i];
	}
    cout << " }" << endl;
}

void SimpleIntSet::Sort() {
	/* TODO: Implement here. */
    for(int i = 0; i < element_count_; i++){
        for(int j = 0; j < element_count_; j++){
            if(elements_[i] < elements_[j]){
                int temp = elements_[i];
                elements_[i] = elements_[j];
                elements_[j] = temp;
            }
        }
    }
}

int *SimpleIntSet::Elements() const {
	return elements_;
}

int SimpleIntSet::ElementCount() const {
	return element_count_;
}

