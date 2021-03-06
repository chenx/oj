// Should work. Tested locally.
// Modified from Solution2.
class Solution3 {
public:
    bool wordPatternMatch(string pattern, string str) {
        map<char, string> mp;
        set<string> st;
        return match(pattern, str, mp, st);
    }

    bool match(string pattern, string str, map<char, string> &mp, set<string> &st) {
        if (pattern == "") return str == "";

        char p = pattern[0];
        if (mp.count(p)) {
            string s = mp[p];
            int lens = s.length();

            if (lens > str.length() || str.substr(0, lens) != s) return false;
            return (match(pattern.substr(1), str.substr(lens), mp, st));
        } else {
            for (int i = 1; i <= str.size(); i++){
                string s = str.substr(0, i);
                if (st.count(s)) continue;
                
                mp[p] = s;
                st.insert(s);
                if (match(pattern.substr(1), str.substr(i), mp, st)) return true;
                mp.erase(p);
                st.erase(s);
            }
            return false;
        }
    }
};


// Should work. Tested locally.
// Modified from: https://leetcode.com/discuss/76466/20-lines-concise-and-easy-understand-c-solution
class Solution2 {
public:
    bool wordPatternMatch(string pattern, string str) {
        map<char, string> mp;
        set<string> st;
        return match(pattern, str, mp, st);
    }

    bool match(string pattern, string str, map<char, string> &mp, set<string> &st) {
        if (pattern.size() == 0) return str.size() == 0;
        if (mp.count(pattern[0])) {
            string value = mp[pattern[0]];
            if(value.size() > str.size() || str.substr(0, value.size()) != value) return false;
            if(match(pattern.substr(1), str.substr(value.size()), mp, st)) return true;
        } else {
            for (int i = 1; i <= str.size(); i++){
                if (st.count(str.substr(0, i))) continue;
                mp[pattern[0]] = str.substr(0, i);
                st.insert(str.substr(0, i));
                if (match(pattern.substr(1), str.substr(i), mp, st)) return true;
                mp.erase(pattern[0]);
                st.erase(str.substr(0, i));
            }
        }
        return false;
    }
};


// Works. Tested.
// Idea:
// The key is in lowerbound checking. lowerBound is the minimal length the str 
// should be. It will increase every time we update the char to pattern map.
// The place to check the lowerBound is also important. Here we check it every 
// time it is increased. This allows us to break early from the pattern update 
// loop, because we don't need to assign a longer pattern to this char if the 
// lowerBound condition not met.
// From: https://leetcode.com/discuss/78689/my-0ms-c-solution-with-pruning
class Solution {
private:
    array<int, 26> hist;        // number of each char in pattern, will be const after initialization
    array<string, 26> mp;       // char to pattern map
    unordered_set<string> used; // used pattern

    bool dfs(string &pattern, int pStep, string &str, int sStep, int lowerBound) {
        if(pStep == pattern.length() || sStep == str.length())
            return (pStep == pattern.length() && sStep == str.length());

        auto c = pattern[pStep];
        auto& s = mp[c - 'a'];

        // if the mapping exists, update char to string map and perform backtracking
        // else check if the mapping matches correctly
        if(s.empty()) {
            for(int len = 1; sStep + len <= str.length(); ++len) {
                s += str[sStep + len - 1];
                if(used.count(s)) continue;

                // 1. str's length should be at least lowerBound long
                // 2. use len-1 here because we set the initial length to be 1
                // 3. we do the lowerBound checking here because the len is increasing
                //    no need to continue the loop if lowerBound test fails
                auto newLowerBound = lowerBound + hist[c-'a'] * (len-1);
                if(str.length() < newLowerBound) break;

                auto iter = used.insert(s).first;
                if(dfs(pattern, pStep + 1, str, sStep + len, newLowerBound)) 
                    return true;
                used.erase(iter);
            }
            s.clear();
            return false;
        }
        else 
            return str.substr(sStep, s.length()) == s 
                && dfs(pattern, pStep + 1, str, sStep + s.length(), lowerBound);
    }

public:
    bool wordPatternMatch(string pattern, string str) {
        fill(hist.begin(), hist.end(), 0);
        for(auto c : pattern) 
            ++hist[c - 'a'];
        return dfs(pattern, 0, str, 0, pattern.length());
    }
};


/**
Word Pattern II 
Difficulty: Hard

Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between 
a letter in pattern and a non-empty substring in str.

Examples:
pattern = "abab", str = "redblueredblue" should return true.
pattern = "aaaa", str = "asdasdasdasd" should return true.
pattern = "aabb", str = "xyzabcxzyabc" should return false.
Notes:
You may assume both pattern and str contains only lowercase letters.
 */
