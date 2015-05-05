class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        k %= len;
        if (k == 0) return;

        k = len - 1 - k; // note this.
        reverse(nums, 0, k);
        reverse(nums, k+1, len-1);
        reverse(nums, 0, len-1);
    }
    
    void reverse(vector<int>& v, int start, int end) {
        for (; start < end; ++ start, -- end) {
            swap(v[start], v[end]);
        }
    }
};

/**
Rotate Array.

Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

Note:
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.

[show hint]
Hint:
Could you do it in-place with O(1) extra space?

Related problem: Reverse Words in a String II
 */
