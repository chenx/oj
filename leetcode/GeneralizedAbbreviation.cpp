// Should work. Tested locally.
// Basically same as Solution3, but re-written and cleaned code.
class Solution4 {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> ans;
        gen(ans, word, 0, "", false);
        return ans;
    }

    void gen(vector<string> & ans, string word, int pos, string p, bool prevIsNum) {
        if (pos == word.length()) {
            ans.push_back(p);
            return;
        }

        gen(ans, word, pos + 1, p + word[pos], false);
        if (! prevIsNum) {
            for (int i = 1; i + pos <= word.length(); ++ i) {
                gen(ans, word, pos + i, p + to_string(i), true);
            }
        }
    }
};


// Works. Tested.
// From: https://leetcode.com/discuss/75421/my-backtracking-c-solution
class Solution3 {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> result;
        go(word, "", 0, result, false);
        return result;
    }

    void go(string& word, string abbr, int i, vector<string>& result, bool prevNum) {
        if (i == word.length()) {
            result.push_back(abbr);
            return;
        }

        go(word, abbr+word[i], i+1, result, false);
        if (!prevNum) {
            // Add number abbreviations only when we added a character instead of an abbreviation earlier
            for (int len = 1; i+len <= word.length(); ++len) {
                go(word, abbr+to_string(len), i+len, result, true);
            }
        }
    }
};


// Works. Tested.
// From: https://leetcode.com/discuss/75806/share-my-cpp-recursive-solution
class Solution2 {
public:
    void go(string &word, vector<string> &res, string &path, int pos, bool flag) {
        if (pos == word.size()) {
            res.push_back(path);
        } else {
            path.push_back(word[pos]);
            go(word, res, path, pos + 1, true);
            path.pop_back();
            if (flag == false) return;
            for (int i = 1; i <= word.size() - pos; i++) {
                int Nt = path.size();
                path += to_string(i);
                go(word, res, path, pos + i, false);
                path = path.substr(0, Nt);
            }
        }
    }

    vector<string> generateAbbreviations(string word) {
        vector<string> ans;
        string path;
        go(word, ans, path, 0, true);
        return ans;
    }
};


// Works. Tested.
// From: https://leetcode.com/discuss/76163/concise-c-bit-manipulation-solution
// motivated by subset II, each character 'x' in word will represent as either 
// 'x' or '1' in an abbreviation. The trick is to accumulate those '1' together.
class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> res(1<<word.size());
        for(int i=0; i<word.size(); i++){
            for(int j=0; j<res.size(); j++){
                if(j & (1<<i)) res[j].push_back(word[i]);
                else{  // plus one
                    int k=res[j].size()-1, carry=1;
                    while(k>=0 && isdigit(res[j][k]) && carry==1){
                        int cur=(res[j][k]-'0')+carry;
                        res[j][k--]=cur%10+'0';
                        carry=cur/10;
                    }
                    if(carry==1) res[j].insert(res[j].begin()+k+1, '1');
                }
            }
        }
        return res;
    }
};


/**
Generalized Abbreviation My Submissions Question
Difficulty: Medium

Write a function to generate the generalized abbreviations of a word.

Example:
Given word = "word", return the following list (order does not matter):
["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", 
 "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]
 */
