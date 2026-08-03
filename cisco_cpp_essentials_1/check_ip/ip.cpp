/* String in functions: IP numbers
Checks if an entered IP address is valid or not.
*/


// Original solution

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int parts_int[4] = {};  // Array to store the digits from each part after turned to ints.

// Checks if the given character is a digit. Returns true when the character is a digit.
bool digit_checker(string word, int position) {
    return ((word[position] >= '0' && word[position] <= '9'));
}

// Transforms each part of the IP from string to int
void string_to_int(string parts[]) {
    for (int i = 0; i < 4; i++) {
        int value = 0;
        for (int j = 0; j < parts[i].size(); j++) {
            value += ((parts[i][parts[i].size() - j - 1]) - '0') * (pow(10, j));
        }
        parts_int[i] = value;
    }
    return;
}

// Check each part of the string. Returns 1 when there are too many digits, 2 when the value
// of a part is over 255 and 0 otherwise.
int check_parts(string parts[]) {
    string_to_int(parts);

    for (int i = 0; i < 4; i++) {
        if ((parts[i].size()) > 3) {
            return 1;
        } else if (parts_int[i] > 255) {
            return 2;
        }
    }
    return 0;
}

int main(void) {
    string ip;
    cout << "Type the ip to check ";
    getline(cin, ip);
    string parts[4] = {};
    int amount = 0;
    // Checks if the ip entered has invalid characters or too many parts and separates each part into the parts array.
    for (int i = 0; i < ip.length(); i++) {
        if(ip[i] == '.') {
            amount += 1;
        } else if (!digit_checker(ip, i)) {
            cout << "Only digits and dots allowed." << endl;
            return 1;
        } else if (amount > 3){
            cout << "Too many parts";
            return 2;
        } else {
            parts[amount] += ip[i];
        }
    }
    // If the parts array has too few elements, the IP address has incorrect number of parts.
    if (amount < 3) {
        cout << "Incorrect parts count" << endl;
        return 3;
    }
    
    // The switch calls check_parts, and returns the appropriate exit.
    switch(check_parts(parts)) {
        case 1: {cout << "Too many characters in a part" << endl; return 4;}
        case 2: {cout << "Too big a value of a part"; return 5;}
        case 0: {cout << "Correct IP" << endl; return 0;}
    }

}

// Sample solution from Cisco C++ course

// #include <iostream>
// #include <string>
// #include <sstream>

// std::string checkIPAddress(std::string address)
// {
// 	std::stringstream splited(address);
// 	std::string s;
// 	int partsCount = 0;
// 	while (std::getline(splited, s, '.'))
// 	{
// 		if (3 < s.length() || s.length() < 1)
// 			return "Too many characters in part";
// 		if (partsCount > 4)
// 			return "Incorrect parts count";
// 		for (int i = 0; i < s.length(); i++)
// 		{
// 			if (!isdigit(s[i]))
// 				return "Only digits and dots allowed";
// 		}
// 		int partValue = atoi(s.c_str());
// 		if (partValue > 255)
// 			return "Too big value of part";
// 		partsCount++;
// 	}
// 	if (partsCount != 4)
// 		return "Too many parts";
// 	return "Correct IP";//Student can store the result in a variable, too
// }

// int main()
// {
// 	std::cout << checkIPAddress("1.2.3.4") << std::endl;
// 	std::cout << checkIPAddress("255.255.255.255") << std::endl;
// 	std::cout << checkIPAddress("355.255.255.255") << std::endl;
// 	std::cout << checkIPAddress("1000.255.255.255") << std::endl;
// 	std::cout << checkIPAddress("ASD.255.255.255") << std::endl;
// 	return 0;
// }