// Works. Tested. Y?
// From: https://leetcode.com/discuss/81299/c-4ms-manacher
class Solution {
public:
    string shortestPalindrome(string s) {
        if(s == "") return s;
        string scopy(s.begin()+1,s.end());
        reverse(scopy.begin(), scopy.end());
        string ans = scopy + s;
        int len = s.size(), i = 0, j, k;
        while (i < len){
            string tmp = scopy;
            int r = i;
            while (r < len && s[r] == s[r + 1]) ++r;
            j = i - 1; k = r + 1;
            while (j >= 0 && k < len && s[j] == s[k]){
                --j;
                ++k;
            }
            if (j == -1 && k == len){
                return s;
            }
            else if(j == -1 && k != len){
                tmp = s.substr(k, len -  k + 1);
                reverse(tmp.begin(), tmp.end());
                tmp += s;
                ans = ans.size() > tmp.size() ? tmp : ans;
            }
            i = r + 1;
        }
        return ans;
    }
};


// Works. Tested. Y?
// From: https://leetcode.com/discuss/83232/short-rolling-hash-o-n-solution-in-c
#define int long long 
const int B = 'z'+1;
const int H = 74747474747474747LL;  

class Solution {
public:
    string shortestPalindrome(string s) {
        int n;
        for(int i=0, hash=0, hashR=0, base=1; i<s.size(); i++)
        {
            hash = (hash+base*s[i])%H;
            base = base*B%H;
            hashR = (hashR*B+s[i])%H;
            if(hash == hashR)
                n = i;
        }
        string r;
        for(int i=s.size()-1; i>n; i--)
            r += s[i];
        return r + s;
    }
};


/**
Shortest Palindrome
Difficulty: Hard

Given a string S, you are allowed to convert it to a palindrome by 
adding characters in front of it. Find and return the shortest 
palindrome you can find by performing this transformation.

For example:

Given "aacecaaa", return "aaacecaaa".

Given "abcd", return "dcbabcd".
 */
