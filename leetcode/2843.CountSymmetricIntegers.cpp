// Assume: 1 <= low <= high <= 10^4
// Time complexity: O(high−low).
// Space: O(1)
class Solution2 {
    public int countSymmetricIntegers(int low, int high) {
        int res = 0;
        for (int a = low; a <= high; ++a) {
            if (a < 100 && a % 11 == 0) {
                res++;
            } else if (1000 <= a && a < 10000) {
                int left = a / 1000 + (a % 1000) / 100;
                int right = (a % 100) / 10 + (a % 10);
                if (left == right) {
                    res++;
                }
            }
        }
        return res;
    }
}


// Time complexity: O((high−low) * L). L is max length of a number, 4 if high <= 10000.
// Space: O(1)
class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        for (int i = low; i <= high; ++ i) {
            string s = to_string(i);
            int len = s.length();
            if (len % 2 == 0) {
                int sum1 = 0, sum2 = 0;
                for (int j = 0; j < len/2; ++ j) sum1 += s[j] - '0';
                for (int j = len/2; j < len; ++ j) sum2 += s[j] - '0';
                if (sum1 == sum2) ++ count;
            }
        }
        return count;
    }
};


/**
2843. Count Symmetric Integers
Easy

You are given two positive integers low and high.

An integer x consisting of 2 * n digits is symmetric if the sum of the first n digits of x is equal to the 
sum of the last n digits of x. Numbers with an odd number of digits are never symmetric.

Return the number of symmetric integers in the range [low, high].

 

Example 1:

Input: low = 1, high = 100
Output: 9
Explanation: There are 9 symmetric integers between 1 and 100: 11, 22, 33, 44, 55, 66, 77, 88, and 99.

Example 2:

Input: low = 1200, high = 1230
Output: 4
Explanation: There are 4 symmetric integers between 1200 and 1230: 1203, 1212, 1221, and 1230.
 */
