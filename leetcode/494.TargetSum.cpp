// Brute force.
// Time complexity: O(2^n)
// Space complexity: O(n)
class Solution3 {
public:
    int totalWays = 0;  // Tracks the total number of ways to reach the target

    int findTargetSumWays(std::vector<int>& nums, int target) {
        calculateWays(nums, 0, 0, target);
        return totalWays;
    }

private:
    void calculateWays(std::vector<int>& nums, int currentIndex, int currentSum, int target) {
        if (currentIndex == nums.size()) {
            if (currentSum == target) totalWays++;
            return;
        }

        // Include the current number with a positive sign
        calculateWays(nums, currentIndex + 1, currentSum + nums[currentIndex], target);
        // Include the current number with a negative sign
        calculateWays(nums, currentIndex + 1, currentSum - nums[currentIndex], target);
    }
};


// 2D Dynamic Programming
// Time complexity: O(n⋅totalSum)
// Space complexity: O(n⋅totalSum)
class Solution2 {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> dp(nums.size(), vector<int>(2 * totalSum + 1, 0));

        // Initialize the first row of the DP table
        dp[0][nums[0] + totalSum] = 1;
        dp[0][-nums[0] + totalSum] += 1;

        // Fill the DP table
        for (int index = 1; index < nums.size(); index++) {
            for (int sum = -totalSum; sum <= totalSum; sum++) {
                if (dp[index - 1][sum + totalSum] > 0) {
                    dp[index][sum + nums[index] + totalSum] += dp[index - 1][sum + totalSum];
                    dp[index][sum - nums[index] + totalSum] += dp[index - 1][sum + totalSum];
                }
            }
        }

        // Return the result if the target is within the valid range
        return abs(target) > totalSum ? 0 : dp[nums.size() - 1][target + totalSum];
    }
};


// Recursion with memorization.
class Solution {
public:
    int totalSum;

    int findTargetSumWays(vector<int>& nums, int target) {
        totalSum = accumulate(nums.begin(), nums.end(), 0);

        vector<vector<int>> memo(
            nums.size(),
            vector<int>(2 * totalSum + 1, numeric_limits<int>::min()));
        return calculateWays(nums, 0, 0, target, memo);
    }

    int calculateWays(vector<int>& nums, int currentIndex, int currentSum,
                      int target, vector<vector<int>>& memo) {
        if (currentIndex == nums.size()) {
            // Check if the current sum matches the target
            if (currentSum == target) {
                return 1;
            } else {
                return 0;
            }
        } else {
            // Check if the result is already computed
            if (memo[currentIndex][currentSum + totalSum] !=
                numeric_limits<int>::min()) {
                return memo[currentIndex][currentSum + totalSum];
            }
            // Calculate ways by adding the current number
            int add =
                calculateWays(nums, currentIndex + 1,
                              currentSum + nums[currentIndex], target, memo);

            // Calculate ways by subtracting the current number
            int subtract =
                calculateWays(nums, currentIndex + 1,
                              currentSum - nums[currentIndex], target, memo);

            // Store the result in memoization table
            memo[currentIndex][currentSum + totalSum] = add + subtract;

            return memo[currentIndex][currentSum + totalSum];
        }
    }
};

/**
494. Target Sum
Medium

You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer 
in nums and then concatenate all the integers.

    For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to 
    build the expression "+2-1".

Return the number of different expressions that you can build, which evaluates to target.

 

Example 1:

Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3
 */
