// See: classic solution: http://www.engr.mun.ca/~theo/Misc/exp_parsing.htm
// EBNF:
// E = T | { T +- T }
// T = F | { F */ F }
// F = (E) | num
// This works for both Basic Calculator I and II.
public class Solution {
    public int calculate(String s) {
        this.s = s;
        return E();
    }
    
    void err(String msg) {
        System.out.println(msg);
        //throw new Exception(msg);
    }
    void ignore_space() { 
        while (! eof() && s.charAt(pos) == ' ') ++ pos;
    }
    boolean isDigit(char c) { 
        return c >= '0' && c <= '9'; 
    }
    boolean eof() {
        return pos == s.length();
    }
    
    int getNum() {
        int num = 0;
        while (! eof() && isDigit(s.charAt(pos))) {
            num = num * 10 + (s.charAt(pos) - '0');
            ++ pos;
        }
        
        return num;
    }
    
    int F() {
        ignore_space();
        if (eof()) return 0;
        
        char c = s.charAt(pos);
        if (c == '(') {
            ++ pos;
            int v = E();
            if (!eof() && s.charAt(pos) == ')') ++ pos; 
            else err("missing )"); 
            return v;
        }
        else if (isDigit(c)) {
            return getNum(); 
        }
        else {
            err("F(): invalid input");
            return 0;
        }
    }
    
    int T() {
        int v = F();
        
        ignore_space();
        if (eof()) return v;
        char op = s.charAt(pos);
        while (op == '*' || op == '/') {
            ++ pos;
            int u = F();
            if (op == '*') v *= u;
            else {
                if (u == 0) err("T(): divide by 0 error");
                else v /= u;
            }
            
            ignore_space();
            if (eof()) return v;
            op = s.charAt(pos);
        }
        
        return v;
    }
    
    int E() {
        int v = T();
        
        ignore_space();
        if (eof()) return v;
        char op = s.charAt(pos);
        while (op == '+' || op == '-') {
            ++ pos;
            int u = T();
            if (op == '+') v += u;
            else v -= u;
            
            ignore_space();
            if (eof()) return v;
            op = s.charAt(pos);
        }
        
        return v;
    }    
    
    private String s;
    private int pos; // position in s.
}

// Simplified shunting-yard algorithm.
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
