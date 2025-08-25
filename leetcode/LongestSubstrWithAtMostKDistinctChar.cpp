// Tested locally.
class Solution2 {
public:
    int LongestSubstrWithAtMostKDistinctChar(string s, int k) {
        map<char, int> count;
        int maxLen = 0;

        for (int i = 0, j = 0; i < s.length(); ++ i) {
            ++ count[s[i]];
            while (count.size() > k) {
                if (-- count[s[j]] == 0) count.erase(s[j]);
                ++ j;
            }
            maxLen = max(maxLen, i - j + 1);
        }
        return maxLen;
    }
};

// This should work. Not tested.
// Note: 
// 1) simply extended from 2 to k. See:
//    https://github.com/chenx/oj/blob/master/leetcode/LongestSubstrWithAtMost2DistinctChar.cpp
//    https://leetcode.com/discuss/95559/simple-sliding-window-apporach
// 2) to find minlen is also easy.
int lengthOfLongestSubstringKDistinct(string s, int k) {
    unordered_map<char, int> ct;
    int i = 0, numDist = 0, maxlen = 0;
    for (int j = 0, n = s.length(); j < n; ++ j) {
        if (ct[s[j]] == 0) ++ numDist;
        ++ ct[s[j]];
        while (numDist > k) {
            -- ct[s[i]];
            if (ct[s[i]] == 0) -- numDist;
            ++ i;
        }
        maxlen = max(maxlen, j - i + 1);
    }
    return maxlen;
}

/**
Given a string S, find the length of the longest substring T that contains at most k distinct characters.
For example, k = 2
Given S = "eceba", T is "ece" with max length 3.
 */
