// Works. getKey() function here is more efficient than previous ones.
class Solution3 {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> m;
        for (auto& s: strings) m[getKey(s)].push_back(s);

        vector<vector<string>> ans;
        for (auto& p : m) {
            sort(p.second.begin(), p.second.end());
            ans.push_back(p.second);
        }
        return ans;
    }

    string getKey(string& s) {
        string k;
        for (int i = 0; i < s.length(); ++ i) {
            k += (s[i] - s[0] + 26) % 26  + 'a'; 
        }
        return k;
    }
};

// Should work.
class Solution2 {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> mp;
        for (auto s : strings) {
            mp[getKey(s)].push_back(s);
        }
        
        vector<vector<string>> ans;
        for (auto p : mp) {
            sort(p.second.begin(), p.second.end());
            ans.push_back(p.second);
        }
        
        return ans;
    }
    
    // Note: "," is needed, to differentiate cases like 1,10 v.s. 11,0.
    string getKey(string s) {
        string k;
        for (int i = 0; i < s.length(); ++ i) {
            k += to_string( (s[i] - s[0] + 26) % 26 ) + ","; 
        }
        return k;
    }
};

// Works. Tested. Key is to create key for each string.
// From: https://leetcode.com/discuss/70907/c-concise-solution-using-unordered_map
class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> myMap;
        for (auto& s: strings) {  // string
            string key = "";
            for (auto& c: s)  // char
                key += to_string((c+26-s[0])%26)+',';
            myMap[key].push_back(s);
        }
        
        vector<vector<string>> res;
        for (auto it = myMap.begin(); it != myMap.end(); it++) {
            sort(it->second.begin(), (*it).second.end());
            res.push_back(it->second);
        }
        return res;
    }
};


/**
Group Shifted Strings My Submissions Question
Total Accepted: 6137 Total Submissions: 20010 Difficulty: Easy
Given a string, we can "shift" each of its letter to its successive letter, 
for example: "abc" -> "bcd". We can keep "shifting" which forms the sequence:

"abc" -> "bcd" -> ... -> "xyz"
Given a list of strings which contains only lowercase alphabets, group all 
strings that belong to the same shifting sequence.

For example, given: ["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"], 
Return:

[
  ["abc","bcd","xyz"],
  ["az","ba"],
  ["acef"],
  ["a","z"]
]

Note: For the return value, each inner list's elements must follow the lexicographic order.
 */
