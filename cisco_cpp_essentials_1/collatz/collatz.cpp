/* 
Collatz hypothesis

    1. take any non-negative and non-zero integer number and name it c0;
    2. if it's even, evaluate a new c0 as c0 / 2
    3. otherwise, if it's odd, evaluate a new c0 as 3 ⋅ c0 + 1
    4. if c0 ≠ 1, skip to point 2
*/
#include <iostream>

using namespace std;
int main(void){
    int c0, result;
    cout << "Enter a positive integer: ";
    // 1. Take any non-negative and non-zero integer number and name it c0;
    cin >> c0;

    if (c0 < 0) {
        cout << "c0 must be positive" << endl;
        return -1;
    }
    
    int steps = 0;
    
    while(c0 != 1) {
        // 2. if it's even, evaluate a new c0 as c0 / 2
        if (!(c0 % 2)) {
            c0 /= 2;
        } 
        // 3. otherwise, if it's odd, evaluate a new c0 as 3 ⋅ c0 + 1
        else {
            c0 = 3 * c0 + 1;
        }
        cout << c0 << endl;
        steps++;
        
        if (steps > 500){
            cout << "Something wrong with the loop";
            return -2;
        }
    }
    cout << "Steps = " << steps << endl;
    return 0;
}