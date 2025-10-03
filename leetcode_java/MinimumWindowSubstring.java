class Solution {
    public String minWindow(String s, String t) {
        int m = s.length(), n = t.length();
        if (m < n) return "";

        HashMap<Character, Integer> toFind = new HashMap<>();
        HashMap<Character, Integer> found = new HashMap<>();
        
        for (int i = 0; i < n; ++ i) {
            char c = t.charAt(i);
            toFind.put(c, toFind.get(c) == null ? 1 : (toFind.get(c) + 1));
        }
        
        int total = 0, minLen = 0, pos = 0;
        for (int i = 0, start = 0; i < m; ++ i) {
            char c = s.charAt(i);
            found.put(c, found.get(c) == null ? 1 : (found.get(c) + 1));
            if (toFind.get(c) == null) continue;
            if (found.get(c) <= toFind.get(c)) total += 1;
            
            while (total == n) {
                char d = s.charAt(start);
                if (toFind.get(d) == null || found.get(d) > toFind.get(d)) {
                    ++ start;
                    found.put(d, found.get(d) - 1);
                } else {
                    int len = i - start + 1;
                    if (minLen == 0 || minLen > len) {
                        minLen = len;
                        pos = start;
                    }
                    break;
                }
            }
        }
        return s.substring(pos, pos + minLen);
    }
}

/**
Minimum Window Substring

Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that 
every character in t (including duplicates) is included in the window. If there is no such substring, return 
the empty string "".
 */
