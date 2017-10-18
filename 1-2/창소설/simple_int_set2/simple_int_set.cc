/**
  * this file is ...
  * @author
  *	@since
  */

#include "simple_int_set.h"
#include <sstream>
#include <iostream>

using namespace std;

SimpleIntSet::SimpleIntSet() {
	/* TODO: Implement here. */
}

SimpleIntSet::~SimpleIntSet() {
	/* TODO: Implement here. */
}

void SimpleIntSet::Initialize(string text) {
	/* TODO: Implement here. */
    //int count = 0;
    //for(int i = 0; i != '0'; i++){
    //    Elements()[i] = atoi(&text[i]);
    //    count++;
    //}
    //element_count_ = count;
    //Sort();
    
    string *argv = new string[text.length()]; // More than count.
    string token;
    size_t pos;
    int argc = 0;
    int *elements_ = NULL;
    element_count_ = 0;
    
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
            //cout << "else" << "\n";
        }
    }
    //cout << "for_start" << "\n";
    for (int i = 0; i < argc; ++i) {
        string arg = argv[i];
        //cout << "arg" << "\n";
        if (arg == "{" && elements_ == NULL) {
            cout << "if" << "\n";
            elements_ = new int[argc];
        }
        else if (isdigit(arg[arg.length() - 1]) != 0) {
            cout << "else if" << "\n";
            int num;
            istringstream buffer(arg);
            buffer >> num;
            
            Elements()[element_count_++] = num;
        }
        else if(arg == "}") {
            
        }
    }
}

void SimpleIntSet::GetIntersection(const SimpleIntSet* left,
		const SimpleIntSet* right) {
	/* TODO: Implement here. */
    //int ElementCount() = 0;
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

void SimpleIntSet::GetDifference(const SimpleIntSet* left, 
		const SimpleIntSet* right) {
	/* TODO: Implement here. */
    int element_count_ = 0, inequal = 0;
    int copy[MAX_SIZE];
    for(int i = 0; i < left->ElementCount(); i++){
        for(int j = 0; j < right->ElementCount(); j++){
            if(left->Elements()[i] != right->Elements()[j]){
                inequal++;
            }
        }
        if(inequal == right->ElementCount()){
            elements_[element_count_] = left->Elements()[i];
            element_count_++;
        }
    }
    Sort();
}

void SimpleIntSet::GetUnion(const SimpleIntSet* left,
		const SimpleIntSet* right) {
	/* TODO: Implement here. */
    int inequal = 0, k = 0;
    for(int i = 0; i < left->ElementCount(); i++){
        elements_[i] = left->Elements()[i];
    }
    for(int j = 0; j < right->ElementCount(); j++){
        for(int i = 0; i < left->ElementCount(); i++){
            if(right->Elements()[j] != left->Elements()[i]){
                inequal++;
            }
        }
        if(inequal == left->ElementCount()){
            elements_[left->ElementCount() + k] = right->Elements()[j];
            k++;
        }
    }
    element_count_ = left->ElementCount() + k;
    Sort();
}

void SimpleIntSet::Print() {
    cout << "{";
    for(int i = 0; i < element_count_; i++) {
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

