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
