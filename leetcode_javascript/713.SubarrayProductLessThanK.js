/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var numSubarrayProductLessThanK = function(nums, k) {
    if (k <= 1) return 0;
    const n = nums.length;
    let count = 0, product = 1;

    for (let i = 0, begin = 0; i < n; ++ i) {
        product *= nums[i];

        while (product >= k) {
            product /= nums[begin];
            ++ begin;
        }
        count += i - begin + 1;
    }
    return count;
};
