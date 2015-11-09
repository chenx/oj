public class Solution {
    public int calculate(String s) {
        return evaluate(s);
    }
    
    void ignore_space(String s) {
        while (pos < s.length() && s.charAt(pos) == ' ') ++ pos;
    }
    
    int getNum(String s) {
        ignore_space(s);
        int num = 0;   
        
        while (pos < s.length()) {
            char c = s.charAt(pos);
            if (c >= '0' && c <= '9') {
                num = num * 10 + (c - '0');
                ++ pos;
            }
            else break;
        }
        
        ignore_space(s);
        return num;
    }
    
    int evaluate(String s) {
        Stack<Integer> sn = new Stack<Integer>();
        pos = 0;
        int len = s.length();
              
        sn.push(getNum(s));
        
        while (pos < len) {
            char op = s.charAt(pos);
            ++ pos;        
            int num = getNum(s);
            
            if (op == '*') { int v = sn.peek() * num; sn.pop(); sn.push(v); }
            else if (op == '/') { int v = sn.peek() / num; sn.pop(); sn.push(v); }
            else if (op == '+') { sn.push(num); }
            else if (op == '-') { sn.push(- num); }
            else { sn.push(num); }
        }
        
        int v = 0;
        while(!sn.isEmpty()) {
            v += sn.peek();
            sn.pop();
        }
        
        return v;
    }    
    
    private int pos; // position in s.
}


/**
Basic Calculator II
Difficulty: Medium

Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, +, -, *, / 
operators and empty spaces . The integer division should truncate toward zero.

You may assume that the given expression is always valid.

Some examples:

"3+2*2" = 7
" 3/2 " = 1
" 3+5 / 2 " = 5

Note: Do not use the eval built-in library function. 
 */
