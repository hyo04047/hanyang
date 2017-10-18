#include "binary_search.h"
#include <iostream>

using namespace std;

BinarySearch::BinarySearch() {
    /* Implement Here. */
}

BinarySearch::BinarySearch(int *array, int array_count) {
    /* Implement Here. */
    array_ = array;
    array_count_ = array_count;
}

BinarySearch::~BinarySearch() {
    /* Implement Here. */
}

void BinarySearch::SortArray() {
    /* Implement Here. */
    for(int i = 0; i < array_count_; i++){
        for(int j = 0; j < array_count_; j++){
            if(array_[i] < array_[j]){
                int temp = array_[i];
                array_[i] = array_[j];
                array_[j] = temp;
            }
        }
    }
}

int BinarySearch::GetIndex(int element) {
    /* Implement Here. */
    SortArray();
    int n = array_count_ / 2;
    int right_input = 0;
    for(int i = 0; i < array_count_; i++){
        if(array_[i] == element) right_input = 1;
    }
    while(right_input == 1){
        if(array_[n] ==  element){
            //cout << "if" << "\n";
            return n;
            break;
        }
        else{
            //cout << "else" << "\n";
            if(array_[n] > element){
                n = n / 2;
            }
            else if(array_[n] < element){
                if(n != 1){
                    if(n == array_count_) n = n - 1;
                    else n = n + n / 2;
                }
                else if(n == 1) n = n + 1;
            }
        }
    }
    return -1;
}
