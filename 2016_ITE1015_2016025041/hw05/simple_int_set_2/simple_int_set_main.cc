/**
  * this file is ...
  * @author
  *	@since
  */

#include <iostream>
#include <string>
#include <string.h>

#include "simple_int_set.h"

using namespace std;

/**
  * check valid operand text started with { and ended with }
  * @param[in]	str 		text to be checked for valid integer set 
                            - started with { and ended with }
  * @return true if the operand text is valid
  */
bool check_valid_operand(string str) {
	/* TODO: implements here. */

	return true;
}

int main(void) {

	bool	is_valid_input;
	size_t	set_open_index, set_close_index, operator_index;
	string 	inputs, str_integer_set;
	SimpleIntSet operands[2];
	SimpleIntSet resultSet;

	while (true) {
		/* initialize variables. */
		is_valid_input = false;
		operator_index = string::npos;
		set_open_index = string::npos;
		set_close_index = string::npos;

		// cout << "-1" << endl;

		/* Take an input of characters ended with line break - cin
		   and store thems to target charaters - inputs
		   http://www.cplusplus.com/reference/string/string/getline/ */
        getline(cin, inputs);

        // cout << "0" << endl;
		/* An input of Single character of '0' terminates this process */
		if (inputs == "0") {
			break;
		}

		/* Parse the input text and extract the left operand. */
		set_open_index = inputs.find("{");
		set_close_index = inputs.find("}");

		str_integer_set = inputs.substr(set_open_index, 
				set_close_index - set_open_index + 1);

		// cout << "1" << endl;

		if (check_valid_operand(str_integer_set)) {
			operands[0].Initialize(str_integer_set);
			is_valid_input = true;
		}

		// cout << "2" << endl;

		/* Parse the input text and the operator type. */
		operator_index = inputs.find_first_of("+-*", set_close_index);

		/* Parse the input text and extract the right operand. */
		set_open_index = inputs.find("{", operator_index);
		set_close_index = inputs.find("}", operator_index);

		str_integer_set = inputs.substr(set_open_index, 
				set_close_index - set_open_index + 1);

		// cout << "3" << endl;

		if (check_valid_operand(str_integer_set)) {
			operands[1].Initialize(str_integer_set);
			is_valid_input &= true;
		}

		// cout << "4" << endl;

		if (!is_valid_input || operator_index == string::npos
				|| set_open_index <= operator_index) {
			break;
		}

		// cout << "5" << endl;

		/* extracts the operation type from inputs. */
		switch (inputs.at(operator_index)) {
		default:
			break;
		case '+':
			/* TODO: Using operator overlading. */
			resultSet = operands[0] + operands[1];
			break;
		case '-':
			/* TODO: Using operator overlading. */
			resultSet = operands[0] - operands[1];
			break;
		case '*':
			/* TODO: Using operator overlading. */
			resultSet = operands[0] * operands[1];
			break;
		}

		// cout << "6" << endl;

		resultSet.Print();
	}

	return 0;
}
