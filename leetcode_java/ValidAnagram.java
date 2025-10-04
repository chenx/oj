// This works.
class Solution2 {
    public boolean isAnagram(String s, String t) {
        char[] a = s.toCharArray(), b = t.toCharArray();
        Arrays.sort(a);
        Arrays.sort(b);
        
        String s2 = String.valueOf(a);
        String t2 = String.valueOf(b);
        // String s2 = Arrays.toString(a);
        // String t2 = Arrays.toString(b);
        return s2.equals(t2);
    }
}

public class Solution {
    public boolean isAnagram(String s, String t) {
        return sortStr(s).equals(sortStr(t));
    }
    
    private String sortStr(String s) {
        if (s.equals("")) return "";
        char[] a = s.toCharArray();
        Arrays.sort(a);
        return new String(a);
    }
}

/**
Valid Anagram
Total Accepted: 31881 Total Submissions: 85760 Difficulty: Easy

Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?
 */
