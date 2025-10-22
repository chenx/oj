// Works too.
var rotate2 = function(nums, k) {
    const n = nums.length;
    k %= n;

    reverse(nums, 0, n-1);
    reverse(nums, 0, k-1);
    reverse(nums, k, n-1);

    function reverse(nums, i, j) {
        for (; i < j; ++ i, -- j) {
            const tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
        }
    }
};


/**
 * @param {number[]} nums
 * @param {number} k
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var rotate = function(nums, k) {
    const n = nums.length;
    k %= n;

    reverse(nums, 0, n-1);
    reverse(nums, 0, k-1);
    reverse(nums, k, n-1);
};

function reverse(nums, i, j) {
    for (; i < j; ++ i, -- j) {
        const tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
}
