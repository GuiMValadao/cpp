/* Bitwise palindromes
Checks if a unsigned short value is a bitwise palindrome.
*/

#include <iostream>

using namespace std;

int main(void) {

	unsigned short int val, tmp_val;     // 16 bits of size
	bool ispalindrome = false;
    int reversed = 0;

    // To use longer sizes of numbers, is enough to change the type of val and adjust the value of bit_size.
    // However, the amount of bits should be even, which is the norm from common types.
    int bit_size = 16;      

	cout << "value = ";
	cin >> val;
	// Insert your code here
	if (val == 0)
        // All bits on 0 are zeros
	    ispalindrome = true;
    else if (val < ((1<<(bit_size/2)) + (1 << (bit_size/2-1)))){
        // The smallest possible palindrome after 0 is when both middle bits are 1s. 
        ispalindrome = false;
    } else {
        // Here we take the lower half of the val bits, transpose them to the higher half
        // of the variable 'bits' (with their order inverted), and set the lower half
        // bits of 'tmp_val' to 0 (tmp_val was created to avoid altering the source val).
	    unsigned short n = val;
        tmp_val = val;

        for (int i = 0; i < bit_size/2 ; i++) {
            if (n & (1<<i)) {
                reversed |= (1 << ((bit_size - 1) - i));    // Set the bit at the (bit_size-1-i) position to 1 
                tmp_val &= ~(1 << i);   // Unset the bit at the i position from tmp_val
            }
        }
        // Compare tmp_val and bits and set ispalindrome to the answer
        ispalindrome = tmp_val == reversed; 
	}


	if(ispalindrome)
		cout << val << " is a bitwise palindrome" << endl;
	else
		cout << val << " is not a bitwise palindrome" << endl;	
	return 0;
}