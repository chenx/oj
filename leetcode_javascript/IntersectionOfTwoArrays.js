// Version 2.
var intersection = function(nums1, nums2) {
    const set1 = new Set();
    nums1.forEach(n => set1.add(n));

    const set2 = new Set();
    nums2.forEach(n => set2.add(n));

    const ret = [];
    for (const n of set1) {
        if (set2.has(n)) ret.push(n);
    }
    return ret;
};

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
