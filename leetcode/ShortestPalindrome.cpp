// Works. Tested. Based on KMP. Nice solution.
// ab -> ab#ba, find maxLen = len(a), then result = bab.
// From: http://www.rudy-yuan.net/archives/186/
class Solution7 {
public:
    string shortestPalindrome(string s) {
        if (s.length() <= 1) return s;

        string s_rev = s;
        reverse(s_rev.begin(), s_rev.end());
        
        string str = s + "#" + s_rev;
        
        vector<int> next(str.length() + 1, 0);
        getNext(next, str);
        
        // length of longest suffix of str that's a prefix of str.
        int maxLen = next[str.length()];
        
        return s_rev.substr(0, s.length() - maxLen) + s;
    }
    
    void getNext(vector<int> & next, const string & s) {
        int len = -1, i = 0;
        next[0] = -1;
        
        while (i < s.length()) {
            if (len == -1 || s[i] == s[len]) {
                ++ i;
                ++ len;
                next[i] = len;
            }
            else {
                len = next[len];
            }
        }
    }
};

// Works too. Tested. Use KMP. But Solution7 is shorter and more clean.
// Use the kmp failure function from 
// https://github.com/chenx/oj/blob/master/misc/KMP.cpp
// just need to change 
//     int maxLen = next[str.length()];
// to
//     int maxLen = next[str.length() - 1];
class Solution8 {
public:
    string shortestPalindrome(string s) {
        if (s.length() <= 1) return s;

        string s_rev = s;
        reverse(s_rev.begin(), s_rev.end());
        
        string str = s + "#" + s_rev;
        
        vector<int> next(str.length() + 1, 0);
        getNext(next, str);
        
        int maxLen = next[str.length() - 1];
        
        return s_rev.substr(0, s.length() - maxLen) + s;
    }
    
    void getNext(vector<int> & F, string P) {
        int m = P.length();
        int i = 1, j = 0;
        F[0] = 0;
        
        while (i < m) {
            if (P[i] == P[j]) {
                F[i] = j + 1;
                ++ i, ++ j;
            }
            else if (j > 0) {
                j = F[j - 1];
            }
            else {
                F[i] = 0;
                ++ i;
            }
        }
    }
};

// Works. Tested. Re-written from Solution5.
class Solution6 {
public:
    string shortestPalindrome(string s) {
        int n = s.length();
        if (n == 0) return "";
        
        // length of max palindrome starting from s[0].
        int len = getLongestPalindrome(s); 
        
        string tail = s.substr(len);
        reverse(tail.begin(), tail.end());
        return tail + s;
    }
    
    int getLongestPalindrome(string s) {
        int n = s.length(), L, R, start = 0, end = 0, i = 0;
        while (i < n) {
            L = i;
            while (s[i] == s[L]) ++ i;
            R = i-1;
            
            while (L > 0 && R < n-1 && s[L - 1] == s[R + 1]) {
                -- L, ++ R;
            }
            if (L == 0 && R - L > end - start) {
                start = L, end = R;
            }
        }
        return end + 1;
    }
};

// This works. Tested.
// But this is also O(n^2), maybe it's specialized to pass the "aaaa.." test case.
class Solution5 {
public:
    string shortestPalindrome(string s) {
        int n = s.length();
        if (n == 0) return "";
        
        // length of max palindrome starting from s[0].
        int len = getLongestPalindrome(s); 
        
        string tail = s.substr(len);
        reverse(tail.begin(), tail.end());
        return tail + s;
    }
    
    int getLongestPalindrome(string s) {
        int n = s.length(), leftMost = 0, rightMost = 0;
        int i = 0, start, end;
        while (i < n) { 
            start = i;
            while (s[i] == s[start]) ++ i;

            end = i-1;
            while (start-1 >= 0 && end+1 < n && s[start-1] == s[end+1]) {
                -- start; ++ end;
            }
            if (start == 0 && (end-start) > (rightMost-leftMost)) {
                leftMost = 0; rightMost = end;
            }
        }
        return rightMost + 1;
    }
};


// Should work. But times out for large input.
class Solution4 {
public:
    string shortestPalindrome(string s) {
        int n = s.length();
        int len = getLongestPalindrome(s); // length of max p starting from 0.
        
        string tail = s.substr(len);
        reverse(tail.begin(), tail.end());
        return tail + s;
    }
    
    // O(n^2). not efficient.
    int getLongestPalindrome(string s) {
        int maxLen = 0, n = s.length();
        for (int i = 0; i < n; ++ i) {
            if (isPalindrome(s, 0, i)) maxLen = i + 1;
        }
        return maxLen;
    }
    
    bool isPalindrome(string & s, int L, int R) {
        for (; L <= R; ++ L, -- R) {
            if (s[L] != s[R]) return false;
        }
        return true;
    }
};

    
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
// s is a palindrome if hash(s) == hash(s^-1). We find the biggest n such as 
// s[1...n] is a palindrome and return s[length-1 ... n+1] + s.
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
