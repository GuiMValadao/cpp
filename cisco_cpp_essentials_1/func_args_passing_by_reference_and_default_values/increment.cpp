/* Modifying a function argument's value – how do we do it?
Implement a function named increment that returns void and receives two parameters,
one is a value that will be incremented and the other is the amount to increment.
When only one argument is provided, increments the value by 1, otherwise 
increments the value by the expression received.
*/

#include <iostream>
using namespace std;
// Passing first parameter by reference, so the value of the parameter on main is altered
// Passing increment by value, and setting the default to 1.
void increment(int &var, int expression = 1) {
	var += expression;
}
int main(void) {

	int var = 0;
	for(int i = 0; i < 10; i++)
		if(i % 2)
			increment(var);
		else
			increment(var,i);
	cout << var << endl;
	return 0;
}