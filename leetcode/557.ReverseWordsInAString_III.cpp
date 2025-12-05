// Time: O(n)
// Space: O(1)
class Solution {
public:
    string reverseWords(string s) {
        int left = 0, right = 0, n = s.length();
        while (left < n) {
            while (right < n && ! isspace(s[right])) ++ right;

            reverse(s.begin() + left, s.begin() + right); // [left, right)

            left = right + 1;
            right = left;            
        }
        return s;
    }
};


/**
557. Reverse Words in a String III
Easy

Given a string s, reverse the order of characters in each word within a sentence while 
still preserving whitespace and initial word order.

 

Example 1:

Input: s = "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"

Example 2:

Input: s = "Mr Ding"
Output: "rM gniD"
 */
