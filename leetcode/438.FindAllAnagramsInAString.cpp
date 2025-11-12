// From: https://leetcode.com/problems/find-all-anagrams-in-a-string/editorial/
// Time: O(n^2). Compare if 2 maps are equal is O(n)
// Space: O(1)
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int ns = s.length(), np = p.length();
        if (ns < np) return ans;

        map<char, int> maps, mapp;

        for (char c : p) ++ mapp[c];

        for (int i = 0; i < ns; ++ i) {
            char c = s[i];
            ++ maps[c];

            if (i >= np) {
                int left = i - np;
                if (-- maps[s[left]] == 0) maps.erase(s[left]);
            }
            if (maps == mapp) ans.push_back(i - np + 1);
        }
        return ans;
    }
};


/**
438. Find All Anagrams in a String
Medium

Given two strings s and p, return an array of all the start indices of p's
in s. You may return the answer in any order.
 */
