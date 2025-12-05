// From: https://leetcode.com/problems/number-complement/editorial/
// Flip Bit by Bit
// Time: O(32) =~ O(1)
// Space: O(1)
class Solution {
  public int findComplement(int num) {
    int todo = num, bit = 1;
    while (todo != 0) {
      // flip the current bit
      num = num ^ bit;

      // prepare for the next run
      bit = bit << 1;
      todo = todo >> 1;
    }
    return num;
  }
}


// From: https://leetcode.com/problems/number-complement/editorial/
// Compute Bit Length and Construct 1-bit Bitmask
// Time: O(1)
// Space: O(1)
class Solution2 {
  public int findComplement(int num) {
    // n is a length of num in binary representation
    int n = (int)( Math.log(num) / Math.log(2) ) + 1;
    // The bitmask has the same length as num and contains only ones 1...1
    int bitmask = (1 << n) - 1;
    // Flip all bits
    return bitmask ^ num;
  }
}


// Time: O(log(num))
// Space: O(1)
class Solution {
public:
    int findComplement(int num) {
        long long i = 1;
        while (i <= num) i <<= 1;

        return num ^ (i - 1);
    }
};


/**
476. Number Complement
Easy

The complement of an integer is the integer you get when you flip all the 0's to 1's and 
all the 1's to 0's in its binary representation.

    For example, The integer 5 is "101" in binary and its complement is "010" which is the integer 2.

Given an integer num, return its complement.

 

Example 1:

Input: num = 5
Output: 2
Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement 
is 010. So you need to output 2.

Example 2:

Input: num = 1
Output: 0
Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. 
So you need to output 0.
 */
