// Works. Tested! Great solution.
// From: https://leetcode.com/discuss/86891/concise-java-solution-with-comments
class Solution2 {
public:
    bool increasingTriplet(vector<int>& nums) {
        int small = INT_MAX, big = INT_MAX;
        for (int n : nums) {
            if (n <= small) { small = n; } // update small if n is smaller than both
            else if (n <= big) { big = n; } // update big only if greater than small but smaller than big
            else return true; // return if you find a number bigger than both
        }
        return false;
    }
};

// Works. Tested. By: XC
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if (nums.size() < 3) return false;
        
        int a, b = INT_MIN;
        for (int i = 0; i < nums.size() - 1; ++ i) {
            if (nums[i] < nums[i+1]) {
                // if a, b are assigned, a < b, then b cannot be INT_MIN.
                if (b == INT_MIN) { 
                    a = nums[i];
                    b = nums[i+1];
                }
                else {
                    // a < b, nums[i] < nums[i+1].
                    // if a < nums[i], then (a, nums[i], nums[i+1]) is a triplet
                    // else, if b < nums[i+1], then (a, b, nums[i+1]) is a triplet.
                    if (a >= nums[i] && b >= nums[i+1]) { 
                        a = nums[i];
                        b = nums[i+1];
                    }
                    else {
                        return true; 
                    }
                }
            }
        }
        return false;
    }
};


/**
Increasing Triplet Subsequence
Difficulty: Medium

Given an unsorted array return whether an increasing subsequence of 
length 3 exists or not in the array.

Formally the function should:

    Return true if there exists i, j, k
    such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false. 

Your algorithm should run in O(n) time complexity and O(1) space complexity.

Examples:
Given [1, 2, 3, 4, 5],
return true.

Given [5, 4, 3, 2, 1],
return false. 
 */
