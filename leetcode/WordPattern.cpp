class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, int> m1;
        unordered_map<string, int> m2;
        vector<int> f1, f2; // feature vector
        
        int ct = 0;
        for (int i = 0, len = pattern.length(); i < len; ++ i) {
            if (m1[pattern[i]] == 0) {
                m1[pattern[i]] = ++ ct;
            }
            f1.push_back(m1[pattern[i]]);
        }
        
        istringstream iss(str);
        ct = 0;

        while(iss)
        {
            string sub;
            iss >> sub;
            if (sub == "") break;
            if (m2[sub] == 0) {
                m2[sub] = ++ ct;
            }
            f2.push_back(m2[sub]);
        };
        
        return f1 == f2;
    }
};


/**
Word Pattern
Difficulty: Easy

Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a 
letter in pattern and a non-empty word in str.

Examples:

    pattern = "abba", str = "dog cat cat dog" should return true.
    pattern = "abba", str = "dog cat cat fish" should return false.
    pattern = "aaaa", str = "dog cat cat dog" should return false.
    pattern = "abba", str = "dog dog dog dog" should return false.

Notes:
You may assume pattern contains only lowercase letters, and str contains 
lowercase letters separated by a single space. 
 */
