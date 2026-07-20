/* Counting bits (the ones)
This program counts the bits in a unsigned long integer that are 1.
*/

#include <iostream>

using namespace std;
int main(void) {
    unsigned long int n;
    int result = 0;
    cout << "n = ";
    cin >> n;
    
    while (n > 0) {
        // For counting zeros to the right of most significative bit
        // can just use the negation operator, !(n & 1)
        if (n & 1)     
            result++;
        n >>= 2;
    }
    cout << result << endl;
    return 0;
}