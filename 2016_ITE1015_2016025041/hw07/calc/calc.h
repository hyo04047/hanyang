#ifndef __CALC_H__
#define __CALC_H__

#include <string>

class Calc {
public:
	Calc(std::string type = ""): type(type) {};
	~Calc() {};
	virtual int calculate(std::string cmd, int x, int y);
	std::string getType();
protected:
	std::string type;
};

class ScientificCalc : public Calc{
public:
	// ScientificCalc() : Calc() {};
	virtual int calculate(std::string cmd, int x, int y);
};

class ProgrammerCalc : public ScientificCalc{
public:
	// ProgrammerCalc() : ScientificCalc() {};
	int calculate(std::string cmd, int x, int y);
};

#endif
