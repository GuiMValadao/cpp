#include <iostream>
#include <cstdint>

using namespace std;
int main(void) {
    int n;
    uint64_t result_1 = 1, result_2 = 1, result_final = 1;

    cout << "Type which position of a Fibonacci number you wish to know: ";
    cin >> n;
    if (n < 1) {
        cout << "Type an integer starting from 1, the first number." << endl;
        return -1;
    }
    if (n == 1 || n == 2) {
        cout << "The number in position " << n << " of the Fibonacci sequence is " << result_final << endl; 
        return 0;
    }
    // Loop starts in 2 as first and second Fibonacci numbers are 1.
    for (int i = 2; i < n; i++) {
        cout << result_final << endl;
        result_final = result_1 + result_2;
        result_1 = result_2;
        result_2 = result_final;
        
    }
    cout << "The number in position " << n << " of the Fibonacci sequence is " << result_final << endl;
    
    return 0;

}