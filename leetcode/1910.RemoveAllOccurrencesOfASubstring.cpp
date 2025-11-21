// See: https://leetcode.com/problems/remove-all-occurrences-of-a-substring/editorial/
// Time complexity: O(n^2)
// Space complexity: O(n)
//
class Solution {
public:
    string removeOccurrences(string s, string part) {
        while (s.find(part) != string::npos) {
            int pos = s.find(part);
            s = s.substr(0, pos) + s.substr(pos + part.length());
        }
        return s;
    }
};


/**
1910. Remove All Occurrences of a Substring
Medium

Given two strings s and part, perform the following operation on s until all occurrences of the substring part are removed:

    Find the leftmost occurrence of the substring part and remove it from s.

Return s after removing all occurrences of part.

A substring is a contiguous sequence of characters in a string.
 */
