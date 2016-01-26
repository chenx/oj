// This works too.
class Solution2 {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> a = splitPattern(pattern);
        vector<string> b = splitStr(str);
        return checkEqual(a, b) && checkEqual(b, a);
    }
    
    bool checkEqual(vector<string> &a, vector<string> &b) {
        if (a.size() != b.size()) return false;
        
        unordered_map<string, string> m;
        for (int i = 0, n = a.size(); i < n; ++ i) {
            if (m.find(a[i]) == m.end()) m[a[i]] = b[i];
            if (m[a[i]] != b[i]) return false;
        }
        return true;
    }
    
    vector<string> splitPattern(string str) {
        vector<string> v;
        for (int i = 0; i < str.size(); ++ i) {
            v.push_back(str.substr(i, 1));
        }
        return v;
    }
    
    vector<string> splitStr(string str) {
        vector<string> v;
        istringstream iss(str);

        while(iss)
        {
            string sub;
            iss >> sub;
            if (sub == "") break;
            v.push_back(sub);
        };
        return v;
    }
};

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
