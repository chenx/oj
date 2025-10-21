/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var moveZeroes = function(nums) {
    let i = 0, p = 0, n = nums.length;

    while (i < n) {
        if (nums[i] !== 0) {
            nums[p ++] = nums[i ++];
        } else {
            ++ i;
        }
    }

    while (p < n) {
        nums[p ++] = 0;
    }
};
