#include <iostream>
#include <string>
#include <stdlib.h>
#include <sstream>
#include "poly_diff.h"

using namespace std;

/* Constructor
 * Set degree_ and constant_ values.
 * @param[out]  data    string contains like x^4
 */
Variable::Variable(string data) {
    /* Implement Here */
    constant_ = 1; degree_ = 1;
    if(data.find("^") != std::string::npos){
    	int index, degree;
   	 	index = data.find("^");

	    string temp;
	    temp = data.substr(index + 1);
	    istringstream buffer(temp); 
	    buffer >> degree_;

	    string temp2;
	    temp2 = data.substr(0, index - 1);
	    // cout << "if" << endl;
	    if(temp2 == "-"){
			constant_ = -1;
			// cout << "if" << endl;
		}
	    else{
	    	// cout << "else" << endl;
	    	istringstream buffer2(temp2);
		    buffer2 >> constant_;
	   		if(constant_ == 0) constant_ = 1;
		}
		// cout << "constant_ : " << constant_ << endl;
	}

	else if(data.find("x") != std::string::npos){
		int index;
		string temp;
		index = data.find("x");
		temp = data.substr(0, index);
		// cout << "else if" << endl;
		if(temp == "-") constant_ = -1;
		else{
			istringstream buffer(temp);
			buffer >> constant_;
			if(constant_ == 0) constant_ = 1;
			degree_ = 1;
		}
		// cout << "constant_ : " << constant_ << endl;
	}

	else{
		istringstream buffer(data);
		buffer >> constant_;
		degree_ = 0;
		// cout << "constant_ : " << constant_ << endl;
	}
}

/* Differentiate the variable.
 * Ex)  [x^4] -> [4x^3] 
 */
void Variable::Differentiate() {
    /* Implement Here */
    if(degree_ == 0) constant_ = 0;
    else{
    	constant_ = constant_ * degree_;
    	degree_ -= 1;
    }
}

/* Get differential value of x.
 * Ex)  [x^4] -> [4x^3] -> 4 (x = 1)
 */
int Variable::GetDiff(int x) {
    /* Implement Here */
    int result = 1;
    Differentiate();
    if(constant_ == 0) return 0;
    else if(degree_ == 0) return constant_;
    else{
    	for(int i = 0; i < degree_; i++){
    		result = result * x;
    	}
    	result = result * constant_;
    	return result;
    }
}

/* Get differential value of f(x).
 * Ex)  f(x) = x^4+-3x^2+x
 *      f'(x) = 4x^3+-6x+1
 *      f'(4) = 233
 */
int PolyDiff::GetDiff(int x) {
    /* Implement Here */
    int result = 0;
    for(std::vector<Variable>::iterator it = variables_.begin(); it != variables_.end(); it++){
    	result += (*it).GetDiff(x);
    }
    return result;
}

