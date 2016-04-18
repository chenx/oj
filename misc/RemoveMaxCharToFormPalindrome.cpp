//
// Given a string, what's the min number of chars to remove
// for it to become a palindrome?  
// 
// By: X.C. 4/17/2016
// 

#include <iostream>
#include <vector>
#include <set>
using namespace std;

// This gives the max palindrome strings in addition to the 
// number of chars to remove.
class Solution2 {
    set<string> maxStr;
    int maxLen;
public:
    int removeCharToFormPalindrome(string s) {
        maxStr.clear();
        maxLen = 0;
        int ct = get(s);

        for (set<string>::iterator it = maxStr.begin(); it != maxStr.end(); ++ it)
            cout << "max palindrome: " << *it << endl;

        return ct;
    }

    int get(string s) {
        int count = 0;
        for (int L = 0, R = s.length() - 1; L < R; ++ L, -- R) {
            if (s[L] != s[R]) {
               count = 1 + min(
                   get(s.substr(0, L) + s.substr(L+1)),
                   get(s.substr(0, R) + s.substr(R+1))
               );
               return count;
            }
        }

        if (isPalindrome(s) && s.length() >= maxLen) {
            if (s.length() > maxLen) {
                maxLen = s.length();
                maxStr.clear();
            }
            maxStr.insert(s);
        }
        return count;
    }

    bool isPalindrome(string s) {
        int L = 0, R = s.length() - 1;
        for (; L < R; ++ L, -- R) {
            if (s[L] != s[R]) return false;
        }
        return true;
    }
};

// Returns the max number of chars to remove.
// This does not change s, is fast.
class Solution {
public:
    int removeCharToFormPalindrome(string s) {
        int minCt = 0;
        getP(s, 0, s.length() - 1, minCt, -1);
        return minCt;
    }
    void getP(string s, int L, int R, int & count, int rmIndex) {
        if (rmIndex != -1) {
            string p = s.substr(0, rmIndex) + s.substr(rmIndex+1);
            cout << "remove char at index " << rmIndex << ", string becomes: " << p << endl;
        }

        for (; L < R; ++ L, -- R) {
            if (s[L] != s[R]) {
               int n1 = count + 1, n2 = count + 1;
               getP(s, L + 1, R, n1, L);
               getP(s, L, R - 1, n2, R);
               count = min(n1, n2);
               return;
            }
        }
    }
};

void test1() {
    string in[] = {"abbac", "acbcba", "axbybba", "aaazzzaaaaaaaataaxxa", "abccddc"};
    int expect[] = {1, 1, 2, 6, 3};
    int size = sizeof(expect) / sizeof(int);
    Solution2 so;

    for (int i = 0; i < size; ++ i)
    {
        int answer = so.removeCharToFormPalindrome(in[i]);
        cout << "input: " << in[i] << ", min chars to remove: " << answer <<
             ". expect: " << expect[i] << ". " << (answer == expect[i] ? "pass" : "fail") << "\n\n";
    }
}

int main() {
    test1();
    return 0;
}


/**
Output:

max palindrome: abba
input: abbac, min chars to remove: 1. expect: 1. pass

max palindrome: abcba
max palindrome: acbca
input: acbcba, min chars to remove: 1. expect: 1. pass

max palindrome: abbba
max palindrome: abyba
input: axbybba, min chars to remove: 2. expect: 2. pass

max palindrome: aaaaaaaaaaaaaa
input: aaazzzaaaaaaaataaxxa, min chars to remove: 6. expect: 6. pass

max palindrome: cddc
input: abccddc, min chars to remove: 3. expect: 3. pass
 */
