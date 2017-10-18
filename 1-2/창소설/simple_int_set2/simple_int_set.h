/**
  * this file is ...
  * @author
  *	@since
  */

#ifndef __SIMPLE_INT_SET__
#define __SIMPLE_INT_SET__

#include <string>

#define	MAX_SIZE	1024

class SimpleIntSet {
public:
    SimpleIntSet();
    ~SimpleIntSet();
	void Initialize(std::string text);
    void GetUnion(const SimpleIntSet* left, const SimpleIntSet* right);
    void GetDifference(const SimpleIntSet* left, const SimpleIntSet* right);
    void GetIntersection(const SimpleIntSet* left, const SimpleIntSet* right);
    void Print();
	void Sort(); // you can reuse your previous sort assignment

private: // getter
    int *Elements() const;
    int ElementCount() const;

private:
	int *elements_;
	int element_count_;
};

#endif
