// https://www.geeksforgeeks.org/dsa/check-if-given-number-is-perfect-square-in-cpp/

// n^2 = 1 + 3 + 5 + .. + (2n - 1)
// Works.
class Solution2 {
public:
   bool isPerfectSquare(int num) {
       if (num == 0) return false;


       int odd = 1;
       while (num > 0) {
           num -= odd;
           odd += 2;
       }
       return num == 0;
   }
};

// Works.
class Solution {
public:
   bool isPerfectSquare(int num) {
       if (num <= 0) return false;


       int L = 1, R = num;
       while (L <= R) {
           long long M = L + (R - L) / 2;
           long long p = M*M;
           if (p == num) return true;
           else if (p < num) L = M + 1;
           else R = M - 1;
       }
       return false;
   }
};


/**
Valid Perfect Square.

Given a positive integer num, return true if num is a perfect square or false otherwise.

A perfect square is an integer that is the square of an integer. In other words, it is the product of some integer with itself.

You must not use any built-in library function, such as sqrt.

Example 1:

Input: num = 16
Output: true
Explanation: We return true because 4 * 4 = 16 and 4 is an integer.

Example 2:

Input: num = 14
Output: false
Explanation: We return false because 3.742 * 3.742 = 14 and 3.742 is not an integer.
*/
