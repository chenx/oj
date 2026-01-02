class Solution5 {
    vector<string> split(string& s) {
        stringstream ss(s);
        string out;
        vector<string> result;
        while (getline(ss, out, ' ')) {
            result.push_back(out);
        }
        return result;
    }
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words = split(s);

        if (words.size() != pattern.length()) return false;

        map<char, string> map1;
        map<string, char> map2;
        for (int i = 0; i < pattern.length(); ++ i) {
            char ch = pattern[i];
            if (! map1.contains(ch) && ! map2.contains(words[i])) {
                map1[ch] = words[i];
                map2[words[i]] = ch;
            }
            else if (map1[ch] != words[i] || map2[words[i]] != ch) return false;
        }        
        return true;
    }
};

// Works.
class Solution4 {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words = split(s);
        if (words.size() != pattern.length()) return false;

        map<string, char> m1;
        map<char, string> m2;

        for (int i = 0; i < words.size(); ++ i) {
            if (!m1.contains(words[i])) m1[words[i]] = pattern[i];
            else if (m1[words[i]] != pattern[i]) return false;

            if (!m2.contains(pattern[i])) m2[pattern[i]] = words[i];
            else if (m2[pattern[i]] != words[i]) return false;
        }
        return true;
    }

    vector<string> split(string& s) {
        vector<string> ans;
        stringstream ss(s);
        string word;
        while (ss >> word) {
            ans.push_back(word);
        }
        return ans;
    }
};

// Works too.
class Solution3 {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words = split(s);
        if (pattern.length() != words.size()) return false;

        unordered_map<char, string> m1;
        unordered_map<string, char> m2;
        for (int i = 0; i < pattern.length(); i ++) {
            if (m1.find(pattern[i]) == m1.end() && m2.find(words[i]) == m2.end()) {
                m1[pattern[i]] = words[i];
                m2[words[i]] = pattern[i];
            } else if (m1[pattern[i]] != words[i]) {
                return false;
            }
        }

        return true;
    }

    vector<string> split(string s) {
        vector<string> result;
        stringstream ss(s);
        string word;

        while (ss >> word) {
            result.push_back(word);
        }
        return result;
    }
};

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
        stringstream ss(str);
        string sub;

        while(ss >> sub) {
            v.push_back(sub);
        };
        return v;
    }
    
    vector<string> splitStr2(string str) {
        vector<string> v;
        stringstream ss(str);
        string sub;

        while(getline(ss, sub, ' ')) {
            v.push_back(sub);
        };
        return v;
    }
};

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<int> vp, vs; // feature vectors.
        
        unordered_map<char, int> mp;
        int ct = 0;
        for (int i = 0; i < pattern.length(); ++ i) {
            if (mp[pattern[i]] == 0) mp[pattern[i]] = ++ ct;
            vp.push_back(mp[pattern[i]]);
        }
        
        unordered_map<string, int> ms;
        ct = 0;
        
        stringstream ss(str);
        string next;
        while (ss >> next) {
            if (ms[next] == 0) ms[next] = ++ ct;
            vs.push_back(ms[next]);
        }
        
        return vp == vs;
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
