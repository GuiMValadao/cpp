#include <iostream>

using namespace std;
int main(void) {

    int matrix[3][3] = {};

    // ptr points to the first element of the array
    
    for(int i = 0; i < 3; i++) {
        int *ptr = matrix[i];
		for(int j = 0; j < 3; j++) {
            // Assigns to each element the value of i+1 * j + 1
            *(ptr + j) = (i + 1) * (j + 1);
            cout.width(4);
			cout << matrix[i][j];
        }
        cout << endl;
    }

}