// From: https://leetcode.com/problems/find-the-derangement-of-an-array/editorial/
// d(n)=(n−1)⋅[d(n−1)+d(n−2)]
// 
// Time complexity : O(n). memo array of length n is filled once only.
// Space complexity : O(1).
//
class Solution {
public:
    int findDerangement(int n) {
        if (n == 0)
            return 1;
        if (n == 1)
            return 0;
        int first = 1, second = 0;
        for (int i = 2; i <= n; i++) {
            int temp = second;
            second = (((i - 1L) * (first + second)) % 1000000007);
            first = temp;
        }
        return second;
    }
};


/**
634. Find the Derangement of An Array
Solved
Medium
Topics
conpanies iconCompanies

In combinatorial mathematics, a derangement is a permutation of the elements of a set, 
such that no element appears in its original position.

You are given an integer n. There is originally an array consisting of n integers from 
1 to n in ascending order, return the number of derangements it can generate. Since 
the answer may be huge, return it modulo 109 + 7.

 

Example 1:

Input: n = 3
Output: 2
Explanation: The original array is [1,2,3]. The two derangements are [2,3,1] and [3,1,2].

Example 2:

Input: n = 2
Output: 1
 */
