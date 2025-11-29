// See: https://leetcode.com/problems/goat-latin/editorial/
// Time: O(n^2)
// Space: O(n^2)
//
class Solution2 {
public:
    string toGoatLatin(string sentence) {
        string result, word, padding;
        stringstream ss(sentence);

        while (ss >> word) {
            if (! isVowel(word[0])) {
                word = word.substr(1) + word[0];
            }

            padding += "a";
            result += word + "ma" + padding + " ";
        }
        result.pop_back(); // remove the last space.
        
        return result;
    }

    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
            ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
    }
};

class Solution {
public:
    string toGoatLatin(string sentence) {
        string result, word;
        stringstream ss(sentence);
        int count = 1;

        // while (ss >> word) {
        while (getline(ss, word, ' ')) {
            if (isVowel(word[0])) {
                word += "ma";
            } else {
                word = word.substr(1) + word[0] + "ma";
            }
            word += string(count, 'a');

            if (count > 1) result += " ";
            result += word;

            ++ count;
        }
        return result;
    }


    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
            ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
    }
};


/**
824. Goat Latin
Easy

You are given a string sentence that consist of words separated by spaces. Each word consists of lowercase and 
uppercase letters only.

We would like to convert the sentence to "Goat Latin" (a made-up language similar to Pig Latin.) The rules of 
Goat Latin are as follows:

    If a word begins with a vowel ('a', 'e', 'i', 'o', or 'u'), append "ma" to the end of the word.
        For example, the word "apple" becomes "applema".
    If a word begins with a consonant (i.e., not a vowel), remove the first letter and append it to the end, then add "ma".
        For example, the word "goat" becomes "oatgma".
    Add one letter 'a' to the end of each word per its word index in the sentence, starting with 1.
        For example, the first word gets "a" added to the end, the second word gets "aa" added to the end, and so on.

Return the final sentence representing the conversion from sentence to Goat Latin.

 

Example 1:

Input: sentence = "I speak Goat Latin"
Output: "Imaa peaksmaaa oatGmaaaa atinLmaaaaa"

Example 2:

Input: sentence = "The quick brown fox jumped over the lazy dog"
Output: "heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa"
 */
