class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result = "";
        int i = 0, j = 0;
        for (; i < word1.length() && j < word2.length(); ++ i, ++ j) {
            // result += word1[i] + word2[j]; // This causes error !!!
            result += word1[i];
            result += word2[j];
        }
        for (; i < word1.length(); ++ i) result += word1[i];
        for (; j < word2.length(); ++ j) result += word2[j];
        return result;
    }
};


/**
1768. Merge Strings Alternately
Easy

You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, 
starting with word1. If a string is longer than the other, append the additional letters onto the end 
of the merged string.

Return the merged string.
 */
