public class Solution {
    public int minDistance(String word1, String word2) {
        int len1 = word1.length(), len2 = word2.length();
        if (len1 == 0) return len2;
        if (len2 == 0) return len1;
        
        int[][] dp = new int[len1 + 1][len2 + 1];
        
        for (int j = 0; j <= len2; ++ j) dp[0][j] = j;
        
        for (int i = 1; i <= len1; ++ i) {
            dp[i][0] = i;  // pay attention to this value.
            for (int j = 1; j <= len2; ++ j) {
                int ins = dp[i-1][j] + 1;
                int del = dp[i][j-1] + 1;
                int rep = dp[i-1][j-1] + (word1.charAt(i-1) == word2.charAt(j-1) ? 0 : 1);
                dp[i][j] = Math.min(rep, Math.min(ins, del));
            }
        }
        
        return dp[len1][len2];
    }
}

// This also works, but times out for large input, 
// since it does not store intermediate result.
public class Solution2 {
    public int minDistance(String word1, String word2) {
        return minD(word1, word2, 0, 0);
    }
    
    private int minD(String word1, String word2, int p1, int p2) {
        if (p1 == word1.length()) return word2.length() - p2;
        if (p2 == word2.length()) return word1.length() - p1;
        
        int ins = minD(word1, word2, p1 + 1, p2) + 1;
        int del = minD(word1, word2, p1, p2 + 1) + 1;
        int rep = minD(word1, word2, p1 + 1, p2 + 1) + (word1.charAt(p1) == word2.charAt(p2) ? 0 : 1);
        return Math.min(rep, Math.min(ins, del));
    }
}

/**
Edit Distance
Difficulty: Hard

Given two words word1 and word2, find the minimum number of steps required 
to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character
 */
