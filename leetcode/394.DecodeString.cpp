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
