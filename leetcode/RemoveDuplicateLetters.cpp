// Basically same as Solution. Easier to understand.
class Solution2 {
public:
    string removeDuplicateLetters(string s) {
        int count[256] = {0};
        bool used[256] = {false};
        
        for (char c : s) count[c] ++;
        
        string ans;
        for (int i = 0; i < s.length(); ++ i) {
            char c = s[i];
            count[c] --;
            if (used[c]) continue;
            
            while (ans != "" && count[ans.back()] > 0 && ans.back() > c) {
                used[ans.back()] = false;
                ans.pop_back();
            }

            used[c] = true;
            ans += c;
        }
        
        return ans;
    }
};

// From: https://leetcode.com/discuss/76639/o-n-c-solution
class Solution {
public:
    string removeDuplicateLetters(string s) {
        int counts[26] = {};
        bool inresult[26] = {};
        for(char c: s) counts[c-'a']++;
        string result = "";
        for(char c: s) {
            counts[c-'a']--;
            if(inresult[c-'a']) continue;
            while(!result.empty() && counts[result.back()-'a']>0 && result.back()>c){
                inresult[result.back()-'a'] = false;
                result.pop_back();
            }
            inresult[c-'a'] =true;
            result.push_back(c);
        }
        return result;
    }
};


/**
Remove Duplicate Letters
Difficulty: Medium

Given a string which contains only lowercase letters, remove duplicate letters 
so that every letter appear once and only once. You must make sure your result 
is the smallest in lexicographical order among all possible results.

Example:

Given "bcabc"
Return "abc"

Given "cbacdcbc"
Return "acdb" 
 */
