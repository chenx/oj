// This works.
// Note how an int wrap object is used to pass by reference.
// Note Integer is an object but immutable, so cannot be used here.
public class Solution {
    public int compareVersion(String version1, String version2) {
        int n1 = version1.length(), n2 = version2.length(), v1, v2;
        Inte p1 = new Inte(0), p2 = new Inte(0);
        
        while (p1.p < n1 && p2.p < n2) {
            v1 = getNext(version1, p1);
            v2 = getNext(version2, p2);
            
            if (v1 < v2) return -1;
            else if (v1 > v2) return 1;
        }
        
        while (p1.p < n1) {
            v1 = getNext(version1, p1);
            if (v1 > 0) return 1; 
        }
        while (p2.p < n2) {
            v2 = getNext(version2, p2);
            if (v2 > 0) return -1;
        }

        return 0;
    }
    
    private int getNext(String s, Inte p) {
        int n = s.length(), v = 0;
        while (p.p < n && s.charAt(p.p) != '.') {
            v = v * 10 + (s.charAt(p.p) - '0');
            ++ p.p;
        }
        if (p.p < n && s.charAt(p.p) == '.') ++ p.p; // Note need this.
        return v;
    }
    
    private class Inte {
        public int p;
        public Inte(int p) { this.p = p; }
    }
}

/**
Compare Version Numbers
Difficulty: Easy

Compare two version numbers version1 and version2.
If version1 > version2 return 1, if version1 < version2 return -1, 
otherwise return 0.

You may assume that the version strings are non-empty and contain 
only digits and the . character.

The . character does not represent a decimal point and is used to 
separate number sequences.

For instance, 2.5 is not "two and a half" or "half way to version 
three", it is the fifth second-level revision of the second first-level revision.

Here is an example of version numbers ordering:

0.1 < 1.1 < 1.2 < 13.37
 */
