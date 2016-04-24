class Solution {
public:    
    /**
     * @param strs: A list of strings
     * @return: A list of strings
     */
    vector<string> anagrams(vector<string> &strs) {
        vector<string> ans;
        int n = strs.size();
        if (n == 0) return ans;
        
        unordered_map<string, vector<string>> m;
        
        for (auto s : strs) {
            m[getKey(s)].push_back(s);
        }
        
        for (auto e : m) {
            if (e.second.size() > 1) {
                for (auto a : e.second)
                    ans.push_back(a);
            }
        }
        
        return ans;
    }
    
    string getKey(string s) {
        sort(s.begin(), s.end());
        return s;
    }
};


/**
Anagrams

Given an array of strings, return all groups of strings that are anagrams.

Notice

All inputs will be in lower-case
Example

Given ["lint", "intl", "inlt", "code"], return ["lint", "inlt", "intl"].

Given ["ab", "ba", "cd", "dc", "e"], return ["ab", "ba", "cd", "dc"].

 */
