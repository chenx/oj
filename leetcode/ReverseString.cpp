class Solution {
public:
    string reverseString(string s) {
        for (int L = 0, R = s.length() - 1; L < R; ++ L, -- R)
            swap(s[L], s[R]);
        return s;
    }
};

/**
Reverse String  
Difficulty: Easy

Write a function that takes a string as input and returns the string reversed.

Example:
Given s = "hello", return "olleh".
 */
