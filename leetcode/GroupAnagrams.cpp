class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        
        unordered_map<string, vector<string>> m;
        for (int i = 0, len = strs.size(); i < len; ++ i) {
            string key = strs[i];
            sort(key.begin(), key.end());
            m[key].push_back(strs[i]);
        }
        
        for (unordered_map<string, vector<string>>::iterator it = m.begin(); 
                it != m.end(); ++ it) {
            vector<string> &v = (*it).second;
            sort(v.begin(), v.end());
            ans.push_back(v);
        }
        
        return ans;
    }
};

/**
Group Anagrams
Difficulty: Medium

Given an array of strings, group anagrams together.

For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"],
Return:

[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]

Note:

    For the return value, each inner list's elements must follow the lexicographic order.
    All inputs will be in lower-case.
 */
