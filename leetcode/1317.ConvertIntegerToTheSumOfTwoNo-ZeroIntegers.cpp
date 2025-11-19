// From: https://leetcode.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers/editorial
// Time complexity: O(nlogn).
// We enumerate all possible values of A in O(n). For each pair (A,B), we check whether their decimal representations 
// contain a zero. This check takes O(logn) time, since the number of digits in A and B is O(logn).
// Space complexity: O(1).
//
class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        for (int A = 1; A < n; ++A) {
            int B = n - A;
            if ((to_string(A) + to_string(B)).find('0') == string::npos) {
                return {A, B};
            }
        }
        return {};
    }
};

/**
1317. Convert Integer to the Sum of Two No-Zero Integers
Easy

No-Zero integer is a positive integer that does not contain any 0 in its decimal representation.

Given an integer n, return a list of two integers [a, b] where:

    a and b are No-Zero integers.
    a + b = n

The test cases are generated so that there is at least one valid solution. 
If there are many valid solutions, you can return any of them.

 

Example 1:

Input: n = 2
Output: [1,1]
Explanation: Let a = 1 and b = 1.
Both a and b are no-zero integers, and a + b = 2 = n.

Example 2:

Input: n = 11
Output: [2,9]
Explanation: Let a = 2 and b = 9.
Both a and b are no-zero integers, and a + b = 11 = n.
Note that there are other valid answers as [8, 3] that can be accepted.
 */
