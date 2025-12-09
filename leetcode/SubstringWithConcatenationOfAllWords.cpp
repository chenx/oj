// From: https://leetcode.com/problems/substring-with-concatenation-of-all-words/editorial/
// Given n as the length of s, a as the length of words, and b as the length of each word:
// Time complexity: O(a+n⋅b)
// Space complexity: O(a+b)
//
class Solution4 {
private:
    unordered_map<string, int> wordCount;
    int n;
    int wordLength;
    int substringSize;
    int k;
    void slidingWindow(int left, string &s, vector<int> &answer) {
        unordered_map<string, int> wordsFound;
        int wordsUsed = 0;
        bool excessWord = false;
        for (int right = left; right <= n - wordLength; right += wordLength) {
            string sub = s.substr(right, wordLength);
            if (!wordCount.count(sub)) {
                // Mismatched word - reset the window
                wordsFound.clear();
                wordsUsed = 0;
                excessWord = false;
                left = right + wordLength;
            } else {
                // If we reached max window size or have an excess word
                while (right - left == substringSize || excessWord) {
                    string leftmostWord = s.substr(left, wordLength);
                    left += wordLength;
                    wordsFound[leftmostWord]--;
                    if (wordsFound[leftmostWord] >= wordCount[leftmostWord]) {
                        // This word was an excess word
                        excessWord = false;
                    } else {
                        // Otherwise we actually needed it
                        wordsUsed--;
                    }
                }
                // Keep track of how many times this word occurs in the window
                wordsFound[sub]++;
                if (wordsFound[sub] <= wordCount[sub]) {
                    wordsUsed++;
                } else {
                    // Found too many instances already
                    excessWord = true;
                }
                if (wordsUsed == k && !excessWord) {
                    // Found a valid substring
                    answer.push_back(left);
                }
            }
        }
    }

public:
    vector<int> findSubstring(string s, vector<string> &words) {
        n = s.length();
        k = words.size();
        wordLength = words[0].length();
        substringSize = wordLength * k;
        for (string &word : words) {
            wordCount[word]++;
        }
        vector<int> answer;
        for (int i = 0; i < wordLength; i++) {
            slidingWindow(i, s, answer);
        }
        return answer;
    }
};


//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 1/4/2013
// @Last modified: 1/4/2013
//

// Works too. 
class Solution3 {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if (s.length() == 0 || words.size() == 0) return ans;
        
        int n = words.size(), lenw = words[0].length(), total = n * lenw;;
        map<string, int> toFind;
        for (auto w : words) toFind[w] ++;
        
        for (int i = 0, end = s.length() - total; i <= end; ++ i) {
            map<string, int> found;
            
            int j = 0;
            for (; j < total; j += lenw) {
                string t = s.substr(i + j, lenw);
                if (toFind[t] == 0) break;
                if (++ found[t] > toFind[t]) break;
            }
            if (j == total) ans.push_back(i);
        }
        
        return ans;
    }
};

// This works too. Basically the same as Solution.
class Solution2 {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> ans;
        if (L.size() == 0) return ans;
        int N = L[0].length();
        
        unordered_map<string, int> ct;
        for (int i = 0; i < L.size(); ++ i) ct[L[i]] ++;
        
        for (int i = 0, len = S.length() - N * L.size(); i <= len; ++ i) {
            unordered_map<string, int> stat;
            int total = 0;
            for (int j = i, lenj = S.length(); j < lenj; j += N) {
                string s = S.substr(j, N);
                if (stat[s] == ct[s]) break;
                stat[s] ++;
                total ++;
            }
            if (total == L.size()) {
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};

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

