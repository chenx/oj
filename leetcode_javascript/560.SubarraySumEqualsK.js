/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var subarraySum = function(nums, k) {
    const n = nums.length;
    let sum = 0, count = 0;
    const map = new Map(); // num, count

    map.set(0, 1);  // don't forget.
    nums.forEach(num => {
        sum += num;
        const ct = map.get(sum - k) || 0;
        if (ct > 0) {
            count += ct;
        }
        map.set(sum, (map.get(sum) || 0) + 1);
    });
    return count;
};
