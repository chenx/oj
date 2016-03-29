// Works. Tested.
// Modified from: https://leetcode.com/discuss/87618/sharing-my-4ms-c-solution
class Solution3 {
public:
    string shortestPalindrome(string s) {
        int n = s.length(), leftMost=0, rightMost=0;
        int i = 0, start, end;
        while (i < n) { // get longest palindrome starting from s[0]
            start = i;
            while (s[i]==s[start]) ++ i;

            end = i-1;
            while (start-1>=0 && end+1<n && s[start-1]==s[end+1]) {
                start--; end++;
            }
            if (start == 0 && (end-start) > (rightMost-leftMost)) {
                leftMost = 0; rightMost = end;
            }
        }

        string tail;
        if (rightMost < n-1) { // get part after palindrome, reverse it
            tail = s.substr(rightMost+1, n-rightMost); 
            reverse(tail.begin(), tail.end());
        }
        return tail + s;
    }
};    
    
/*
Comment from: https://leetcode.com/discuss/52616/easy-c-manacher

The idea is to find the longest palindromic substring of s that begins with s[0]. 
Then take the remaining susbtring, reverse it and append it to the beginning of s.

For example, given s = "aacecaaa", the longest palindromic substring beginning 
with s[0] = 'a' is "aacecaa" and the remaining substring is "a". Reverse it and 
append it to the beginning of s gives "aaacecaaa".

For s = "abcd", the longest palindromic substring beginning with s[0] = 'a' is 
"a" and the remaining substring is "bcd". Reverse it and append it to the 
beginning of s gives "dcbabcd".

The most difficult part is to implement the Manacher's algorithm to find the 
longest palindromic substring starting with s[0]. Please refer to this nice 
article if you want to know how it works. 
 */

// Works. Tested. Y?
// From: https://leetcode.com/discuss/81299/c-4ms-manacher
class Solution2 {
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
