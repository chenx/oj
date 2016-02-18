// Works. Tested. By: XC
// Compared to solution to ShortestWordDistance.cpp, the only difference
// is added an overloaded function to handle the case when 2 words equal.
class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        if (word1 == word2) return shortestWordDistance(words, word1);
        
        int index1 = -1, index2 = -1, min_distance = INT_MAX;
        for(int i = 0; i < words.size(); ++ i) {
            if(words[i].compare(word1) == 0) index1 = i;
            else if(words[i].compare(word2) == 0) index2 = i;
            else continue;
            
            if(index1 != -1 && index2 != -1)
                min_distance = min(min_distance, abs(index1 - index2));
        }
        return min_distance;
    }
    
    int shortestWordDistance(vector<string>& words, string word) {
        int index = -1, min_dist = INT_MAX;
        for (int i = 0; i < words.size(); ++ i) {
            if (words[i] == word) {
                if (index != -1) min_dist = min(min_dist, i - index);
                index = i;
            }
        }
        return min_dist;
    }
};


/**
Shortest Word Distance III
Difficulty: Medium

This is a follow up of Shortest Word Distance. The only difference 
is now word1 could be the same as word2.

Given a list of words and two words word1 and word2, return the 
shortest distance between these two words in the list.

word1 and word2 may be the same and they represent two individual 
words in the list.

For example,
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Given word1 = “makes”, word2 = “coding”, return 1.
Given word1 = "makes", word2 = "makes", return 3.

Note:
You may assume word1 and word2 are both in the list.
 */
