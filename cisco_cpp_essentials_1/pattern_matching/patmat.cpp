/* Pattern matching
The program receives two lines of text, the first is the pattern
to be matched and the second the sentence to search for the pattern.
- D will match any digit
- A will match any letter
- letters will match themselves?
- ? will match any symbol, including whitespaces
- Other punctuation will match the same symbol
*/

#include <string>
#include <iostream>

struct Collection {
	int  elno;
	std::string *elements;
};

void AddToCollection(Collection &col, std::string element) {

	if(col.elno == 0) {
	    col.elno = 1;
	    col.elements = new std::string[1];
        col.elements[0] = element;
	} else {
	    std::string *new_values = new std::string[col.elno + 1];
        for (int i = 0; i < col.elno; i++) {
            new_values[i] = col.elements[i];
        }
        new_values[col.elno++] = element;
        delete[] col.elements;
        col.elements = new_values;
	}
}

void PrintCollection(Collection col) {
	for(int i = 0; i < col.elno; i++)
		std::cout << col.elements[i] << std::endl;
}

bool check(char sentence_char, char pattern_char) {
    if (tolower(sentence_char) == tolower(pattern_char)) {
        return true;
    } else if (pattern_char == 'D' && isdigit(sentence_char)) {
        return true;
    } else if (pattern_char == 'A' && isalpha(sentence_char)) {
        return true;
    } else if (pattern_char == '?') {
        return true;
    }
    return false;
}

int main()
{
    std::string pattern;
    std::getline(std::cin, pattern);

    std::string sentence;
    std::getline(std::cin, sentence);
    // match pattern against sentence
    std::string results, word;
    Collection result = {0, NULL};
    size_t pattern_size = pattern.length();
    size_t sentence_size = sentence.length();
    bool match = false, end_sentence = false;
    for(int i = 0; i < sentence_size; i++) {
        for(char c : pattern) {
            if(check(sentence[i], c)) {
                word += sentence[i];
                i++;    //Increments i to check against the pattern
                if(i == sentence_size) {    // Avoids surpassing the length of the sentence
                    end_sentence = true;
                    break; 
                }
            } else {
                i -= word.length(); // Clears the word and breaks the current loop check. Is it necessary to reset i here?
                word.clear();
                break;
            }
        }
        size_t word_size = word.length();
        if ( word_size == pattern_size) {
            AddToCollection(result, word);
            i -= word_size;
            word.clear();
        }
    }
    PrintCollection(result);

}

// --------------------------------------------------------------------------

// Sample solution


// #include <string>
// #include <iostream>
// #include <cctype>

// bool chars_match(int pattern_char, int text_char)
// {
//   // The letter 'D' will match any decimal digit
//   if (pattern_char == 'D')
//   {
//     return isdigit(text_char);
//   }
//   // The letter 'A' will match any character of the english alphabet
//   if (pattern_char == 'A')
//   {
//     return isalpha(text_char);
//   }
//   // The character '?' will match every character
//   if (pattern_char == '?')
//   {
//     return true;
//   }
//   // Lower-case letters in a pattern will match according letters of the English alphabet
//   if (islower(pattern_char))
//   {
//     return pattern_char == tolower(text_char);
//   }
//   // Any punctuation except '?' will match exactly the same punctuation in a string
//   if (ispunct(pattern_char))
//   {
//     return pattern_char == text_char;
//   }
//   return false;
// }

// size_t find_match(std::string const &pattern, std::string const &text, size_t start = 0)
// {
//   size_t match_pos = std::string::npos;

//   size_t len_pattern = pattern.length();
//   if (len_pattern == 0 || start < 0)
//   {
//     return match_pos;
//   }

//   for (size_t idx_text = start;
//        match_pos == std::string::npos && idx_text + len_pattern <= text.length();
//        idx_text++)
//   {
//     bool all_match = true;
//     for (size_t idx_pattern = 0; all_match && idx_pattern < len_pattern; idx_pattern++)
//     {
//       all_match = chars_match(pattern[idx_pattern], text[idx_text + idx_pattern]);
//     }
//     if (all_match)
//     {
//       match_pos = idx_text;
//     }
//   }

//   return match_pos;
// }

// int main()
// {
//     std::string pattern;
//     std::getline(std::cin, pattern);

//     std::string sentence;
//     std::getline(std::cin, sentence);
//     // match pattern against sentence

//     size_t len_pattern = pattern.length();
//     size_t found = find_match(pattern, sentence);
//     while (found != std::string::npos)
//     {
//       std::cout << sentence.substr(found, len_pattern) << std::endl;
//       found = find_match(pattern, sentence, found + 1);
//     }

//     return 0;
// }