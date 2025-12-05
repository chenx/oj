// Time: O(n)
// Space: O(1)
class Solution {
public:
    bool isValid(string word) {
        return word.length() >= 3 && containsAlphaNumOnly(word) &&
            containsVowel(word) && containsConsonant(word);
    }

    bool containsAlphaNumOnly(string& word) {
        for (char ch : word) {
            if (! isalnum(ch)) return false;
        }
        return true;
    }

    bool containsVowel(string& word) {
        for (char ch : word) {
            if (isVowel(ch)) return true;
        }
        return false;
    }

    bool containsConsonant(string& word) {
        for (char ch : word) {
            // Must check isalpha, otherwise it may contains digits.
            if (isalpha(ch) && ! isVowel(ch)) return true;
        }
        return false;
    }

    bool isVowel(char ch) {
        static string vowels = "aeiouAEIOU";
        return vowels.find(ch) != -1;
    }
};


/**
3136. Valid Word
Easy

A word is considered valid if:

    It contains a minimum of 3 characters.
    It contains only digits (0-9), and English letters (uppercase and lowercase).
    It includes at least one vowel.
    It includes at least one consonant.

You are given a string word.

Return true if word is valid, otherwise, return false.

Notes:

    'a', 'e', 'i', 'o', 'u', and their uppercases are vowels.
    A consonant is an English letter that is not a vowel.

 

Example 1:

Input: word = "234Adas"

Output: true

Explanation:

This word satisfies the conditions.

Example 2:

Input: word = "b3"

Output: false

Explanation:

The length of this word is fewer than 3, and does not have a vowel.

Example 3:

Input: word = "a3$e"

Output: false

Explanation:

This word contains a '$' character and does not have a consonant.
 */
