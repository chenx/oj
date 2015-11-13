public class Solution {
    public int evalRPN(String[] tokens) {
        Stack<Integer> s = new Stack<Integer>();
        int a, b;
        
        for (int i = 0, len = tokens.length; i < len; ++ i) {
            String v = tokens[i];
            
            if (v.equals("+") || v.equals("-") || v.equals("*") || v.equals("/")) {
                b = s.peek(); s.pop();
                a = s.peek(); s.pop();
                
                if (v.equals("+")) s.push(a + b);
                else if (v.equals("-")) s.push(a - b);
                else if (v.equals("*")) s.push(a * b);
                else if (v.equals("/")) s.push(a / b);
            }
            else {
                s.push(Integer.parseInt(v));
            }
        }
        
        return s.peek();
    }
}

/**
Evaluate Reverse Polish Notation
Difficulty: Medium

Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:

  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6

 */
