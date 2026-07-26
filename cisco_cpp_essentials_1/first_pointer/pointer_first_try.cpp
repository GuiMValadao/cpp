/* Vectors and pointers: first try
Find the smallest value from the vector without using brackets (indexing).
*/
#include <iostream>

using namespace std;

int main(void) {

	int vector[] = { 3, -5, -17, 10, -4, 14, 5, 2, -13 };
	int n = sizeof(vector) / sizeof(vector[0]);
    int result = 0;
	// Insert your code here
	for (int i = 1; i < n; i++) {
	    if (*(vector + i) < result) {
	        result = *(vector +i);
	    }
	}
	
	cout << "The answer is " << result;

	return 0;
}