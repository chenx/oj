class Solution {
public:
   int integerReplacement(int n) {
       int ct = 0, minCt = INT_MAX;
       replace(n, ct, minCt);
       return minCt;
   }


   void replace(long long n, int ct, int& minCt) {
       if (n == 1) {
           minCt = min(minCt, ct);
           return;
       }


       if (n & 1) {
           replace(n+1, ct + 1, minCt);
           replace(n-1, ct + 1, minCt);
       } else {
           replace(n/2, ct + 1, minCt);
       }
   }
};

/**
Given a positive integer n, you can apply one of the following operations:
    If n is even, replace n with n / 2.
    If n is odd, replace n with either n + 1 or n - 1.
Return the minimum number of operations needed for n to become 1.

Example 1:

Input: n = 8
Output: 3
Explanation: 8 -> 4 -> 2 -> 1

Example 2:

Input: n = 7
Output: 4
Explanation: 7 -> 8 -> 4 -> 2 -> 1
or 7 -> 6 -> 3 -> 2 -> 1

Example 3:

Input: n = 4
Output: 2
 */
