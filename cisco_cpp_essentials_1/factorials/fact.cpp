#include <iostream>
#include <cstdint>

using namespace std;
int main(void) {
    int n, mult;
    uint64_t result = 1;
    cout << "n = ";
    cin >> n;
    if (n < 0){
        cout << "Invalid value";
        return -1;
    }
    while (n > 0) {
        mult = n;
        result *= mult;
        n--;
    }
    if (n == 0) {
        cout << result;
        return 0;
    }

    cout << result;
    return 0;
}