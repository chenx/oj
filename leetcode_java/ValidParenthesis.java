public class Solution {
    public boolean isValid(String s) {
        int n = s.length();
        Stack<Character> st = new Stack<Character>();
        
        for (int i = 0; i < n; ++ i) {
            char c = s.charAt(i);
            switch (c) {
                case '(':
                case '{':
                case '[':
                    st.push(c);
                    break;
                case ']':
                    if (! st.isEmpty() && st.peek() == '[') st.pop();
                    else return false;
                    break;
                case '}':
                    if (! st.isEmpty() && st.peek() == '{') st.pop();
                    else return false;
                    break;
                case ')':
                    if (! st.isEmpty() && st.peek() == '(') st.pop();
                    else return false;
                    break;
            }
        }
        
        return st.isEmpty();
    }
}

/**
Valid Parentheses
Difficulty: Easy

Given a string containing just the characters '(', ')', '{', '}', '[' and ']', 
determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid 
but "(]" and "([)]" are not.
 */
