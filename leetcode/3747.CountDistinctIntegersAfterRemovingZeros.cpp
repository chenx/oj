// From: https://www.youtube.com/watch?v=37ZfxBxwf6M
//
class Solution {
public:
    long long countDistinct(long long n) {
        string s = to_string(n);
        int len = s.length();
        long long total = 0, power = 9;

        for (int i = 1; i < len; ++ i) {
            total += power;
            power *= 9;
        }

        for (int i = 0; i < len; ++ i) {
            int digit = s[i] - '0';
            for (int d = 1; d < digit; ++ d) {
                int rem = len - 1 - i;
                total += pow(9, rem);
            }
            if (digit == 0) break;
            if (i == len - 1) total += 1;
        }
        return total;
    }
};


// Brute force. Times out for large input.
class Solution {
public:
    long long countDistinct(long long n) {
        set<string> set;

        for (int i = 1; i <= n; ++ i) {
            string s = to_string(i);
            string t;
            for (int j = 0; j < s.length(); ++ j) {
                if (s[j] != '0') t += s[j];
            }
            set.insert(t);
        }

        return set.size();
    }
};


/**
3747. Count Distinct Integers After Removing Zeros
Medium

You are given a positive integer n.

For every integer x from 1 to n, we write down the integer obtained by removing all zeros from the decimal representation of x.

Return an integer denoting the number of distinct integers written down.

 

Example 1:

Input: n = 10

Output: 9

Explanation:

The integers we wrote down are 1, 2, 3, 4, 5, 6, 7, 8, 9, 1. There are 9 distinct integers (1, 2, 3, 4, 5, 6, 7, 8, 9).

Example 2:

Input: n = 3

Output: 3

Explanation:

The integers we wrote down are 1, 2, 3. There are 3 distinct integers (1, 2, 3).
 */
