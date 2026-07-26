/* Matrices and pointers: a step inside
Fill a 10 x 10 matrix with numbers, yielding the multiplication table without using indexing (except once, when declaring the pointer).
*/

#include <iostream>

using namespace std;

int main(void) {

	int matrix[10][10] = { };

	// Insert your code here
    
	for(int i = 0; i < 10; i++) {
	    int *ptr = matrix[i];
		for(int j = 0; j < 10; j++) {
			cout.width(4);
			*(ptr + j) = (i+1) * (j+1);
			cout << matrix[i][j];
			
		}
		cout << endl;
	}
	return 0;
}