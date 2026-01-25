class Solution2 {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int curMaxSum = nums[0], curMinSum = nums[0], maxSum = nums[0], minSum = nums[0], total = nums[0];

        for (int i = 1; i < nums.size(); ++ i) {
            if (curMaxSum < 0) curMaxSum = 0;
            curMaxSum += nums[i];
            maxSum = max(maxSum, curMaxSum);

            if (curMinSum > 0) curMinSum = 0;
            curMinSum += nums[i];
            minSum = min(minSum, curMinSum);

            total += nums[i];
        }

        return minSum == total ? maxSum : max(maxSum, total - minSum);
    }
};

// O(n) time, O(1) space.
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int sum1 = maxSubArray(nums), total = 0;

        for (int i = 0; i < nums.size(); ++ i) {
            total += nums[i];
            nums[i] = - nums[i];
        }

        int sum2 = total + maxSubArray(nums);  // Total minus the negative max sum.
        // sum2 = 0 : in this case all elements are negative, ignore sum2 in this case.
        // This is because: if total == -maxSumArray(nums), then every num is used to get sum2;
        // so every num after negation is positive, thus every num is negative initially.
        return sum2 == 0 ? sum1 : max(sum1, sum2);
    }

    // Kadane's sum algorithm.
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int sum = nums[0], maxSum = nums[0];

        for (int i = 1; i < nums.size(); ++ i) {
            if (sum < 0) sum = 0;
            sum += nums[i];
            if (sum > maxSum) maxSum = sum;
        }
        return maxSum;
    }
};

/**
918. Maximum Sum Circular Subarray

Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.

A circular array means the end of the array connects to the beginning of the array. Formally, the next element of
nums[i] is nums[(i + 1) % n] and the previous element of nums[i] is nums[(i - 1 + n) % n].

A subarray may only include each element of the fixed buffer nums at most once. Formally, for a subarray nums[i],
nums[i + 1], ..., nums[j], there does not exist i <= k1, k2 <= j with k1 % n == k2 % n.
 */
