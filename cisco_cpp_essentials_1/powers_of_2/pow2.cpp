#include <iostream>
#include <cstdint>

using namespace std;
int main(void){
    int power;
    uint64_t result = 1;    // O tipo unsigned long no windows tem 32 bits. uint64_t de cstdint garante a utilização de 64 bits.
    
    cout << "Enter the power of two you seek: ";
    cin >> power;

    while (power > 63 || power < 1) {
        cout << "The value you seek is out of bounds. Type another value from 1 to 63:";
        cin >> power;
    }

    // Deslocamento de bits para a esquerda é equivalente a multiplicar por uma potência de 2.
    //result = result << power;
    
    // Usando loop e multiplicação, como pretendido pelo exercício. 
    for (int i = 0; i < power; i++) {
        result *= 2;
    }

    cout << "The answer is " << result << endl;
   
    
    return 0;
}