/* Finding PI by the Leibniz formula:
    PI / 4 = 1/1 - 1/3 + 1/5 - 1/7 + 1/9 - ...
*/
#include <iostream>

using namespace std;

int main(void) {
	double pi4 = 0., dividend = 1.;
	long   n;

	cout << "Number of iterations? ";
	cin >> n;

	// Insert your code here
    for (int i = 1; i <= n; i++){
        if (i%2)
            pi4 += 1./dividend;
        else
            pi4 -= 1./dividend;
        dividend += 2.;
    }
	cout.precision(20);
	cout << "Pi = " << (pi4 * 4.) << endl;
	return 0;
}