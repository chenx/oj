// From: https://leetcode.com/problems/remove-k-digits/editorial/
// Greedy with Stack.
// Time: O(n). Although there are nested loops, the inner loop is bounded to be run at most k times globally.
// Space: O(n)
class Solution {
public:
    string removeKdigits(string num, int k) {
        deque<char> q;
        for (char digit : num) {
            while (! q.empty() && k > 0 && q.back() > digit) {
                q.pop_back();
                k --;
            }
            q.push_back(digit);
        }
        for (; k > 0; -- k) q.pop_back();

        string s;
        bool leadingZero = true;
        while (! q.empty()) {
            char digit = q.front();
            q.pop_front();

            if (leadingZero && digit == '0') continue;
            leadingZero = false;

            s += digit;
        }

        return s == "" ? "0" : s;
    }
};


/**
402. Remove K Digits
Medium

Given string num representing a non-negative integer num, and an integer k, return the smallest 
possible integer after removing k digits from num.

 

Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.

Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.

Example 3:

Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.
 */
