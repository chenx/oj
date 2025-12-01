// Time Complexity: O(maxK⋅n), where maxK is the maximum value of k and n is the length of a given string s.
// Space Complexity: O(m+n), where m is the number of letters(a-z) and n is the number of digits(0-9) in string s.
// In worst case, the maximum size of stringStack and countStack could be m and n respectively.
class Solution2 {
public:
    string decodeString(string s) {
        stack<string> strStack;
        stack<int> numStack;

        int count = 0;
        string cur;
        for (char ch : s) {
            if (isdigit(ch)) {
                count = count * 10 + (ch - '0');
            } else if (ch == '[') {
                strStack.push(cur);
                numStack.push(count);
                cur = "";
                count = 0;
            } else if (ch == ']') {
                string str = strStack.top();
                strStack.pop();

                int ct = numStack.top();
                numStack.pop();

                for (; ct > 0; -- ct) str += cur;
                cur = str;
            } else {
                cur += ch;
            }
        }
        return cur;
    }
};


class Solution {
public:
    string decodeString(string s) {
        stack<int> st1;
        stack<string> st2;

        int k = 0;
        string cur;
        for (char c : s) {
            if (isdigit(c)) {
                k = k  * 10 + (c - '0');
            } else if (c == '[') {
                st1.push(k);
                st2.push(cur);
                k = 0;
                cur = "";
            } else if (c == ']') {
                string t = st2.top();
                st2.pop();
                int ct = st1.top(); 
                st1.pop();
                for (; ct > 0; -- ct) {
                    t += cur;
                }
                cur = t;
            } else {
                cur += c;
            }
        }
        return cur;
    }
};

/**
394. Decode String
Medium

Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is 
being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; there are no extra white spaces, square 
brackets are well-formed, etc. Furthermore, you may assume that the original data does not contain 
any digits and that digits are only for those repeat numbers, k. For example, there will not be input like 3a or 2[4].

The test cases are generated so that the length of the output will never exceed 105.
 */
