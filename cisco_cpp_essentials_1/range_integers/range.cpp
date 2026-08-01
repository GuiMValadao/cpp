/* Range of integer types
The program correctly returns the sum of all integers up to 100,000.
*/

#include <iostream>

int main(void) {
    long long int result = 0, N;    // Windows's long is 32 bits. an alternative is using int32_t ou int64_t from <cstdint>
    std::cout << "The maximum number for the sum is ";
    std::cin >> N;
    if (!(std::cin.good() || N < 100000)) {
        std:: cout << "The value entered is invalid. Closing the program." << std::endl;
        return 1;
    }
    while (N > 0) {
        result += N;
        N--;    
    }
    std::cout << "The total sum is " << result << std::endl;
    return 0;
}