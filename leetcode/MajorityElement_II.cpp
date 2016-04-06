// Works. Code cleaned from Solution, using C++11 feature (auto loop).
class Solution2 {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return vector<int>();
        
        int n1 = 0, n2 = 0, ct1 = 0, ct2 = 0;
        
        for (auto n : nums) {
            if (n == n1) ++ ct1;
            else if (n == n2) ++ ct2;
            else if (ct1 == 0) n1 = n, ct1 = 1;
            else if (ct2 == 0) n2 = n, ct2 = 1;
            else -- ct1, -- ct2;
        }
        
        ct1 = ct2 = 0;
        for (auto n : nums) {
            if (n == n1) ++ ct1;
            else if (n == n2) ++ ct2;
        }
        
        vector<int> ans;
        if (ct1 * 3 > n) ans.push_back(n1);
        if (ct2 * 3 > n) ans.push_back(n2);
        
        return ans;
    }
};

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
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int len = nums.size();
        
        // n1, n2 can be any 2 numbers that are not equal.
        int n1 = 0, n2 = 1, ct1 = 0, ct2 = 0;
        
        // Note: cannot make "ct1 == 0, ct2 == 0" before "n1 == .., n2 == ..",
        // otherwise n1 and n2 may be equal, and result wrong. e.g.: {8,8,7,7,7}.
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
        
        if (ct1 > len/3) ans.push_back(n1);
        if (ct2 > len/3) ans.push_back(n2);
        
        return ans;
    }
};

/**
Majority Element II
Total Accepted: 16753 Total Submissions: 70025 Difficulty: Medium

Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times. 
The algorithm should run in linear time and in O(1) space.

Hint:

    How many majority elements could it possibly have? (answer: 0, 1 or 2).
 */
