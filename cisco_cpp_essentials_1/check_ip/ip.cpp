#include <iostream>
#include <string>

using namespace std;

bool digit_checker(string word, int position) {
    return ((word[position] < '0' || word[position] > '9'));
}

int *string_to_int(string parts[], int &parts_int) {
    for (int i = 0; i < 4; i++) {
        int value = 0;
        for (int j = 0; j < sizeof(parts[i]); j++) {
            value += ((int) parts[i][parts[i].size() - j]) * (1 + 10 * j);
        }
        *(parts_int[i]) = value;
    }
    return &parts_int;
}

int check_parts(string parts[], int &parts_int) {
    for (int i = 0; i < 4; i++) {
        if ((parts[i].size()) > 3) {
            return 1;
        } else if (string_to_int(parts, parts_int)[i] > 255) {
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
    if (amount < 3) {
        cout << "Incorrect parts count" << endl;
        return 3;
    }
    int parts_int[4] = {};
    switch(check_parts(parts, parts_int[0])) {
        case 1: {cout << "Too many characters in a part" << endl; return 4;}
        case 2: {cout << "Too big a value of a part"; return 5;}
        case 0: {cout << "Correct IP" << endl; return 0;}
    }

}