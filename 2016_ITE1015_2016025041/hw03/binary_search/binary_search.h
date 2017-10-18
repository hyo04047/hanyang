// binary_search.h
// Implement your binary_search.cc

#ifndef __BINARY_SEARCH__
#define __BINARY_SEARCH__

class BinarySearch
{
public:
    BinarySearch();
    BinarySearch(int *_array, int _arrayCount);
    ~BinarySearch();
    int GetIndex(int _element); // return -1 when element doesn't exist

private:
    int *array_;
    int array_count_;
    
    void SortArray(); // you can reuse your previous sort assignment
};

#endif
