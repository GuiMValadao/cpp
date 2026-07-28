/* Prime numbers - how do we find them?
Prints all prime numbers up to a chosen value, which is hardcoded as 21.
*/

#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int num) {

	// Insert your code here
	if (num < 2) {
	    return false;
	}
	for (int i=2; i <= sqrt(num); i++) {
	    if (!(num % i)) {
	        return false;
	    }
	}
	return true;
}

int main(void) {

	for(int i = 0; i <= 21; i++)
		if(isPrime(i))
			cout << i << " ";
	cout << endl;
	return 0;
}