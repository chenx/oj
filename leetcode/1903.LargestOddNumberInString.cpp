
// Solution: find the first odd digit from RHS, return all chars before this.
// imagine the last digit is odd, should return entire string: n-1+1
// Time: O(n)
class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size(), i = n - 1;
        for (; i >= 0; -- i) {
            if ((num[i] - '0') % 2 == 1) {
                return num.substr(0, i + 1); 
            }
        }
        return "";
    }
};


/**
1903. Largest Odd Number in String
Easy


You are given a string num, representing a large integer. Return the largest-valued odd integer (as a string) 
that is a non-empty substring of num, or an empty string "" if no odd integer exists.

A substring is a contiguous sequence of characters within a string.

 

Example 1:

Input: num = "52"
Output: "5"
Explanation: The only non-empty substrings are "5", "2", and "52". "5" is the only odd number.

Example 2:

Input: num = "4206"
Output: ""
Explanation: There are no odd numbers in "4206".

Example 3:

Input: num = "35427"
Output: "35427"
Explanation: "35427" is already an odd number.
 */
