//
// This works.
// From: https://leetcode.com/discuss/69126/concise-java-solution-based-on-moores-voting-algorithm
// The basic idea is based on Moore's Voting Algorithm, we need top two candidates. 
// If got different number from the candidates, decrease *both* counts by 1, otherwise increase by 1.  
// If a count equals 0, switch the candidate to the current number. 
// The trick is that a second counting is needed for the top two candidates
// to guarantee both occur more than 1/3. 
// Finally, output the numbers appearing more than n/3 times.
//
public class Solution {
    public List<Integer> majorityElement(int[] nums) {
        List<Integer> ans = new ArrayList<Integer>();
        int len = nums.length;
        
        // n1, n2 can be any 2 numbers that are not equal.
        int n1 = 0, n2 = 1, ct1 = 0, ct2 = 0;
        
        for (int i = 0; i < len; ++ i) {
            if (n1 == nums[i]) ++ ct1;
            else if (n2 == nums[i]) ++ ct2;
            else if (ct1 == 0) {
                n1 = nums[i];
                ct1 = 1;
            }
            else if (ct2 == 0) {
                n2 = nums[i];
                ct2 = 1;
            }
            else { -- ct1; -- ct2; }
        }
        
        ct1 = ct2 = 0;
        for (int i = 0; i < len; ++ i) {
            if (nums[i] == n1) ++ ct1;
            else if (nums[i] == n2) ++ ct2;
        }
        
        if (ct1 > len/3) ans.add(n1);
        if (ct2 > len/3) ans.add(n2);
        
        return ans;        
    }
}

/**
Majority Element II
Total Accepted: 16753 Total Submissions: 70025 Difficulty: Medium

Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times. 
The algorithm should run in linear time and in O(1) space.

Hint:

    How many majority elements could it possibly have? (answer: 0, 1 or 2).
 */
