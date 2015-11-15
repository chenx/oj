public class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> ans = new ArrayList<String>();
        gen(ans, n, 0, 0, "");
        return ans;
    }
    
    void gen(List<String> ans, int n, int L, int R, String p) {
        if (L == n && R == n) {
            ans.add(p);
            return;
        }
        
        // Order of these 2 don't matter.
        if (L < n) {
            gen(ans, n, L + 1, R, p + "(");
        }
        if (L > R) {
            gen(ans, n, L, R + 1, p + ")");
        }
    }
}

/**
Generate Parentheses
Difficulty: Medium

Given n pairs of parentheses, write a function to generate 
all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()" 
 */
