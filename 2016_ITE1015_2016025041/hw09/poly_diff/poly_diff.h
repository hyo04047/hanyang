#ifndef __POLY_DIFF_H__
#define __POLY_DIFF_H__

#include <vector>
#include <iostream>

class Variable {
public:
    Variable(std::string data);
    void Differentiate();
    int GetDiff(int x);
// private:
    int degree_;
    int constant_;
};

class PolyDiff {
public:
    int GetDiff(int x);
    
// private:
    std::vector<Variable> variables_;
};

#endif
