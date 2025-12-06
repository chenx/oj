// Math solution: K(K+1)/2 <= N
// Time: O(1)
// Space: O(1)
class Solution2 {
public:
    int arrangeCoins(int n) {
        return (int)(sqrt(2 * (long)n + 0.25) - 0.5);
    }
};

// Time: O(log(n))
// Space: O(1)
class Solution {
public:
    int arrangeCoins(int n) {
        int left = 0, right = n;
        long k, curr;
        while (left <= right) {
            k = left + (right - left) / 2;
            curr = k * (k + 1) / 2;

            if (curr == n) return (int)k;

            if (curr > n) {
                right = k - 1;
            } else {
                left = k + 1;
            }
        }
        return right;
    }
};


/**
441. Arranging Coins
Easy


You have n coins and you want to build a staircase with these coins. The staircase consists 
of k rows where the ith row has exactly i coins. The last row of the staircase may be incomplete.

Given the integer n, return the number of complete rows of the staircase you will build.
 */
