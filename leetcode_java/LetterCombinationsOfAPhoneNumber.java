public class Solution {
    public List<String> letterCombinations(String digits) {
        List<String> ans = new ArrayList<String>();
        if (digits.equals("")) return ans;
        
        String s = "";
        getComb(ans, digits, 0, s);
        return ans;
    }
    
    private void getComb(List<String> ans, String digits, int pos, String s) {
        if (pos == digits.length()) {
            ans.add(s);
            return;
        }
        
        char c = digits.charAt(pos);
        if (c >= '2' && c <= '9') {
            String v = m[c - '2'];
            for (int i = 0, len = v.length(); i < len; ++ i) {
                getComb(ans, digits, pos + 1, s + v.charAt(i));
            }
        } 
        else {
            getComb(ans, digits, pos + 1, s + c);
        }
    }
    
    // pay attention to the declaration grammar.
    private String[] m = new String[]{"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
}


/**
Letter Combinations of a Phone Number
Difficulty: Medium

Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

Note:
Although the above answer is in lexicographical order, your answer could be in any order you want. 
 */
