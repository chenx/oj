class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        int n = s.length();
        boolean[] DP = new boolean[n + 1];  // default to false

        HashSet<String> words = new HashSet<>();
        for (String word : wordDict) words.add(word);
        
        for (int i = 1; i <= n; ++ i) {
            // C++: substr(start, len); Java: substring(start, end).
            if (words.contains(s.substring(0, i))) {
                DP[i] = true;
            } else {
                for (int j = 1; j < i; ++ j) {
                    String t = s.substring(j, i);
                    if (DP[j] && words.contains(t)) {
                        DP[i] = true;
                        break;
                    }
                }
            }
        }
        return DP[n];
    }
}

/**
Word Break.
 */
