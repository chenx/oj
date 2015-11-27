public class Solution {
    public boolean isNumber(String s) {
        p = 0; 
        len = s.length();
        this.s = s;

        while (isspace(next())) ++ p;
        if (p == len) return false;
        
        if (next() == '-' || next() == '+') ++ p;
        
        if (isdigit(next())) {
            while (isdigit(next())) { ++ p; }
            if (next() == '.') ++ p;
            while (isdigit(next())) { ++ p; }
        }
        else if (next() == '.') {
            ++ p;
            if (! isdigit(next())) return false;
            while (isdigit(next())) { ++ p; }
        }
        else { return false; }
        
        if (next() == 'e') {
            ++ p;
            if (next() == '+' || next() == '-') ++ p;
            if (! isdigit(next())) return false;
            while (isdigit(next())) { ++ p; }
        }
        
        while (isspace(next())) ++ p;
        return p == len;
    }
    
    char next() {
        return (p < len) ? s.charAt(p) : 0;
    }
    
    boolean isspace(char c) {
        return c == ' ';    
    }
    
    boolean isdigit(char c) {
        return c >= '0' && c <= '9';        
    }
    
    private String s;
    private int p, len;
}

/**
Valid Number
Difficulty: Hard

Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true

Note: It is intended for the problem statement to be ambiguous. 
You should gather all requirements up front before implementing one. 
 */
