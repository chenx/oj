// This works.
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
