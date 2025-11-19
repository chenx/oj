class Solution {
public:
    bool detectCapitalUse(string word) {
        // if first letter is captial, all other can be consistently upper/lower case;
        // otherwise all should be lower case.
        if (word.length() == 0) return true;

        if (isCapitalLetter(word[0])) {
            if (checkAllLetters(word, 1, true) || checkAllLetters(word, 1, false)) return true;
        } else {
            if (checkAllLetters(word, 0, false)) return true;
        }
        return false;
    }

    bool checkAllLetters(string& s, int start, bool isCapital) {
        for (int i = start; i < s.length(); ++ i) {
            if ( (isCapital && ! isCapitalLetter(s[i])) ||
                 (! isCapital && isCapitalLetter(s[i]))
            ) {
                return false;
            }
        }
        return true;
    }

    bool isCapitalLetter(char ch) {
        return ch >= 'A' && ch <= 'Z';
    }
};


/**
520. Detect Capital
Easy

We define the usage of capitals in a word to be right when one of the following cases holds:

    All letters in this word are capitals, like "USA".
    All letters in this word are not capitals, like "leetcode".
    Only the first letter in this word is capital, like "Google".

Given a string word, return true if the usage of capitals in it is right.
 */
