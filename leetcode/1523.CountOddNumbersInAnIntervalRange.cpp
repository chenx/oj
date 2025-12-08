class Solution {
public:
    int countOdds(int low, int high) {
        // If low is even, make it odd.
        if (!(low & 1)) {
            low++;
        }
  
        // low could become greater than high due to incrementation
        // if it is, the answer is 0; otherwise, use the formula.
        return low > high ? 0 : (high - low) / 2 + 1;
    }
};


/**
1523. Count Odd Numbers in an Interval Range
Easy

Given two non-negative integers low and high. Return the count of odd numbers between low and high (inclusive).

 

Example 1:

Input: low = 3, high = 7
Output: 3
Explanation: The odd numbers between 3 and 7 are [3,5,7].

Example 2:

Input: low = 8, high = 10
Output: 1
Explanation: The odd numbers between 8 and 10 are [9].
 */
