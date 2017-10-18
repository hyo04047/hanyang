/**
  * this file is ...
  * @author
  *	@since
  */

#ifndef __SIMPLE_INT_SET__
#define __SIMPLE_INT_SET__

#include <string>
#include <set>

class SimpleIntSet {
public:
    SimpleIntSet();
    ~SimpleIntSet();
	void Initialize(std::string text);
    void Print();
    SimpleIntSet operator+ (SimpleIntSet& right);
    SimpleIntSet operator- (SimpleIntSet& right);
    SimpleIntSet operator* (SimpleIntSet& right);
	// void Sort(); // you can reuse your previous sort assignment
    // int *Elements() const;
    // int ElementCount() const;


    /* Implement operator overloading here */
    // SimpleIntSet operator+ (SimpleIntSet& right){
    // 	// for(std::set<int>::iterator it = elements_.begin(); it != elements_.end(); it++){
    // 		// this->elements_.insert(*it);
    // 	// }
    // 	for(std::set<int>::iterator it = right.elements_.begin(); it != right.elements_.end(); it++){
    // 		if(elements_.find(*it) == elements_.end()){
    // 			this->elements_.insert(*it);
    // 		}
    // 	}
    // 	// Sort();
    // 	return *this;
    // }

    // SimpleIntSet operator- (SimpleIntSet& right){
    // 	for(std::set<int>::iterator it = elements_.begin(); it != elements_.end(); it++){
    // 		if(right.elements_.find(*it) != right.elements_.end()){
    // 			elements_.erase(*it);
    // 		}
    // 	}
    // 	// Sort();
    // 	return *this;
    // }

    // SimpleIntSet operator* (SimpleIntSet& right){
    // 	for(std::set<int>::iterator it = elements_.begin(); it != elements_.end(); it++){
    // 		if(right.elements_.find(*it) == right.elements_.end()){
    // 			elements_.erase(*it);
    // 		}
    // 	}
    // 	// Sort();
    // 	return *this;
    // }

    // SimpleIntSet& operator= (SimpleIntSet& set){
    	// elements_ = set.elements_;
    	// return *this;
    // }

private:
    std::set<int> elements_;
};

#endif
