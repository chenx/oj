// This works.
// Faster by combining 2 loops into 1, to avoid redundant work of getting s1L, s1R.
public class Solution2 {
    public boolean isScramble(String s1, String s2) {
        int len1 = s1.length(), len2 = s2.length();
        if (len1 != len2) return false;
        if (len1 <= 1) return s1.equals(s2);
        
        for (int i = 1; i < len1; ++ i) {
            String s1L = s1.substring(0, i), s1R = s1.substring(i),
                   s2L = s2.substring(0, i), s2R = s2.substring(i),
                   s2L2 = s2.substring(0, len1 - i), s2R2 = s2.substring(len1 - i);
                   
            if (isAnagram(s1L, s2L) && isScramble(s1L, s2L) && isScramble(s1R, s2R)) {
                return true;
            }
            if (isAnagram(s1L, s2R2) && isScramble(s1L, s2R2) && isScramble(s1R, s2L2)) {
                return true;
            }
        }

        return false;        
    }
    
    private boolean isAnagram(String a, String b) {
        char[] a1 = a.toCharArray();
        char[] b1 = b.toCharArray();
        Arrays.sort(a1);
        Arrays.sort(b1);
        a = new String(a1); // String.valueOf(a1);
        b = new String(b1); //String.valueOf(b1);
        return a.equals(b);
    }
}

// This works.
public class Solution {
    public boolean isScramble(String s1, String s2) {
        int len1 = s1.length(), len2 = s2.length();
        if (len1 != len2) return false;
        if (len1 <= 1) return s1.equals(s2);
        
        for (int i = 1; i < len1; ++ i) { // pay attention to boundary: len1, not len1-1.
            String s1L = s1.substring(0, i), s1R = s1.substring(i),
                   s2L = s2.substring(0, i), s2R = s2.substring(i);
            if (isAnagram(s1L, s2L) && 
                isScramble(s1L, s2L) && isScramble(s1R, s2R)) return true;
        }

        for (int i = 1; i < len1; ++ i) {
            String s1L = s1.substring(0, i), s1R = s1.substring(i),
                   s2L = s2.substring(0, len1 - i), s2R = s2.substring(len1 - i);
            if (isAnagram(s1L, s2R) && 
                isScramble(s1L, s2R) && isScramble(s1R, s2L)) return true;
        }

        return false;        
    }
    
    private boolean isAnagram(String a, String b) {
        char[] a1 = a.toCharArray();
        char[] b1 = b.toCharArray();
        Arrays.sort(a1);
        Arrays.sort(b1);
        a = new String(a1); // String.valueOf(a1);
        b = new String(b1); //String.valueOf(b1);
        return a.equals(b);
    }
}


/**
Scramble String
Difficulty: Hard

Given a string s1, we may represent it as a binary tree by 
partitioning it to two non-empty substrings recursively.

Below is one possible representation of s1 = "great":

    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t

To scramble the string, we may choose any non-leaf node and 
swap its two children.

For example, if we choose the node "gr" and swap its two children, 
it produces a scrambled string "rgeat".

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t

We say that "rgeat" is a scrambled string of "great".

Similarly, if we continue to swap the children of nodes "eat" 
and "at", it produces a scrambled string "rgtae".

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a

We say that "rgtae" is a scrambled string of "great".

Given two strings s1 and s2 of the same length, determine 
if s2 is a scrambled string of s1. 
 */
