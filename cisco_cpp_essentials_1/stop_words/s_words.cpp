/* Stop word manipulation
Receives a list of words comma-separated and remove them from a sentence.
*/

#include <string>
#include <iostream>
#include <sstream>

int main()
{
    std::string stop_words;
    std::getline(std::cin, stop_words);

    std::string sentence;
    std::getline(std::cin, sentence);
    // remove stop_words from sentence here
    std::string s, temp;
    std::stringstream splited(stop_words);
    // Turns received sentence to all lower case
    for (char c : sentence) {
        temp += tolower(c);
    }
    sentence = temp;
    temp.clear();

    while (std::getline(splited, s, ',')) {
        size_t found = sentence.find(s);
        size_t word_len = s.length();
        while (found != std::string::npos) {
            if(sentence[found-1] == ' ' || sentence[found+word_len] == ' '){
                sentence.erase(found, s.length() + 1);
            }
            found = sentence.find(s, found + 1);
        }
    }
    
    
    
    std::cout << sentence << "\n";
}


// Sample solution (safer than my own, my program doesn't check the sentence boundaries)
// #include <string>
// #include <iostream>
// #include <algorithm>

// void remove_word_ci(std::string &sentence, std::string const &word)
// {
//   std::string sentence_copy = sentence;
//   std::transform(sentence_copy.begin(), sentence_copy.end(), sentence_copy.begin(), ::tolower);
//   std::string word_copy = word;
//   std::transform(word_copy.begin(), word_copy.end(), word_copy.begin(), ::tolower);

//   size_t found = sentence_copy.find(word_copy);
//   size_t word_len = word_copy.length();
//   while (found != std::string::npos)
//   {
//     size_t from = found;
//     size_t len = word_len;
//     bool left_space       = found > 0 && sentence[found-1] == ' ';
//     bool right_space      = found + word_len < sentence.length() 
//                             && sentence[found + word_len] == ' ';
//     bool left_boundry_ok  = left_space || found == 0;
//     bool right_boundry_ok = right_space || found + word_len == sentence.length();

//     if (left_boundry_ok && right_boundry_ok)
//     {
//       if (left_space)
//       {
//         from--;
//         len++;
//       }
//       if (!left_space && right_space)
//       {
//         len++;
//       }
//       sentence.erase(from, len);
//       sentence_copy.erase(from, len);
//     }

//     found = sentence_copy.find(word, found + 1);
//   }
// }

// int main()
// {
//   std::string stop_words_string;
//   std::getline(std::cin, stop_words_string);

//   std::string sentence;
//   std::getline(std::cin, sentence);
//   // remove stop_words from sentence here

//   size_t word_end = stop_words_string.find(',');
//   while (word_end != std::string::npos)
//   {
//     remove_word_ci(sentence, stop_words_string.substr(0, word_end));
//     stop_words_string.erase(0, word_end+1);
//     word_end = stop_words_string.find(',');
//   }
//   if (stop_words_string.length() > 0)
//   {
//     remove_word_ci(sentence, stop_words_string);
//   }

//   std::cout << sentence << "\n";

//   return 0;
// }