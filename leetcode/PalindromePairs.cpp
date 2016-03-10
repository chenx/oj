
// Java version. Works. Tested. 
// From: https://leetcode.com/discuss/91254/java-naive-165-ms-nk-and-126-ms-nk-manacher-suffixes-prefixes
public class Solution2 {
    public List<List<Integer>> palindromePairs(String[] words) {
        Map<String, Integer> index = new HashMap<>();
        Map<String, Integer> revIndex = new HashMap<>();
        String[] revWords = new String[words.length];
        for (int i = 0; i < words.length; ++i) {
            String s = words[i];
            String r = new StringBuilder(s).reverse().toString();
            index.put(s, i);
            revIndex.put(r, i);
            revWords[i] = r;
        }
        List<List<Integer>> result = new ArrayList<>();
        result.addAll(findPairs(words, revWords, revIndex, false));
        result.addAll(findPairs(revWords, words, index, true));
        return result;
    }
    
    private static List<List<Integer>> findPairs(String[] words, String[] revWords, Map<String, Integer> revIndex, boolean reverse) {
        List<List<Integer>> result = new ArrayList<>();
        for (int i = 0; i < words.length; ++i) {
            String s = words[i];
            for (int k = reverse ? 1 : 0; k <= s.length(); ++k) { // check suffixes, <= because we allow empty words
                Integer j = revIndex.get(s.substring(k));
                if (j != null && j != i) { // reversed suffix is present in the words list
                    String prefix = s.substring(0, k); // check whether the prefix is a palindrome
                    String revPrefix = revWords[i].substring(s.length() - k);
                    if (prefix.equals(revPrefix)) {
                        result.add(reverse ? Arrays.asList(i, j) : Arrays.asList(j, i));
                    }
                }
            }
        }
        return result;
    }
}

// Should work. But times out for large input.
// Naive O(n^2).
class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> ans;
        int n = words.size();
        for (int i = 0; i < n; ++ i) {
            for (int j = 0; j < n; ++ j) {
                if (i == j) continue;
                if (isPalindrome(words[i] + words[j])) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
    
    bool isPalindrome(string s) {
        int L = 0, R = s.length() - 1;
        while (L < R) {
            if (s[L] != s[R]) return false;
            ++ L; -- R;
        }
        return true;
    }
};

/**
Palindrome Pairs
Difficulty: Hard

Given a list of unique words. Find all pairs of indices (i, j) in the given list, 
so that the concatenation of the two words, i.e. words[i] + words[j] is a palindrome.

Example 1:
Given words = ["bat", "tab", "cat"]
Return [[0, 1], [1, 0]]
The palindromes are ["battab", "tabbat"]

Example 2:
Given words = ["abcd", "dcba", "lls", "s", "sssll"]
Return [[0, 1], [1, 0], [3, 2], [2, 4]]
The palindromes are ["dcbaabcd", "abcddcba", "slls", "llssssll"]
 */
