// Works. Best. Same for the case of K.
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        unordered_map<char, int> m;
        int maxLen = 0;

        for (int i = 0, j = 0, n = s.length(); i < n; i ++) {
            m[s[i]] ++;
            while (m.size() > 2) {
                m[s[j]] --;
                if (m[s[j]] == 0) m.erase(s[j]);
                j ++;
            }
            maxLen = max(maxLen, i - j + 1);
        }
        return maxLen;
    }
};

// This works. Tested.
// From leetcode solution.
// Note: 1) it's easy to extend from 2 to k. 2) to find minlen is also easy.
int LongestSubstrWithAtMost2DistinctChar(string s) {
    unordered_map<char, int> ct;
    int i = 0, numDist = 0, maxlen = 0;
    for (int j = 0, n = s.length(); j < n; ++ j) {
        if (ct[s[j]] == 0) ++ numDist;
        ++ ct[s[j]];
        while (numDist > 2) {
            -- ct[s[i]];
            if (ct[s[i]] == 0) -- numDist;
            ++ i;
        }
        maxlen = max(maxlen, j - i + 1);
    }
    return maxlen;
}

/**
Given a string S, find the length of the longest substring T that contains at most 2 distinct characters.

For example,

Given S = "eceba", T is "ece" with max length 3.
 */
