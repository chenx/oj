// For this analysis, we will assume that we are using Java.
// Time complexity: O(m⋅(n2⋅k−n⋅k2))
// Space complexity: O(n)
class Solution {
public:
    string addBoldTag(string s, vector<string>& words) {
        int n = s.size();
        vector<bool> bold(n);
        
        for (string word: words) {
            int start = s.find(word);
            while (start != -1) {
                for (int i = start; i < start + word.size(); i++) {
                    bold[i] = true;
                }
                
                start = s.find(word, start + 1);
            }
        }
        
        string openTag = "<b>";
        string closeTag = "</b>";
        string ans = "";
        
        for (int i = 0; i < n; i++) {
            if (bold[i] && (i == 0 || !bold[i - 1])) {
                ans += openTag;
            }
            
            ans += s[i];
            
            if (bold[i] && (i == n - 1 || !bold[i + 1])) {
                ans += closeTag;
            }
        }
        
        return ans;
    }
};

/**
616. Add Bold Tag in String
Medium

You are given a string s and an array of strings words.

You should add a closed pair of bold tag <b> and </b> to wrap the substrings in s that exist in words.

    If two such substrings overlap, you should wrap them together with only one pair of closed bold-tag.
    If two substrings wrapped by bold tags are consecutive, you should combine them.

Return s after adding the bold tags.
 */
