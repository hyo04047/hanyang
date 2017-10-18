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
  * @param[in]	from_index	starting position - {
  * @param[in]	to_index	end position - } 
  * @return true if the operand text is valid
  */
bool check_valid_operand(size_t from_index, size_t to_index) {
	/* TODO: implements here. */
    
	return false;
}

int main(void) {

	bool	is_valid_input;
	size_t	set_open_index, set_close_index, operator_index;
	string 	inputs;
	SimpleIntSet *operands[2];
	SimpleIntSet *resultSet;

	operands[0] = new SimpleIntSet();
	operands[1] = new SimpleIntSet();
	resultSet = new SimpleIntSet();

	while (true) {
		/* initialize variables. */
		is_valid_input = false;
		operator_index = string::npos;
		set_open_index = string::npos;
		set_close_index = string::npos;

		/* Take an input of characters ended with line break - cin
		   and store thems to target charaters - inputs
		   http://www.cplusplus.com/reference/string/string/getline/ */
        getline(cin, inputs);

		/* An input of Single character of '0' terminates this process */
		if (inputs == "0") {
			break;
		}

		/* Parse the input text and extract the left operand. */
		set_open_index = inputs.find_first_of("{");
		set_close_index = inputs.find("}");

		if (/*check_valid_operand(set_open_index, set_close_index)*/true) {
			operands[0]->Initialize(inputs.substr(set_open_index, 
						set_close_index - set_open_index + 1));
			is_valid_input = true;
		}

		/* Parse the input text and the operator type. */
		operator_index = inputs.find_first_of("+-*", set_close_index);

		/* Parse the input text and extract the right operand. */
		set_open_index = inputs.find_first_of("{", set_close_index);
		set_close_index = inputs.find("}", set_close_index + 1);

		if (/*check_valid_operand(set_open_index, set_close_index)*/true) {
			operands[1]->Initialize(inputs.substr(set_open_index, 
						set_close_index - set_open_index + 1));
			is_valid_input &= true;
		}

		if (!is_valid_input || operator_index == string::npos
				|| set_open_index <= operator_index) {
			break;
		}

		/* extracts the operation type from inputs. */
		switch (inputs.at(operator_index)) {
		default:
			break;
		case '+':
			resultSet->GetUnion(operands[0], operands[1]);
			break;
		case '-':
			resultSet->GetDifference(operands[0], operands[1]);
			break;
		case '*':
			resultSet->GetIntersection(operands[0], operands[1]);
			break;
		}
		resultSet->Print();
	}

	if (operands[0]) {
		delete operands[0];
	} if (operands[1]) {
		delete operands[1];
	} if (resultSet) {
		delete resultSet;
	}

	return 0;
}
