/* Text manipulation: duplicate white space
This program reads a line and removes any extra white spaces, leaving only single spaces between words.
*/

#include <string>
#include <iostream>

int main()
{
    std::string sentence;
    std::getline(std::cin, sentence);

    // manipulate the sentence here
    int count = 0;  // count number of spaces
    for (int i = 0; i < sentence.length(); i++) {
        if (sentence[i] == ' ') {
            count += 1; // Increase number of spaces by 1
            if (count > 1){
                // If there's more than one space in sequence, erase each space following until next letter
                sentence.erase(i, 1);
                // To account for the deletion of a space/index from the string, subtract one from the indexing variable
                i--;
            }
        } else {
            // If the current position is a letter, resets the spaces counter
            count = 0;
        }
    }

    std::cout << sentence << "\n";
    return 0;
}


// Sample solution

// #include <iostream>
// #include <string>

// int main()
// {
//     std::string sentence;
//     std::getline(std::cin, sentence);

//     // manipulate the sentence here

//     size_t found = sentence.find("  ");
//     while (found != std::string::npos)
//     {
//       size_t count = 1;
//       while (sentence[found+count+1] == ' ')
//       {
//         count++;
//       }
//       sentence.erase(found, count);
//       found = sentence.find("  ", found+1);
//     }

//     std::cout << sentence << "\n";

//     return 0;
// }