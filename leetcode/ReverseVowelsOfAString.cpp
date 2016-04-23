class Solution {
public:
    string reverseVowels(string s) {
        for (int L = 0, R = s.length() - 1; L < R; ) {
            if (! isvowel(s[L])) ++ L;
            else if (! isvowel(s[R])) -- R;
            else swap(s[L ++], s[R --]);
        }
        return s;
    }
    
    bool isvowel(char c) {
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};


/**
Reverse Vowels of a String  
Difficulty: Easy

Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:
Given s = "hello", return "holle".

Example 2:
Given s = "leetcode", return "leotcede". 
 */
