//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 1/3/2013
// @Last modified: 1/3/2013
//

#include <iostream>
#include <string>
#include <stack>
using namespace std;

/*
// This works no matter there is duplicate char or not!
// http://csjobinterview.wordpress.com/2012/07/03/google-scramble-string-iii/
// If s1 and s2 are scrambled strings, they can be
// divided into 2 anagram parts. Do this recursively.

It is proposed in this paper a recursive-based Divide-And-Conquer approach, 
this approach is more efficient than my preivous approaches.

The principle of this approach goes as following
1) Given two strings A and B, try to split each of them into two 
   sub-strings sA1,sA2,sB1, sB2 where sA1 and sB1 are anagrams and 
   sA2 and sB2 are anagrams.
2) If sA1 and sB1 are the scramble strings while sA2 and sBs are 
   scramble strings, then A and B should be scramble strings.
3) Recursivly analyze sA1 and sB1, sA2 and sB2 by start over from step 1).

In previous example

str1 = aabbbaccd, str2: aabcdbcba,

They are split as: (aab)(bbaccd),  (aab)(cdbcba) => compare bbaccd and cdbcba
They are split as: (bbac)(cd),  (cd)(bcba) => compare bbac and bcba
They are split as: (b)(bac), b(cba) => (ba)(c) vs (c)(ba)
*/
class Solution {
public:
    bool isScramble(string s1, string s2) {
        int len1 = s1.length();
        int len2 = s2.length();
        if (len1 != len2) return false;
        if (len1 == 0) return true;
        if (len1 == 1 && s1 == s2) return true; // This is needed!
        
        // search for anagrams from front to back.
        //for (int i = len1 - 2; i >= 0; -- i) { // This way works too.
        for (int i = 0; i < len1 - 1; ++ i) {
            if ( isAnagram(s1.substr(0, i+1), s2.substr(0, i+1)) ) {
                if ( isScramble(s1.substr(0, i+1), s2.substr(0, i+1)) &&
                     isScramble(s1.substr(i+1), s2.substr(i+1)) )
                    return true; // note you return ONLY WHEN it is true, to try all possibilities.
            }
        }
        
        // search for anagrams from back to front.
        for (int i = 0; i < len1 - 1; ++ i) {
            if ( isAnagram(s1.substr(0, i+1), s2.substr(len1 - i - 1)) ) {
                if ( isScramble(s1.substr(0, i+1), s2.substr(len1 - i - 1)) &&
                     isScramble(s1.substr(i+1), s2.substr(0, len1 - i - 1)) ) 
                    return true; // be careful of index here.
            }
        }
        
        return false;
    }
    
    bool isAnagram(string s1, string s2) {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        return s1 == s2;
    }
};

// Similar to Solution. works too.
class Solution3 {
public:
    bool isScramble(string s1, string s2) {
        int len1 = s1.length(), len2 = s2.length();
        if (len1 != len2) return false;
        if (len1 == 0) return true;
        if (len1 == 1 && s1 == s2) return true;
        
        string s1l, s1r, s2l, s2r;
        for (int i = 0; i < len1-1; ++ i) {
            s1l = s1.substr(0, i+1), s1r = s1.substr(i+1);
            s2l = s2.substr(0, i+1), s2r = s2.substr(i+1);
            if (isAnagram(s1l, s2l)) {
                if (isScramble(s1l, s2l) && isScramble(s1r, s2r))        
                    return true;
            }
        }
        
        for (int i = 0; i < len1-1; ++ i) {
            s1l = s1.substr(0, i+1), s1r = s1.substr(i+1);
            s2l = s2.substr(0, len1-i-1), s2r = s2.substr(len1-i-1);
            if (isAnagram(s1l, s2r)) {
                if (isScramble(s1l, s2r) && isScramble(s1r, s2l))        
                    return true;
            }
        }
        return false;
    }
    
    bool isAnagram(string x, string y) {
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        return x == y;
    }
};

//
// This works too! Optimized from Solution3.
// Note: isAnagram() is not necessary, but can increase speed by disgarding some data.
//
class Solution4 {
public:
    bool isScramble(string s1, string s2) {
        if (s1.length() != s2.length()) return false;
        
        int n = s1.length();
        if (n == 0) return true;
        if (n == 1) return s1 == s2;
        
        // forward
        for (int i = 1; i < n; ++ i) {
            string s1L = s1.substr(0,i), s1R = s1.substr(i, n-i);
            string s2L = s2.substr(0,i), s2R = s2.substr(i, n-i);
            if ( isAnagram(s1L, s2L) ) {
                if (isScramble(s1L, s2L) && isScramble(s1R, s2R)) return true;
            } 
        }
        
        // backward
        for (int i = 1; i < n; ++ i) {
            string s1L = s1.substr(0,i), s1R = s1.substr(i, n-i);
            string s2R = s2.substr(n-i, i), s2L = s2.substr(0, n-i);
            if ( isAnagram(s1L, s2R) ) {
                if (isScramble(s1L, s2R) && isScramble(s1R, s2L)) return true;
            } 
        }        
        
        return false;
    }
    
    bool isAnagram(string s1, string s2) {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        return s1 == s2;
    }
};

// This works too.
// Notice the use of substr() with only 1 param and ignore the 2nd.
// The code commented out should also work, but so far it times out, 
// so guess string creation is time consuming. 11/14/2014
class Solution5 {
public:
    bool isScramble(string s1, string s2) {
        if (s1.length() != s2.length()) return false;
        int n = s1.length();
        if (n <= 1) return s1 == s2;

        for (int i = 1; i < n; ++ i) {
            //string s1L = s1.substr(0, i), s1R = s1.substr(i),
            //       s2L = s1.substr(0, i), s2R = s2.substr(i);
            //if (isAnagram(s1L, s2L) && isScramble(s1L, s2L) && isScramble(s1R, s2R)) return true;
            if (isAnagram(s1.substr(0, i), s2.substr(0, i)) && 
                isScramble(s1.substr(0, i), s2.substr(0, i)) && 
                isScramble(s1.substr(i), s2.substr(i))) return true;
        }
        
        for (int i = 1; i < n; ++ i) {
            //string s1L = s1.substr(0, i), s1R = s1.substr(i),
            //       s2L = s2.substr(0, n-i), s2R = s2.substr(n-i);
            //if (isAnagram(s1L, s2R) && isScramble(s1L, s2R) && isScramble(s1R, s2L)) return true;
            if (isAnagram(s1.substr(0, i), s2.substr(n-i)) && 
                isScramble(s1.substr(0, i), s2.substr(n-i)) && 
                isScramble(s1.substr(i), s2.substr(0, n-i))) return true;
        }
        
        return false;
    }
    
    bool isAnagram(string a, string b) {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        return a == b;
    }
};

/*
This handles the case chars in s1 don't duplicate.
http://csjobinterview.wordpress.com/2012/05/07/google-scramble-string/

Observation: Let is use s1 = tiger?and s2 = itreg?for example.

Let indexArr stores the indexes of s1?s characters in s2, in this example, 
indexArr = {1,0,4,3,2}

Next, based on this array, check if one of its elements is logically adajacent 
to its neighors. For example, in this indexArr, the 3rd entry is ?? and on 
its right side resides number ??, therefore, they are logically adjacent.

Such array can be converted as : {1,0,4,3,2} => {{0,1},4,3,2} => 
{{0,1},{3,4},2} =>{{0,1},{2,3,4}} => {0,1,2,3,4}

As one can observe from above, in this case, two intervals?or two neighbors 
can be merged into one if and only if they are logically ajacent.

An counter example is Tiger and Tgrie, now indexArr = {0,3,1,4,2}, it cannot 
be converted to {0,1,2,3,4} by such merge.

Algoirthm:

By given two strings S1 and S2, first figure out the indexArr defined as bove

1) For each element in indexArr, if it is just smaller than or greater than 
   the one on either of its side, then merge them into an interval.
2) For each interval, we do the same, to see if its head or its tail is just 
   smaller than or greater than its neighbors, if so, merge them accordingly.
3) Once we go through the indexArr once, see if there is just one interval 
   left in indexArr.
 */

class MyInterval {
    public:
        int start;
        int end;
        MyInterval(int s, int e) : start(s), end(e) {}
};

class Solution2 {
public:
    bool isScramble(string s1, string s2) {
        // first, get index array of a1 in a2.
        int len = s1.length();
        if (len != s2.length()) return false;
        
        int a[len];
        size_t pos;
        for (int i = 0; i < len; ++ i) {
            pos = s1.find(s2[i]);
            if (pos == string::npos) return false;
            a[i] = (int) pos;
        }

        stack<MyInterval> t1;
        for (int i = 0; i < len; ++ i) {
            MyInterval mi(a[i], a[i]);
            t1.push(mi);
        }
        
        stack<MyInterval> t2;
        while(t1.size() > 0) {
            MyInterval mi = t1.top();
            t1.pop();
            if (t2.size() == 0) {
                t2.push(mi);
            }
            else {
                while (t2.size() > 0) {
                    if (mi.start == t2.top().end + 1) { // merge t2.top() and mi.
                        mi.start = t2.top().start;
                        t2.pop();
                    } else if (mi.end + 1 == t2.top().start) { // merge mi, t2.top().
                        mi.end = t2.top().end;
                        t2.pop();
                    } else {
                        break;
                    }
                }
                t2.push(mi);
            }
        }
        
        return t2.size() == 1;
        //return true;
    }
};


int main() {
    string a = "cbad";
    printf("%s\n", a.c_str());
    sort(a.begin(), a.end());
    printf("%s\n", a.c_str());
    Solution s;
    
    string s1 = "oatzzffqpnwcxhejzjsnpmkmzngneo";
    string s2 = "acegneonzmkmpnsjzjhxwnpqffzzto";
    printf("isScramble(%s, %s) = %d\n", s1.c_str(), s2.c_str(), s.isScramble(s1, s2));
    return 0;
}

/*
3-digit number: 123: all permutations are scrambles.
4-digit number: 1234
-> scrambles:
4123
4132
4213
4231
4312
4321

1234
1324
2134
2314
3124
3214

1234 - repeated
1243
1324 - repeated
1342
1423
1432

2341
2431
3241
3421
4231 - repeated
4321 - repeated

1234 - repeated
1243 - repeated
2134 - repeated
2143
3412
4312 - repeated
3421 - repeated
4321 - repeated

Total number of scrambles: 22.
Two cases not scrambles:   2413, 3142.

Recursive solution:
- for i = 1 to n-1.
    if (s1[1..i] and s2[1..i] are anagrams {
       check s1[1..i] and s2[1..i]
       check s1[i+1..n] and s2[i+1..n];
    }
    else if (s1[1..i] and s2[n-i+1..n] are anagrams) {
         check s1[1..i] and s2[n-i+1..n];
         check s1[i+1..n] and s2[1..n-i];
    }
    else {
         return false;
    }
 */

/*
Problem:

 Given a string s1, we may represent it as a binary tree by partitioning 
 it to two non-empty substrings recursively.

Below is one possible representation of s1 = "great":

    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t

To scramble the string, we may choose any non-leaf node and swap its 
two children.

For example, if we choose the node "gr" and swap its two children, 
it produces a scrambled string "rgeat".

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t

We say that "rgeat" is a scrambled string of "great".

Similarly, if we continue to swap the children of nodes "eat" 
and "at", it produces a scrambled string "rgtae".

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a

We say that "rgtae" is a scrambled string of "great".

Given two strings s1 and s2 of the same length, determine 
if s2 is a scrambled string of s1. 
 */
