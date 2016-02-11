// Should work. But times out for large input.
class NumArray {
public:
    NumArray(vector<int> &nums) {
        if (nums.size() == 0) return;
        base = nums;
        
        int sum = 0;
        for (int i = 0; i < nums.size(); ++ i) {
            sum += base[i];
            sums.push_back(sum);
        }
    }

    void update(int i, int val) {
        int diff = val - base[i];
        for (int j = i; j < sums.size(); ++ j) {
            sums[j] += diff;
        }
        base[i] = val;
    }

    int sumRange(int i, int j) {
        return sums[j] - sums[i] + base[i];
    }
private:
    vector<int> base;
    vector<int> sums;
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);

/**
Range Sum Query - Mutable
Difficulty: Medium

Given an integer array nums, find the sum of the elements between 
indices i and j (i ≤ j), inclusive.
The update(i, val) function modifies nums by updating the element 
at index i to val.

Example:

Given nums = [1, 3, 5]

sumRange(0, 2) -> 9
update(1, 2)
sumRange(0, 2) -> 8

Note:

    The array is only modifiable by the update function.
    You may assume the number of calls to update and sumRange 
      function is distributed evenly.

 */
