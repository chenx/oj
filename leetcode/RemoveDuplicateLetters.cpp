// Same as Solution. Re-written to be easier to understand.
class Solution2 {
public:
    string removeDuplicateLetters(string s) {
        int counts[26] = {0};
        bool inresult[26] = {false};
        for (char c: s) counts[c-'a'] ++;
        
        string result = "";
        for (int i = 0; i < s.length(); ++ i) {
            char c = s[i];
            counts[c-'a'] --;
            if (inresult[c-'a']) continue; // already used in result string.
            
            while (result != "" && counts[result.back()-'a'] > 0 && result.back() > c) {
                // pop char greater than c in lexicographical order.
                // "counts[result.back()-'a'] > 0" guarantees this char will be used later.
                inresult[result.back()-'a'] = false;
                result.pop_back();
            }
            inresult[c-'a'] = true;
            result.push_back(c);
        }
        return result;
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
