class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        // largest sum: all positive.
        // n <= k? make all positive, if there is one neg, choose the smallest one.
        // n > k, make as many positive as possible.
        // order, count number of negs.

        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() && nums[i] < 0 && k > 0; ++ i, -- k) {
            nums[i] = - nums[i];
        }

        if (k == 0 || k % 2 == 0) {
            return accumulate(nums.begin(), nums.end(), 0);
        }
        // k is odd, just make the smallest number negative.
        sort(nums.begin(), nums.end());
        return accumulate(nums.begin(), nums.end(), 0) - 2 * nums[0];
    }
};

/**
1005. Maximize Sum Of Array After K Negations

Given an integer array nums and an integer k, modify the array in the following way:

    choose an index i and replace nums[i] with -nums[i].

You should apply this process exactly k times. You may choose the same index i multiple times.

Return the largest possible sum of the array after modifying it in this way.
 */
