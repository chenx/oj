public class Solution {
    public boolean isIsomorphic(String s, String t) {
        return check(s, t) && check(t, s);        
    }
    
    private boolean check(String s, String t) {
        HashMap<Character, Character> m = new HashMap<Character, Character>();
        int len = s.length();
        
        for (int i = 0; i < len; ++ i) {
            Character a = s.charAt(i);
            Character b = t.charAt(i);
            if (! m.containsKey(a)) m.put(a, b);
            else if (m.get(a) != b) return false;
        }
        return true;
    }
}

/**
Isomorphic Strings 

Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while 
preserving the order of characters. No two characters may map to the same 
character but a character may map to itself.

For example,
Given "egg", "add", return true.

Given "foo", "bar", return false.

Given "paper", "title", return true.

Note:
You may assume both s and t have the same length.
 */
