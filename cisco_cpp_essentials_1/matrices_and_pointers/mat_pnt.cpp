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


//------------------------------------------------------
// Example solution from the course, pointing to the first element of the matrix and using that to assign values
//-------------------------------------------------------
// #include <iostream>

// using namespace std;

// int main(void) {

// 	int matrix[10][10] = { };

// 	// p points to the top-left element of the matrix
// 	// i.e. to the beginning of matrix
// 	int *p = (int *)matrix;     // Note: is necessary to cast the matrix to int *, as otherwise it would resolve to int *[10].
// 	for(int i = 0; i < 10; i++) {
// 		for(int j = 0; j < 10; j++) {
// 			// we have to find distancee between first element and [i][j] element
// 			// it is j * 10 (as there are 10 elements in every row) + i 
// 			// points to the elements

            //  One bug in the model solution: the course uses (p + j * 10) + i, but this is only true due
            // the simetry of the array. The correct version is (p + i * 10) + j, which extends to any size.
            // The bug happens as it considers 10 elements per line, but each element is tied to j and not i, 
            // all elements from the full lines would be the number of elements (10 in this case) times the amount
            // of lines above the current line (which is i due 0-indexing and first line starts at i = 0), so
// 			int *q = (p + i * 10) + j;
// 			*q = (i+1) * (j+1);
// 		}
// 	}		

// 	for(int i = 0; i < 10; i++) {
// 		for(int j = 0; j < 10; j++) {
// 			cout.width(4);
// 			cout << matrix[i][j];
// 		}
// 		cout << endl;
// 	}
// 	return 0;
// }