#include <iostream>
#include "poly_diff.h"

using namespace std;

int main(void) {
    string str;
    PolyDiff polydiff;
    polydiff.variables_.clear();
    while(true) {
        cin >> str;
        if (str == "quit") {
            break;
        } 
        else {
        	polydiff.variables_.clear();
            /* Implement Here */
            while(true){
	        	if(str.find("+") == string::npos){
	        		polydiff.variables_.push_back(Variable(str));
	        		break;
	        	}
	        	else{
	        		int index = str.find("+");
	        		string temp;
	        		temp = str.substr(0, index);
	        		polydiff.variables_.push_back(Variable(temp));
	        		str = str.substr(index + 1);
	        	}
	        }
	        // for(std::vector<Variable>::iterator it = polydiff.variables_.begin(); it != polydiff.variables_.end(); it++){
	        // 	cout << "constant : " << it->constant_ << " " << "degree : " << it->degree_ << " " << endl;
	        // }
	        // // cout << endl;
	        int x;
	        cin >> x; 
	        cout << polydiff.GetDiff(x) << endl;
        }
    }
    return 0;
}
