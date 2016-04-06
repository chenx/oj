// Should work. Not tested. From lnkin intv.
class WordDistance3 {
private:
    unordered_map<string, vector<int>> m;
    
public:
    WordDistance(vector<string>& words) {
        for (int i = 0, n = words.size(); i < n; ++ i) {
            m[words[i]].push_back(i);
        }
    }

    // optimized. Use merge-sort logic.
    int shortest(string word1, string word2) {
        // Use this to avoid creating empty entry if word1/2 does not exist.
        if (m.find(word1) == m.end() || m.find(word2) == m.end()) return -1;
        
        int minD = INT_MAX;
        vector<int> &a = m[word1];
        vector<int> &b = m[word2];
        
        int n1 = a.size(), n2 = b.size(), i = 0, j = 0;
        while (i < n1 && j < n2) {
            minD = min(minD, abs(a[i] - b[j]));
            if (a[i] < b[j]) ++ i;
            else ++ j;
        }
        
        return minD;
    }
};
    
// Works. Basically same as WordDistance, but optimized.
class WordDistance2 {
private:
    unordered_map<string, vector<int>> m;
    
public:
    WordDistance(vector<string>& words) {
        for (int i = 0, n = words.size(); i < n; ++ i) {
            m[words[i]].push_back(i);
        }
    }

    int shortest(string word1, string word2) {
        int minD = INT_MAX;
        vector<int> &a = m[word1];
        vector<int> &b = m[word2];
        
        for (int i = 0, m = a.size(); i < m; ++ i) {
            for (int j = 0, n = b.size(); j < n; ++ j) {
                minD = min(minD, abs(a[i] - b[j]));
            }
        }
        return minD;
    }
};

// Works. Tested. From: https://leetcode.com/discuss/86267/sharing-my-60ms-c-solution
// This works for ShortestWordDistance.cpp too.
// The double loop part is actually not so optimal.
class WordDistance {
private:
    unordered_map<string, vector<int>> myMap;
public:
    WordDistance(vector<string>& words) {
        int n = words.size();
        int i, j;
        for(i=0; i<n; i++)
            myMap[words[i]].push_back(i);
    }

    int shortest(string word1, string word2) {
        vector<int> index1=myMap[word1];
        vector<int> index2=myMap[word2];
        int distance = INT_MAX;
        int i, j;
        for(i=0; i<index1.size(); i++)
            for(j=0; j<index2.size(); j++)
                distance = min(distance, abs(index1[i]-index2[j]));

        return distance;
    }
};


// Your WordDistance object will be instantiated and called as such:
// WordDistance wordDistance(words);
// wordDistance.shortest("word1", "word2");
// wordDistance.shortest("anotherWord1", "anotherWord2");


/**
Shortest Word Distance II 
Difficulty: Medium

This is a follow up of Shortest Word Distance. The only difference is 
now you are given the list of words and your method will be called 
repeatedly many times with different parameters. How would you optimize it?

Design a class which receives a list of words in the constructor, and 
implements a method that takes two words word1 and word2 and return 
the shortest distance between these two words in the list.

For example,
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Given word1 = “coding”, word2 = “practice”, return 3.
Given word1 = "makes", word2 = "coding", return 1.

Note:
You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.
 */
