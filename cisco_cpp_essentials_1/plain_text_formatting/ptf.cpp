/* Plain text formatting
-> all alphabet characters surrounded by asterisks will be made upper-case,
-> all characters surrounded by underscores will be separated by additional spaces
-> the symbol (* or _) will be ignored if a matching one isn't found in the sequence
*/

#include <string>
#include <iostream>
#include <algorithm>

void ast_changer(std::string &sentence, size_t start, size_t end) {
    std::string boldened = sentence.substr(start + 1, end - start - 1);
    std::transform(boldened.begin(), boldened.end(), boldened.begin(), ::toupper);
    sentence.replace(start, end - start + 1, boldened);
}

void und_changer(std::string &sentence, size_t start, size_t end) {

    std::string emphasised = sentence.substr(start + 1, end - start - 1 );
    size_t emph_len = emphasised.length();
    for (size_t i = 0; i < 2 * emph_len; i += 2) {
        if (emphasised[i] == ' ') {
            continue;
        }
        emphasised.insert(i, " ");
    }
    sentence.replace(start, end - start + 1, emphasised);
}

void apply_und_changes(std::string &sentence, size_t found_und, size_t sentence_len) {
    size_t position_und = 0, end_und = 0;
    while(found_und != std::string::npos) {
            position_und = found_und;
            end_und = sentence.find('_', position_und + 1);
            if (end_und != std::string::npos) {
                und_changer(sentence, position_und, end_und);
            } else {
                break;
            }
            found_und = sentence.find('_',  end_und + 1);
        }
}

void apply_ast_changes(std::string &sentence, size_t found_ast, size_t sentence_len) {
    size_t position_ast = 0, end_ast = 0;
    while(found_ast != std::string::npos) {
            position_ast = found_ast;
            end_ast = sentence.find('*', position_ast + 1);
            if (end_ast != std::string::npos) {
                ast_changer(sentence, position_ast, end_ast);
            } else {
                break;
            }
            found_ast = sentence.find('*',  end_ast + 1);
        }
}


void formatter(std::string &sentence) {
    
    size_t sentence_len = sentence.length();
    size_t found_ast = sentence.find('*');
    size_t found_und = sentence.find('_');
    if (found_ast == std::string::npos && found_und == std::string::npos) {
        return;
    }
    if (found_und != std::string::npos && found_ast == std::string::npos) {
        apply_und_changes(sentence, found_und, sentence_len - found_und);
        return;
    } else if (found_ast != std::string::npos && found_und == std::string::npos) {
        apply_ast_changes(sentence, found_ast, sentence_len - found_ast);
        return;
    } else {
        while (found_und != std::string::npos || found_ast != std::string::npos) {
            size_t start_und = found_und;
            size_t start_ast = found_ast;
            
            if (start_und > start_ast) {
                // Asterisk appears first
                found_ast = sentence.find('*', start_ast + 1);
                if (found_ast > start_und) {
                    // Undescore appears before second asterisk
                    // searches next asterisk after the underscore found           
                    continue;
                } else {
                    ast_changer(sentence, start_ast, found_ast - start_ast);
                }
            } else {
                // Underscore appears first
                found_und = sentence.find('_', start_und + 1);
                if (found_und > start_ast) {
                    continue;
                } else {
                    und_changer(sentence, start_und, found_und - start_und);
                }
            }
            if (found_und == sentence_len && found_ast == sentence_len) {
                break;
            }
        }
    }
    return;    
}

int main()
{
    std::string sentence;
    std::getline(std::cin, sentence);

    // manipulate the sentence here
    formatter(sentence);

    std::cout << sentence << "\n";
}



// Sample solution


// #include <string>
// #include <iostream>
// #include <algorithm>

// void bolden(std::string &text, size_t start, size_t end)
// {
//   std::string boldened = text.substr(start + 1, end - start - 1);
//   std::transform(boldened.begin(), boldened.end(), boldened.begin(), ::toupper);

//   text.replace(start, end - start + 1, boldened);
// }

// void emphasise(std::string &text, size_t start, size_t end)
// {
//   std::string emphasised = text.substr(start + 1, end - start - 1);
//   std::string::iterator next = emphasised.begin();
//   size_t chars_after_insert = 0;

//   while (next + 1 != emphasised.end())
//   {
//     emphasised.insert(next + 1, ' ' );
//     chars_after_insert += 2;
//     next = emphasised.begin() + chars_after_insert;
//   }

//   text.replace(start, end - start + 1, " " + emphasised + " ");
// }

// bool find_pair(std::string const &text, size_t &start, size_t &end, char &found_char)
// {
//   start = std::string::npos;
//   end = std::string::npos;

//   size_t start_asterix_pos = text.find_first_of('*');
//   size_t start_underscore_pos = text.find_first_of('_');

//   if (start_asterix_pos != std::string::npos)
//   {
//     size_t end_asterix_pos =  text.find_first_of('*', start_asterix_pos + 1);
//     if (end_asterix_pos != std::string::npos && start_underscore_pos > end_asterix_pos)
//     {
//       start = start_asterix_pos;
//       end   = end_asterix_pos;
//       found_char = '*';
//       return true;
//     }
//   }
//   if (start_underscore_pos != std::string::npos)
//   {
//     size_t end_underscore_pos =  text.find_first_of('_', start_underscore_pos + 1);
//     if (end_underscore_pos != std::string::npos && start_asterix_pos > end_underscore_pos)
//     {
//       start = start_underscore_pos;
//       end   = end_underscore_pos;
//       found_char = '_';
//       return true;
//     }
//   }

//   return false;
// }

// int main()
// {
//     std::string sentence;
//     std::getline(std::cin, sentence);

//     size_t found = sentence.find_first_of("_*");
//     while (found != std::string::npos)
//     {
//       size_t start = 0, end = 0;
//       char found_char = 0;
//       if (find_pair(sentence, start, end, found_char))
//       {
//         if (found_char == '*')
//         {
//           bolden(sentence, start, end);
//         }
//         if (found_char == '_')
//         {
//           emphasise(sentence, start, end);
//         }
//       }
//       else
//       {
//         sentence.erase(found, 1);
//       }
//       found = sentence.find_first_of("_*", found);
//     }

//     std::cout << sentence << "\n";

//     return 0;
// }