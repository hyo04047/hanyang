/**
  * this file is ...
  * @author
  *	@since
  */

#include <iostream>
#include <string>

#include "simple_int_set.h"

using namespace std;

/**
  * trim the word started with { and ended with }
  * @param[in]	inputs		input string
  * @param[in]	from_index	starting position
  * @return string	trimmed string from input
  */
inline static
string trim_word(string inputs, size_t from_index) {
	size_t start = inputs.find("{", from_index);
	size_t end = inputs.find("}", from_index);
	return inputs.substr(start, end - start + 1);
}

int main(void) {

	size_t found;
	string inputs;
    SimpleIntSet leftset, rightset, result;
	SimpleIntSet *left = &leftset, *right = &rightset, *resultSet = &result;

	while (true) {
		/* initialize variables. */
		found = string::npos;

		/* Take an input of characters ended with line break - cin
		   and store thems to target charaters - inputs
		   http://www.cplusplus.com/reference/string/string/getline/ */
        getline(cin, inputs);

		/* An input of Single character of '0' terminates this process */
		if (inputs == "0") {
			break;
		}

		/* Parse the input text and extract the operation type. */
		found = inputs.find_first_of("+-*");
		if (found != string::npos) {
			/* + or - or * splits the inputs into left and right word. */
			string lhs = trim_word(inputs, 0);
			string rhs = trim_word(inputs, found);

			/* TODO: initialize left from lhs and right from rhs. */
			left->Initialize(lhs);
			right->Initialize(rhs);
			resultSet->Initialize("");

			/* extracts the operation type from inputs. */
			switch (inputs.at(found)) {
			default:
				break;
			case '+':
				resultSet->GetUnion(left, right);
				break;
			case '-':
				resultSet->GetDifference(left, right);
				break;
			case '*':
				resultSet->GetIntersection(left, right);
				break;
			}
			resultSet->Print();
		}
	}

	if (left) {
		delete left;
	} if (right) {
		delete right;
	} if (resultSet) {
		delete resultSet;
	}

	return 0;
}
