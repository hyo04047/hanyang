#ifndef __CALC_H__
#define __CALC_H__

#include <string>

class Calc {
public:
	Calc(std::string type = ""): type(type) {};
	~Calc() {};
	int calculate(std::string cmd, int x, int y);
	std::string getType();
protected:
	std::string type;
};

class ScientificCalc : public Calc{
public:
	ScientificCalc() : Calc() {};
	int calculate(std::string cmd, int x, int y);
};

class ProgrammerCalc : public Calc{
public:
	ProgrammerCalc() : Calc() {};
	int calculate(std::string cmd, int x, int y);
};

#endif
