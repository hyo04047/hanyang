#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <windows>

using namespace std;

string PrimeFactorization(unsigned int _number){
	int prime=2;
	int n=0;
	string str_prime, str_n;
	string result;
	while(_number>=prime) {
		if(_number%prime==0){
			n++;
			_number/=prime;
		}
		else if(n!=0 && _number%prime!=0){
			str_prime=to_string(prime);
			str_n=to_string(n);
			prime++;
			n=0;
			result=result+str_prime+"^"+str_n;
			if(_number!=1) 
				result+=" x ";
		}		
		if(n==0 && _number%prime!=0){
			result+="";
			prime++;
			n=0;
		}					
		if(_number==1){
			str_prime=to_string(prime);
			str_n=to_string(n);
			result=result+str_prime+"^"+str_n;
			break;
		}

	}
	return result;
}

int main(int argc, char** argv)
{
	if(argc < 1) 
		return  1; 
	unsigned int number;
	sscanf(argv[1], "%u", &number);
    cout << PrimeFactorization(number) << endl;
	return 0; 
}
