// This works too. But sometimes times out (other times can pass).
public class Solution {
    public int lengthOfLongestSubstring(String s) {
        int mlen = 0, len = 0;
        HashMap<Character, Integer> h = new HashMap<Character, Integer>();
        
        for (int i = 0, n = s.length(); i < n; ++ i) {
            if (! h.containsKey(s.charAt(i))) {
                h.put(s.charAt(i), i + 1);
                ++ len;
                mlen = Math.max(mlen, len);
            }
            else {
                i = h.get(s.charAt(i)) - 1;
                h.clear();
                len = 0;
            }
        }
        
        return mlen;        
    }
}

// This works.
public class Solution {
    public int lengthOfLongestSubstring(String s) {
        int mlen = 0, len = 0;
        int[] h = new int[256];
        Arrays.fill(h, 0);
        
        for (int i = 0, n = s.length(); i < n; ++ i) {
            if (h[s.charAt(i)] == 0) {
                h[s.charAt(i)] = i + 1;
                ++ len;
                mlen = Math.max(mlen, len);
            }
            else {
                i = h[s.charAt(i)] - 1;
                Arrays.fill(h, 0);
                len = 0;
            }
        }
        
        return mlen;        
    }
}

/**
Longest Substring Without Repeating Characters
Difficulty: Medium

Given a string, find the length of the longest substring without 
repeating characters. For example, the longest substring without 
repeating letters for "abcabcbb" is "abc", which the length is 3. 
For "bbbbb" the longest substring is "b", with the length of 1.
 */
