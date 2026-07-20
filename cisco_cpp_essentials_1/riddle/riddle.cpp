/* The riddle
In a square with sides of odd size, filled with sequential numbers starting in one
at the center of the square, guess what is the number in the lower-right position 
of the square. For example, in a size 3 the answer is 5:
+---+---+---+
| 9 | 2 | 3 |
+---+---+---+
| 8 | 1 | 4 |
+---+---+---+
| 7 | 6 | 5 |
+---+---+---+
*/

#include <iostream>

using namespace std;
int main(void) {
    int size;
    cout << "Enter the size of the helix (odd integer): ";
    cin >> size;
    if (!(size%2)){
        cout << "Size is not of the type required. Aborting execution." << endl;
        return -1;
    }
    
    // The answer will be the sum of a block of size "size - 2" with the
    // blocks located at the top and right of the block, which gives 
    // two sides of size "size - 1".
    
    int result = (size - 2) * (size - 2) + 2 * (size - 1);

    /* Suggested answer from the course:
    cout << (size * size - 2 * size + 2) << endl;
    In this answer, instead of summing the block size of the former square (size - 2) it subtracts (size - 1) from the square of the current size.
    */
    cout << "The answer is " << result << endl;
    return 0;
}