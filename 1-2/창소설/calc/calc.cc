#include "calc.h"

std::string Calc::getType() {
	return type;
}

int Calc::calculate(std::string cmd, int x, int y){
	if(cmd == "add"){
		return x + y;
	}
	else if(cmd == "sub"){
		return x - y;
	}
	else if(cmd == "mul"){
		return x * y;
	}
	else if(cmd == "div"){
		if(y == 0) return -1;
		else return x / y;
	}
	else
		return -1;
}

int ScientificCalc::calculate(std::string cmd, int x, int y){
	if(cmd == "power"){
		int ini = 1;
		for(int i = 0; i < y; i++){
			ini = ini * x;
		}
		return ini;
	}
	else return Calc::calculate(cmd, x, y);
}

int ProgrammerCalc::calculate(std::string cmd, int x, int y){
	if(cmd == "lshift"){
		x = x << y;
		return x;
	}
	else if(cmd == "rshift"){
		x = x >> y;
		return x;
	}
	else return Calc::calculate(cmd, x, y);
}

