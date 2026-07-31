#include <iostream>

using namespace std;
int main(void) {

    int matrix[3] = {1, 2, 3};
    int *pt = matrix + 1;
    // ptr points to the first element of the array
    
    
        cout << pt[-1] << endl;
    

}