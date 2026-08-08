/*Text manipulation: find and replace
Receives 3 lines of text: the one to be replaced, to one that
will replace the first and the source text that will be altered.
*/

#include <iostream>
#include <string>

int main()
{
    std::string from;
    std::getline(std::cin, from);

    std::string to;
    std::getline(std::cin, to);

    std::string sentence;
    std::getline(std::cin, sentence);
    size_t position_count = -1;
    // change all occurrences of 'from' into 'to' in the sentence
          
    size_t found = sentence.find(from);
    size_t from_len = from.length();
    size_t to_len = to.length();
    while (found != std::string::npos){
        sentence.replace(found, from_len,to);
        found = sentence.find(from, found + to_len + 1);
    }

    std::cout << sentence << "\n";
}