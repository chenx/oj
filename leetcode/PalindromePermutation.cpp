// Works. Tested. By: XC
// Palindrome iff:
// when s.length() is even, no char happens odd times;
// when s.length() is odd, only 1 char happens odd times.
class Solution {
public:
    bool canPermutePalindrome(string s) {
        const int SIZE = 256;
        int ct[SIZE] = {0}, len = s.length();
        for (int i = 0; i < len; ++ i) {
            ++ ct[s[i]];
        }
        
        int odd = 0, even = 0;
        for (int i = 0; i < SIZE; ++ i) {
            if (ct[i] & 1) odd ++;
            else even ++;
        }
        
        if (len & 1) return odd == 1;
        else return odd == 0;
    }
};


/**
Palindrome Permutation
Difficulty: Easy

Given a string, determine if a permutation of the string could form a palindrome.

For example,
"code" -> False, "aab" -> True, "carerac" -> True.

Hint:

Consider the palindromes of odd vs even length. What difference do you notice?
Count the frequency of each character.
If each character occurs even number of times, then it must be a palindrome. 
How about character which occurs odd number of times?
 */
