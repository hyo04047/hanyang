#include <map>
#include <string>
#include "matrix.h"
#include <iostream>
#include <ctype.h>
#include <sstream>
#include <locale>
#include <cctype>

using namespace std;

int main() {
    map<string, Matrix> matrices;
    string cmd;
    string name;
    locale loc;
    int row, col, value;
    while (cmd != "quit") {
        cin >> cmd;
        if (cmd == "matrix") {
            /* Implement Here */
            cin >> name;
            cin >> row;
            cin >> col;
            matrices.insert(make_pair(name, Matrix(row, col)));
            for(int i = 0; i < row * col; i++){
                cin >> value;
                matrices[name].values_.push_back(value);
            }
            cout << name << ":" << endl;
            matrices[name].Print();
        } else if (cmd == "list") {
            /* Implement Here */
            for(std::map<string, Matrix>::iterator it = matrices.begin(); it != matrices.end(); it++){
                cout << it->first << " " << it->second.rows_ << " " << it->second.cols_ << endl;
            }
        } else if (cmd == "eval") {
            /* Implement Here */
            string first, second;
            cin >> first;
            cin >> cmd;
            cin >> second;
            int number;
            if(isdigit(first[0])){
            	// cout << "0" << endl;
                istringstream buffer(first);
                buffer >> number;
                Matrix result(matrices[second].rows_, matrices[second].cols_);
                if(isdigit(second[0])){
                	// cout << "1" << endl;
                	int number2;
                	istringstream buffer(second);
                	buffer >> number2;
                	if(cmd == "+") cout << number + number2 << endl;
                	else if(cmd == "-") cout << number - number2 << endl;
                	else if(cmd == "*") cout << number * number2 << endl;
                }
                else if(cmd == "+"){
                	// cout << "2" << endl;
                    (number + matrices[second]).Print();
                    // result.Print();
                }
                else if(cmd == "-"){
                	// cout << "3" << endl;
                    (number - matrices[second]).Print();
                    // result.Print();
                }
                else if(cmd == "*"){
                	// cout << "4" << endl;
                	(number * matrices[second]).Print();
                	// result.Print();
                }
            }
            else if(isdigit(second[0])){
            	// cout << "5" << endl;
                istringstream buffer(second);
                buffer >> number;
                Matrix result(matrices[first].rows_, matrices[first].cols_);
                if(cmd == "+"){
                	// cout << "6" << endl;
                	(matrices[first] + number).Print();
                	// result.Print();
                }
                else if(cmd == "-"){
                	// cout << "7" << endl;
                	(matrices[first] - number).Print();
             		// result.Print();
                }
                else if(cmd == "*"){
                	// cout << "8" << endl;
                	(matrices[first] * number).Print();
                	// result.Print();
                }
            }
            else{
            	// cout << "9" << endl;
            	Matrix result(matrices[first].rows_, matrices[second].cols_);
            	if(cmd == "+"){
            		// cout << "10" << endl;
            		if(matrices[first].rows_ != matrices[second].rows_ || matrices[first].cols_ != matrices[second].cols_){
            			cout << "Invalid operation" << endl;
            			break;
            		}
            		else{
            			(matrices[first] + matrices[second]).Print();
            			// result.Print();
            		}
            	}
            	else if(cmd == "-"){
            		// cout << "11" << endl;
            		if(matrices[first].rows_ != matrices[second].rows_ || matrices[first].cols_ != matrices[second].cols_){
            			cout << "Invalid operation" << endl;
            			break;
            		}
            		else{
            			(matrices[first] - matrices[second]).Print();
            			// result.Print();
            		}
            	}
            	else if(cmd == "*"){
            		// cout << "12" << endl;
            		if(matrices[first].cols_ != matrices[second].rows_){
            			cout << "Invalid operation" << endl;
            			break;
            		}
            		else{
            			(matrices[first] * matrices[second]).Print();
            			// result.Print();
            		}
            	}
            }
        }
    }
    return 0;
}
