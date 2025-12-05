// Time: O(n)
// Space: O(1) for C++.
class Solution {
public:
    string makeFancyString(string s) {
        if (s.length() <= 1) return s;

        int p = 1, count = 1;
        char cur = s[0];
        for (int i = 1; i < s.length(); ++ i) {
            if (cur == s[i]) {
                ++ count;
                if (count >= 3) continue;
            } else {
                cur = s[i];
                count = 1;
            }
            s[p ++] = s[i]; // <-------
        }
        s.resize(p); // <------- for C++, this is in place. For Java/Python, this is O(n)
        return s;
    }
};


// Time: O(n)
// Space: O(n) is we count space used by the result string.
class Solution {
public:
    string makeFancyString(string s) {
        if (s.length() <= 1) return s;

        char cur = s[0];
        int count = 1;
        string result = string(1, cur);
        for (int i = 1; i < s.length(); ++ i) {
            if (cur == s[i]) {
                ++ count;
                if (count >= 3) continue;
            } else {
                cur = s[i];
                count = 1;
            }
            result += cur;
        }
        return result;
    }
};


/**
1957. Delete Characters to Make Fancy String
Easy

A fancy string is a string where no three consecutive characters are equal.

Given a string s, delete the minimum possible number of characters from s to make it fancy.

Return the final string after the deletion. It can be shown that the answer will always be unique.

 

Example 1:

Input: s = "leeetcode"
Output: "leetcode"
Explanation:
Remove an 'e' from the first group of 'e's to create "leetcode".
No three consecutive characters are equal, so return "leetcode".

Example 2:

Input: s = "aaabaaaa"
Output: "aabaa"
Explanation:
Remove an 'a' from the first group of 'a's to create "aabaaaa".
Remove two 'a's from the second group of 'a's to create "aabaa".
No three consecutive characters are equal, so return "aabaa".

Example 3:

Input: s = "aab"
Output: "aab"
Explanation: No three consecutive characters are equal, so return "aab".
 */
