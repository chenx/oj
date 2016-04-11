// Works. Slightly modified from Solution3.
class Solution4 {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int n = words.size();
        unordered_map<string, int> index, revIndex;
        vector<string> revWords(n);
        
        for (int i = 0; i < n; ++ i) {
            string w = words[i], r = w;
            reverse(r.begin(), r.end());
            
            index[w] = revIndex[r] = i;
            revWords[i] = r;
        }
        
        vector<vector<int>> ans;
        find(ans, words, revWords, revIndex, false);
        find(ans, revWords, words, index, true);
        return ans;
    }
    
    void find(vector<vector<int>> & ans, vector<string> & words, 
        vector<string> & revWords, unordered_map<string, int> & revIndex, bool rev) {
            
        for (int i = 0; i < words.size(); ++ i) {
            string w = words[i];
            for (int k = rev ? 1 : 0; k <= w.length(); ++ k) {
                if (revIndex.find(w.substr(k)) == revIndex.end()) continue;
                int j = revIndex[w.substr(k)]; // found suffix
                if (j != i) {
                    string prefix = w.substr(0, k),  // check prefix.
                           revPrefix = revWords[i].substr(w.length() - k);
                    if (prefix == revPrefix) {
                        ans.push_back(rev ? vector<int>({i, j}) : vector<int>({j, i}));
                    }
                }
            }
        }    
    }
};

// Works. Tested. Translated from Java version Solution2.
class Solution3 {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> index;
        unordered_map<string, int> revIndex;
        vector<string> revWords(words.size());
        for (int i = 0; i < words.size(); ++ i) {
            string s = words[i], r = s;
            reverse(r.begin(), r.end());
            
            index[s] = i;
            revIndex[r] = i;
            revWords[i] = r;
        }
        vector<vector<int>> result;
        findPairs(result, words, revWords, revIndex, false);
        findPairs(result, revWords, words, index, true);
        return result;
    }
    
    void findPairs(vector<vector<int>> & result, vector<string>& words, vector<string>& revWords, 
            unordered_map<string, int> & revIndex, bool reverse) {

        for (int i = 0; i < words.size(); ++i) {
            string s = words[i];
            for (int k = reverse ? 1 : 0; k <= s.length(); ++ k) { // check suffixes, <= because we allow empty words
                if (revIndex.find(s.substr(k)) == revIndex.end()) continue;
                int j = revIndex[s.substr(k)];
                if (j != i) { // reversed suffix is present in the words list
                    string prefix = s.substr(0, k); // check whether the prefix is a palindrome
                    string revPrefix = revWords[i].substr(s.length() - k);
                    if (prefix == revPrefix) {
                        result.push_back(reverse ? vector<int>({i, j}) : vector<int>({j, i}));
                    }
                }
            }
        }
    }
};

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
