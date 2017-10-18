#include <iostream>
#include <string>

#include "calc.h"

int main() {

	Calc* calc = NULL;
	std::string calc_type;
	std::string calc_cmd;
	int x, y;

	std::cout << "Which Calculator (basic/scientific/programmer): ";
	std::cin >> calc_type;

	if (calc_type == "basic") {
		calc = dynamic_cast<Calc*>(new Calc());
	} else if (calc_type == "scientific") {
		calc = dynamic_cast<ScientificCalc*>(new ScientificCalc());
	} else if (calc_type == "programmer") {
		calc = dynamic_cast<ProgrammerCalc*>(new ProgrammerCalc());
	} else {
		std::cout << "Invalid Calculator type: " << calc_type << std::endl;
		goto exit;
	}

	std::cout << "Calculator Type: " << calc->getType() 
		<< " was set. " << std::endl;

	while (true) {
		std::cin >> calc_cmd;

		if (calc_cmd == "#quit") {
			break;
		}

		std::cin >> x >> y;
		std::cout << calc->calculate(calc_cmd, x, y) << std::endl;
	}

exit:
	delete calc;
	return 0;
}
