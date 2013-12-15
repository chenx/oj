//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 1/4/2013
// @Last modified: 1/4/2013
//

class Solution {
public:
    // Method from http://blog.csdn.net/maqingli87/article/details/8009972:
    // There may be duplicates in L.
    // First get a count of each word in L and store in a map words.
    // Then, starting from positions i = 0, 1, 2, ... in S,
    // for each candidate string str of given word length, 
    //     if it's not found in map words, break;
    //     else, increase the count of str in map stats;
    //     if count of str in stats > str's count in words, break since it's more than provided in L.
    // if all strings in words are matched at the end of cycle, push curernt i to result set.
    //
    // This solution well utilizes data structure map<string, int>, 
    // which simplifies solution significantly.
    //
    // This method is better than the one on leetcode at
    // http://heartfire.cc/wp/substring-with-concatenation-of-all-words/
    //
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> vs;
        if (L.size() == 0) return vs;
        
        // scan L to get each word's count.
        map<string, int> words;
        for (int i = 0; i < L.size(); ++ i) {
            ++ words[L[i]];
        }
        
        int lenw = L[0].length(); // word length.
        int len = S.length() - L.size() * lenw;
        int i, j;
        string str;
                
        for (i = 0; i <= len; ++ i) { // NOTE: must be i <= len!!!
            // scan all L.size() number of substrings of length lenw, starting from i in S.
            map<string, int> stats;
            for (j = 0; j < L.size(); ++ j) {
                // position of substring to be found in L: i + j * lenw.
                str = S.substr(i + j * lenw, lenw);
                if (words[str] == 0) break; // not found in L (i.e., in words)
                ++ stats[str];
                if (stats[str] > words[str]) break; // found more copies than in words.
            }
            if (j == L.size()) vs.push_back(i);
        }
        
        return vs;
    }
};


/*
Problem:

 You are given a string, S, and a list of words, L, that are all of the same 
 length. Find all starting indices of substring(s) in S that is a concatenation 
 of each word in L exactly once and without any intervening characters.

For example, given:
S: "barfoothefoobarman"
L: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter). 
 */
