// Prefix sum. Best answer.
// Time complexity: O(n). Space complexity: O(1).
class Solution2 {
    public int countValidSelections(int[] nums) {
        int n = nums.length, ans = 0, sum = 0;
        for (int x : nums) sum += x;

        int leftSum = 0;
        int rightSum = sum;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                int a = leftSum - rightSum;  // start direction: going left
                int b = rightSum - leftSum;  // start direction: going right
                if (a == 0 || a == 1) ++ ans;
                if (b == 0 || b == 1) ++ ans;
            } else {
                leftSum += nums[i];
                rightSum -= nums[i];
            }
        }
        return ans;
    }
}

// Simulation.
// Let n be the length of the array nums, and m be the maximum element in nums.
// Time complexity: O(n2m). Space complexity: O(n).
class Solution {
    public int countValidSelections(int[] nums) {
        int count = 0;
        int nonZeros = 0;
        int n = nums.length;
        for (int x : nums) if (x > 0) nonZeros++;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                if (isValid(nums, nonZeros, i, -1)) count++;
                if (isValid(nums, nonZeros, i, 1)) count++;
            }
        }
        return count;
    }

    private boolean isValid(
        int[] nums,
        int nonZeros,
        int start,
        int direction
    ) {
        int n = nums.length;
        int curr = start;
        int[] temp = nums.clone();
        while (nonZeros > 0 && curr >= 0 && curr < n) {
            if (temp[curr] > 0) {
                temp[curr]--;
                direction *= -1;
                if (temp[curr] == 0) nonZeros--;
            }
            curr += direction;
        }
        return nonZeros == 0;
    }
}

/**
3354. Make Array Elements Equal to Zero
Easy

You are given an integer array nums.

Start by selecting a starting position curr such that nums[curr] == 0, and choose a movement direction of either left or right.

After that, you repeat the following process:

    If curr is out of the range [0, n - 1], this process ends.
    If nums[curr] == 0, move in the current direction by incrementing curr if you are moving right, or decrementing curr 
        if you are moving left.
    Else if nums[curr] > 0:
        Decrement nums[curr] by 1.
        Reverse your movement direction (left becomes right and vice versa).
        Take a step in your new direction.

A selection of the initial position curr and movement direction is considered valid if every element in nums becomes 0 
by the end of the process.

Return the number of possible valid selections.
 */
