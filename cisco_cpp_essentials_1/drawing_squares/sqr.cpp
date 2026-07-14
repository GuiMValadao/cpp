// Drawing squares (rectangles)
#include <iostream>

using namespace std;

int main(void) {
    int size;
    cout << "What size you wish to draw? ";
    cin >> size;
    if (size < 1) {
        cout << "Invalid size chosen." << endl;
        return -1;
    }
	cout << '+';
	for(int i = 0; i < size-2; i++)
		cout << '-';
	cout << '+' << endl;
	for(int i = 0; i < size-2; i++) {
		cout << '|';
		for(int j = 0; j < size-2; j++)
			cout << ' ';
		cout << '|' << endl;
	}
	cout << '+';
	for(int i = 0; i < size-2; i++)
		cout << '-';
	cout << '+' << endl;
	return 0;
}