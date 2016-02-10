// Works. Tested. Modified from:
// https://leetcode.com/discuss/68091/share-my-4ms-c-toposort-code-beats-92-98%25-of-cpp-submissions
class Solution {
public:
    string alienOrder(vector<string>& words) {
        if (words.size() == 0) return "";
        if (words.size() == 1) return words[0];
        
        bool e[26] = {false}; //    vector<bool> e(26, false);
        int in[26] = {0}; //    vector<int> in(26, 0);
        vector<vector<int>> E(26);
        int count=0;

        // find which letters exist, and count number of different letters.
        for(int i=0;i<words.size();i++) {
            for(int j=0;j<words[i].size();j++) {
                if (e[words[i][j] - 'a'] == false) {
                    e[words[i][j] - 'a'] = true;
                    count ++;
                }
            }
        }

        // create edges between letters, and get in-degree for each letter.
        for (int i = 1; i < words.size(); ++ i) {
            for (int j=0, len = min(words[i-1].size(), words[i].size()); j < len; ++ j) {
                if (words[i-1][j] != words[i][j]) {
                    E[words[i-1][j]-'a'].push_back(words[i][j]-'a'); // add edge
                    in[words[i][j]-'a']++; // increment in-degree
                    break;
                }
            }
        }

        string R;
        while (count--) { // in each cycle, add those letters whose in-degree is 0 to result.
            bool found = false;
            for (int i=0;i<26;i++) {
                if (e[i] && in[i]==0) {
                    R += 'a' + i; //R.push_back('a'+i);
                    e[i]=false;
                    for(int j=0;j<E[i].size();j++) {
                        in[E[i][j]]--;
                    }
                    found=true;
                    break;
                }
            }
            if(!found) return ""; // conflict/cycle found. give up.
        }
        
        return R;
    }
};


/**
Alien Dictionary My Submissions Question
Difficulty: Hard
There is a new alien language which uses the latin alphabet. 
However, the order among letters are unknown to you. You receive 
a list of words from the dictionary, where words are sorted 
lexicographically by the rules of this new language. Derive the 
order of letters in this language.

For example,
Given the following words in dictionary,

[
  "wrt",
  "wrf",
  "er",
  "ett",
  "rftt"
]
The correct order is: "wertf".

Note:
You may assume all letters are in lowercase.
If the order is invalid, return an empty string.
There may be multiple valid order of letters, return any one of them is fine.
 */
