//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 1/9/2013
// @Last modified: 1/9/2013
//

// Also works. But Solution4 is more clear.
class Solution5 {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> toFind, found;
        for (char ch : t) toFind[ch] ++;

        int total = 0, minLen = -1, startIndex = 0;
        for (int i = 0, left = 0; i < s.length(); ++ i) {
            if (++ found[s[i]] <= toFind[s[i]]) ++ total;

            while (total == t.length()) {
                int len = i - left + 1;
                if (minLen == -1 || minLen > len) {
                    minLen = len;
                    startIndex = left;
                }

                if (toFind[s[left]] >= found[s[left]]) break;
                found[s[left]] --;
                ++ left;
            }
        }
        return minLen == -1 ? "" : s.substr(startIndex, minLen);
    }
};

// Works.
class Solution4 {
public:
    string minWindow(string s, string t) {
        int minLen = 0, total = 0, begin = 0, minStart = 0;
        unordered_map<char, int> toFind, found;
        for (char c : t) ++ toFind[c];

        for (int i = 0; i < s.length(); ++ i) {
            if (++ found[s[i]] <= toFind[s[i]]) ++ total;

            if (total == t.length()) {
                // while (toFind[s[begin]] == 0 || found[s[begin]] > toFind[s[begin]]) {
                while (found[s[begin]] > toFind[s[begin]]) {
                    -- found[s[begin]];
                    ++ begin;
                }
                if (minLen == 0 || minLen > i - begin + 1) {
                    minLen = i - begin + 1;
                    minStart = begin;
                }
            }
        }
        return s.substr(minStart, minLen);
    }
};

// Works. Optimized.
class Solution3 {
public:
    string minWindow(string s, string t) {
        int minLen = -1, minStart = -1, total = 0;
        map<char, int> toFind, found;
        for (auto c : t) toFind[c] ++;

        for (int begin = 0, end = 0; end < s.length(); ++ end) {
            char e = s[end];
            if (toFind[e] == 0) continue;
            if (++ found[e] <= toFind[e]) ++ total;
            
            if (total == t.length()) {
                char b = s[begin];
                while (toFind[b] == 0 || found[b] > toFind[b]) {
                    if (found[b] > toFind[b]) -- found[b];
                    b = s[++ begin];
                }
            
                if (minLen == -1 || minLen > end - begin + 1) {
                    minLen = end - begin + 1;
                    minStart = begin;
                }
            }
        }
        
        return (minLen == -1) ? "" : s.substr(minStart, minLen);
    }
};

// Works too. Basically same as Solution, with shorter var names.
class Solution2 {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> toFind, found;
        for (char c : t) toFind[c] ++;
        
        int ct = t.length(), found_ct = 0,
            minStart = -1, minLen = s.length() + 1;
        for (int begin = 0, end = 0; end < s.length(); ++ end) {
            char e = s[end];
            if (toFind[e] == 0) continue;

            found[e] ++;
            if (found[e] <= toFind[e]) ++ found_ct;

            if (found_ct == ct) {
                char b = s[begin];
                while (toFind[b] == 0 || found[b] > toFind[b]) {
                    if (found[b] > toFind[b]) -- found[b];
                    ++ begin;
                    b = s[begin];
                }
                    
                if (end - begin + 1 < minLen) {
                    minLen = end - begin + 1;
                    minStart = begin; 
                }
            }  
        }
        
        if (minStart == -1) return "";
        else return s.substr(minStart, minLen);
    }
};

// This works! O(n), since begin and end are advanced at most n times each.
// From: http://leetcode.com/2010/11/finding-minimum-window-in-s-which.html
class Solution {
public:
    string minWindow(string S, string T) {
        int needToFind[256] = {0};
        int hasFound[256] = {0};
        int count = 0; // number of chars in T that have been found.
        int maxwin_len = S.length() + 1, maxwin_start = 0, maxwin_end = 0;
        
        // get stats on chars need to find.
        for (int i = 0; i < T.length(); ++ i) {
            ++ needToFind[T[i]];
        }
        
        for (int begin = 0, end = 0; end < S.length(); ++ end) {
            if (needToFind[S[end]] == 0) continue;
            ++ hasFound[S[end]];
            if (hasFound[S[end]] <= needToFind[S[end]]) ++ count;
            
            if (count == T.length()) {
                // advance begin ONLY when hasFound[S[begin]] > needToFind[S[begin]] or S[begin] is not in T.
                while (needToFind[S[begin]] == 0 || hasFound[S[begin]] > needToFind[S[begin]]) {
                    if (hasFound[S[begin]] > needToFind[S[begin]]) -- hasFound[S[begin]];
                    ++ begin;
                }
            
                if (end - begin + 1 < maxwin_len) {
                    maxwin_len = end - begin + 1;
                    maxwin_start = begin;
                    maxwin_end = end;
                }
            }
        }
        
        // 'if (count == T.length())' also works here.
        if (maxwin_len != S.length() + 1) return S.substr(maxwin_start, maxwin_len);
        else return "";
    }
};

// This does not work yet.
class Solution0 {
public:
    string minWindow(string S, string T) {
        if (T.length() == 1 && S.find(T) != string::npos) return T;
        if (S.length() < T.length()) return "";
        
        string s = "";
        set<int> pos_set;
        int pos, start = -1, end = -1, minwin = -1;
        // get first positions of each char of T in S.
        for (int i = 0; i < T.length(); ++ i) {
            pos = S.find(T[i]);
            if (pos == string::npos) return "";
            if (pos_set.find(pos) == pos_set.end()) pos_set.insert(pos);
        }
        
        get_minwin(pos_set, start, end, minwin);
        
        for (int i = end + 1; i < S.length(); ++ i) {
            int j = start;
            pos_set.erase(pos_set.begin());
            pos = S.find(S[j]);
            if (pos == string::npos) break;
            if (pos_set.find(pos) == pos_set.end()) {
                pos_set.insert(pos);
                get_minwin(pos_set, start, end, minwin);
            }
        }
        
        return S.substr(start, end - start + 1);
    }
    
    void get_minwin(set<int> &pos_set, int &start, int &end, int &minwin) {
        set<int>::iterator e_start = pos_set.begin();
        set<int>::iterator e_end = pos_set.end();
        -- e_end;
        
        //if (e_start == e_end) return;
        
        if (minwin == -1 || *e_end - *e_start < minwin) {
            start = *e_start;
            end = *e_end;
            minwin = end - start;
        }        
    }
};


/**
Minimum Window Substring
Difficulty: Hard

Given a string S and a string T, find the minimum window in S 
which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"

Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, 
return the empty string "".

If there are multiple such windows, you are guaranteed that 
there will always be only one unique minimum window in S. 
 */





