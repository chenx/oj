// This works.
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;
        
        vector<char> letters;
        unordered_map<char, vector<int>> pos; // pos of char in letters array.
        getSignature(s, letters, pos);        

        vector<char> letters2;
        unordered_map<char, vector<int>> pos2;
        getSignature(t, letters2, pos2);        

        if (letters.size() != letters2.size()) return false;
        
        for (int i = 0, n = letters.size(); i < n; ++ i) {
            if (pos[letters[i]] != pos2[letters2[i]]) return false; // vector comparison.
        }

        return true;
    }
    
    // for each new letter, store it into letters; store letter's position in pos.
    void getSignature(string s, vector<char> &letters, unordered_map<char, vector<int>> &pos) {
        for (int i = 0, n = s.size(); i < n; ++ i) {
            if (pos[s[i]].size() == 0) {
                letters.push_back(s[i]);
            }
            pos[s[i]].push_back(i+1);
        }
    }
};
