// Should work. Tested locally. Use "==" instead of "a.compare(b) == 0"
class Solution4 {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int index1 = -1, index2 = -1, minDist = INT_MAX;

        for (int i = 0; i < words.size(); ++ i) {
            if (words[i] == word1) index1 = i;
            else if (words[i] == word2) index2 = i;

            if (index1 != -1 && index2 != -1)
                minDist = min(minDist, abs(index1 - index2));
        }

        return minDist;
    }
};

// Works. Tested. Much simpler.
// From: https://leetcode.com/discuss/84035/c-easy-understand-solution
class Solution3 {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int index1 = -1, index2 = -1, min_distance = INT_MAX;
        for(int i = 0; i < words.size(); ++i){
            if(words[i].compare(word1) == 0) index1 = i;
            else if(words[i].compare(word2) == 0) index2 = i;
            else continue;
            
            if(index1 != -1 && index2 != -1)
                min_distance = min(min_distance, abs(index1 - index2));
        }
        return min_distance;
    }
};


// This works. Tested. 
// Modified from https://leetcode.com/discuss/86267/sharing-my-60ms-c-solution
class Solution2 {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        unordered_map<string, vector<int>> myMap;

        int n = words.size();
        int i, j;
        for(i=0; i<n; i++)
            myMap[words[i]].push_back(i);

        vector<int> index1=myMap[word1];
        vector<int> index2=myMap[word2];
        int distance = INT_MAX;
        for(i=0; i<index1.size(); i++)
            for(j=0; j<index2.size(); j++)
                distance = min(distance, abs(index1[i]-index2[j]));

        return distance;
    }
};


// Works. Tested. By: XC
// Adapted from the solution to MinimumWindowSubstring.cpp
class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        unordered_map<string, int> toFind, found;
        toFind[word1] = 1;
        toFind[word2] = 1;
        
        int ct = 2, found_ct = 0, minLen = words.size() + 1;
        for (int begin = 0, end = 0; end < words.size(); ++ end) {
            string e = words[end];
            if (toFind[e] == 0) continue;

            found[e] ++;
            if (found[e] <= toFind[e]) ++ found_ct;

            if (found_ct == ct) {
                string b = words[begin];
                while (toFind[b] == 0 || found[b] > toFind[b]) {
                    if (found[b] > toFind[b]) -- found[b];
                    ++ begin;
                    b = words[begin];
                }
                    
                if (end - begin < minLen) {
                    minLen = end - begin;
                }
            }  
        }
        
        return minLen;
    }
};


/**
Shortest Word Distance
Difficulty: Easy

Given a list of words and two words word1 and word2, return the 
shortest distance between these two words in the list.

For example,
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Given word1 = “coding”, word2 = “practice”, return 3.
Given word1 = "makes", word2 = "coding", return 1.

Note:
You may assume that word1 does not equal to word2, and word1 and 
word2 are both in the list.
 */
