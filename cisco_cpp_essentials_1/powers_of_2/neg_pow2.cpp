#include <iostream>
#include <cstdint>

using namespace std;
int main(void){
    int power;
    double result = 1;    
    
    cout << "Enter the power of two you seek: ";
    cin >> power;

    while (power > 63 || power < 0) {
        cout << "The value you seek is out of bounds. Type another value from 1 to 63:";
        cin >> power;
    }
    
    // Usando loop e multiplicação, como pretendido pelo exercício. 
    // for (int i = 0; i < power; i++) {
    //     result /= 2;
    // }
    cout.precision(20);
    cout << "The answer is " << result << endl;
   
    
    return 0;
}