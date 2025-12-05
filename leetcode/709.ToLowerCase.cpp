// Need to use reference to char, otherwise it's not changed.
class Solution {
public:
    string toLowerCase(string s) {
        for (char& ch : s) {
            if (ch >= 'A' && ch <= 'Z') {
                ch = ch - 'A' + 'a';
            }
        }
        return s;
    }
};


/**
709. To Lower Case
Easy

Given a string s, return the string after replacing every uppercase letter with the same lowercase letter.

 

Example 1:

Input: s = "Hello"
Output: "hello"

Example 2:

Input: s = "here"
Output: "here"

Example 3:

Input: s = "LOVELY"
Output: "lovely"
 */
