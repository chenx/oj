class NumArray {
public:
    NumArray(vector<int> &nums) {
        if (nums.size() == 0) return;
        
        base = nums;
        
        int sum = 0;
        for (int i = 0, len = nums.size(); i < len; ++ i) {
            sum += nums[i];
            sums.push_back(sum);
        }
    }

    int sumRange(int i, int j) {
        return sums[j] - sums[i] + base[i];
    }
private:
    vector<int> sums; // sums[i] = base[0] + base[1] + ... + base[i].
    vector<int> base; // input array.
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);

/**
Range Sum Query - Immutable
Difficulty: Easy

Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

Example:

Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3

Note:

    You may assume that the array does not change.
    There are many calls to sumRange function.
 */
