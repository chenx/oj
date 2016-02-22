// Works. O(n^2). By: XC
class Solution2 {
public:
    int maxProduct(vector<string>& words) {
        int len = words.size();
        vector<int> m(len);

        for (int i = 0; i < len; ++ i) {
            m[i] = getSignature(words[i]);
        }
        
        int maxv = 0;
        for (int i = 0; i < len - 1; ++ i) {
            for (int j = i + 1; j < len; ++ j) {
                // Note: need () around & operation for precedence over =!
                if ((m[i] & m[j]) == 0) { 
                    int v = words[i].length() * words[j].length();
                    maxv = max(maxv, v);
                }
            }
        }
        return maxv;
    }

    int getSignature(string s) {
        int v = 0;
        for (int i = 0; i < s.length(); ++ i) {
            v |= 1 << (s[i] - 'a');
        }
        return v;
    }
};


// Should work. But times out for large input. By: XC
class Solution {
public:
    int maxProduct(vector<string>& words) {
        unordered_map<string, int> m;
        int len = words.size();
        
        for (int i = 0; i < len; ++ i) {
            m[words[i]] = getSignature(words[i]);
        }
        
        int maxv = 0;
        for (int i = 0; i < len - 1; ++ i) {
            for (int j = i + 1; j < len; ++ j) {
                if (m[words[i]] & m[words[j]] == 0) {
                    int v = words[i].length() * words[j].length();
                    maxv = max(maxv, v);
                }
            }
        }
        return maxv;
    }
    
    int getSignature(string s) {
        int v = 0;
        for (int i = 0; i < s.length(); ++ i) {
            v |= 1 << (s[i] - 'a');
        }
        return v;
    }
};


/**
Maximum Product of Word Lengths
Difficulty: Medium

Given a string array words, find the maximum value of 
length(word[i]) * length(word[j]) where the two words 
do not share common letters. You may assume that each 
word will contain only lower case letters. If no such 
two words exist, return 0.

Example 1:

Given ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
Return 16
The two words can be "abcw", "xtfn".

Example 2:

Given ["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
Return 4
The two words can be "ab", "cd".

Example 3:

Given ["a", "aa", "aaa", "aaaa"]
Return 0
No such pair of words. 
 */
