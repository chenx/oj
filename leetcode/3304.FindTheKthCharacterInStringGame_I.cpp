// Bit operation
// From: https://leetcode.com/problems/find-the-k-th-character-in-string-game-i/editorial/
// Time complexity: O(logk).
// It only depends on the binary digits of k.
// Space complexity: O(1).
//
class Solution2 {
public:
    char kthCharacter(int k) {
        int ans = 0;
        int t;
        while (k != 1) {
            t = __lg(k);
            if ((1 << t) == k) {
                t--;
            }
            k = k - (1 << t);
            ans++;
        }
        return 'a' + ans;
    }
};

/**
The __lg function in C++ is a non-standard, compiler-specific extension, typically found in GCC (GNU Compiler Collection). 
It is used to calculate the floor of the base-2 logarithm of a positive integer. More precisely, __lg(n) returns the 
largest integer k such that 2^k <= n
 */

class Solution {
public:
    char kthCharacter(int k) {
        string s = "a";
        while (true) {
            if (s.length() >= k) return s[k-1];

            for (int i = 0, len = s.length(); i < len; ++ i) {
                s += (s[i] == 'z') ? 'a' : (s[i] + 1);
            }
        }
    }
};


/**
3304. Find the K-th Character in String Game I
Easy

Alice and Bob are playing a game. Initially, Alice has a string word = "a".

You are given a positive integer k.

Now Bob will ask Alice to perform the following operation forever:

    Generate a new string by changing each character in word to its next character in the English alphabet, and append it to the original word.

For example, performing the operation on "c" generates "cd" and performing the operation on "zb" generates "zbac".

Return the value of the kth character in word, after enough operations have been done for word to have at least k characters.

 

Example 1:

Input: k = 5

Output: "b"
 */
