/**
 * @param {number[]} nums
 * @return {number}
 */
var lengthOfLIS = function(nums) {
    const n = nums.length;

    const vals = [];

    for (let i = 0; i < n; ++ i) {
        if (vals.length === 0 || nums[i] > vals[vals.length - 1]) {
            vals.push(nums[i]);
        } else {
            let L = 0; R = vals.length - 1;
            while (L <= R) {
                const M = Math.floor( (L+R)/2 );
                if (nums[i] > vals[M]) { // !!!
                    L = M + 1;
                } else {
                    R = M - 1;
                }
            }
            vals[L] = nums[i];
        }
    }
    return vals.length;
};
