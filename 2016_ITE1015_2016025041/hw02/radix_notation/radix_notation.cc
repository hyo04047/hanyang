#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

string RadixNotation(int number, int radix){
	string result;
	char temp;
	int rest;
	int i;
	int last = 0;
	string output;
	for (int i = 0; number * radix >= radix; i++){
		rest = number % radix;
		temp = rest < 10? '0' + rest: 'a' + rest - 10;
		result = temp + result;
		number /= radix;
		last++;
	}
	//for (int j = last; j >= 0; j--){
	//		output = output + result[j];
	//}
	//return output;
	return result;
}

int main(int argc, char** argv) {
	if (argc < 2) 
		return  1;
	int radix;
	sscanf(argv[1], "%u", &radix);
	if (radix < 2 || radix > 36) 
		return  1; 
	for (int i = 2; i < argc; ++i) {
    	int number;
    	sscanf(argv[i], "%d", &number);
    	cout << RadixNotation(number, radix) << "\n";
	}
	return 0; 
}
