/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var searchRange = function(nums, target) {
    let n = nums.length;
    const ans = [];

    ans.push(getStartIndex(nums, target));
    ans.push(getStartIndex(nums, target + 1) - 1);

    if (ans[1] < 0 || ans[1] >= n || nums[ans[1]] !== target) return [-1, -1];  // !!
    return ans;

    function getStartIndex(nums, target) {
        let L = 0, R = n - 1, ret = n;

        while (L <= R) {
            const M = L + Math.floor( (R-L)/2 ); // <-- Math.floor !!!
            if (nums[M] >= target) {
                ret = M;
                R = M - 1;
            } else {
                L = M + 1;
            }
        }
        return ret;
    }
};
