/* Overloading functions
Implement an function to increment a value by an expression similar to the one from
func_args_passing_by_reference_and_default_values/increment.cpp but which will accept
a function call with integer or float parameters.
*/

#include <iostream>
#include <cmath>
using namespace std;

// Insert your functions here
void increment(int &var, int expression = 1);
void increment(float &var, double expression = 1);

int main(void) {

	int intvar = 0;
	float floatvar = 1.5;

	for(int i = 0; i < 10; i++)
		if(i % 2) {
			increment(intvar);
			increment(floatvar, sqrt(intvar));
		}
		else {
			increment(intvar,i);
			increment(floatvar);
		}
	cout << intvar * floatvar << endl;
	return 0;
}


void increment(int &var, int expression) {
	var += expression;
}

void increment(float &var, double expression) {
	var += expression;
}