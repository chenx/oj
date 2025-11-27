// Time: O(n)
// Space: O(n)
class Solution {
public:
    string removeOuterParentheses(string s) {
        int openCount = 0;
        string result;

        for (int i = 0, left = 0; i < s.length(); ++ i) {
            if (s[i] == '(') {
                ++ openCount;
            } else {
                -- openCount;
                if (openCount == 0) {
                    // output: left to i, w/o outer parenthesis: (left+1, i-1)
                    result += s.substr(left+1, i-1 - (left+1) + 1);
                    left = i + 1;
                }
            }
        }
        return result;
    }
};


/**
1021. Remove Outermost Parentheses
Easy

A valid parentheses string is either empty "", "(" + A + ")", or A + B, where A and B are valid parentheses strings, 
and + represents string concatenation.

    For example, "", "()", "(())()", and "(()(()))" are all valid parentheses strings.

A valid parentheses string s is primitive if it is nonempty, and there does not exist a way to split it into s = A + B, 
with A and B nonempty valid parentheses strings.

Given a valid parentheses string s, consider its primitive decomposition: s = P1 + P2 + ... + Pk, where Pi are 
primitive valid parentheses strings.

Return s after removing the outermost parentheses of every primitive string in the primitive decomposition of s.

 

Example 1:

Input: s = "(()())(())"
Output: "()()()"
Explanation: 
The input string is "(()())(())", with primitive decomposition "(()())" + "(())".
After removing outer parentheses of each part, this is "()()" + "()" = "()()()".

Example 2:

Input: s = "(()())(())(()(()))"
Output: "()()()()(())"
Explanation: 
The input string is "(()())(())(()(()))", with primitive decomposition "(()())" + "(())" + "(()(()))".
After removing outer parentheses of each part, this is "()()" + "()" + "()(())" = "()()()()(())".

Example 3:

Input: s = "()()"
Output: ""
Explanation: 
The input string is "()()", with primitive decomposition "()" + "()".
After removing outer parentheses of each part, this is "" + "" = "".
 */
