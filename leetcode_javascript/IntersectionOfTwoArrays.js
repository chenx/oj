/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var intersection = function(nums1, nums2) {
    const set = new Set();

    for (const n of nums1) {
        set.add(n);
    }

    const ans = new Set();
    for (const n of nums2) {
        if (set.has(n)) {
            ans.add(n);
        }
    }

    const ret = [];
    for (const n of ans) {
        ret.push(n);
    }
    return ret;
};
