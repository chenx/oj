// Works.
class Solution3 {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) return false;

        map<char, char> m1, m2;
        int n = s.length();
        for (int i = 0; i < n; ++ i) {
            if (!m1.contains(s[i])) m1[s[i]] = t[i];
            else if (m1[s[i]] != t[i]) return false;

            if (!m2.contains(t[i])) m2[t[i]] = s[i];
            else if (m2[t[i]] != s[i]) return false;
        }
        return true;
    }
};

// This works too. Is better.
// No need to get signature, just check match situation:
// verify that each char in s matches 1 and only 1 char in t, and vice versa.
class Solution2 {
public:
    bool isIsomorphic(string s, string t) {
        return check(s, t) && check(t, s);        
    }
    
    bool check(string s, string t) {
        unordered_map<char, char> m;
        int len = s.length();
        
        for (int i = 0; i < len; ++ i) {
            if (m.find(s[i]) == m.end()) m[s[i]] = t[i];
            else if (m[s[i]] != t[i]) return false;
        }
        return true;
    }
};

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

/*
Isomorphic Strings 

Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while 
preserving the order of characters. No two characters may map to the same 
character but a character may map to itself.

For example,
Given "egg", "add", return true.

Given "foo", "bar", return false.

Given "paper", "title", return true.

Note:
You may assume both s and t have the same length.
 */
