/**
 * @param {number[]} nums
 * @return {number}
 */
var longestConsecutive = function(nums) {
    const s = new Set();
    nums.forEach(num => s.add(num));

    let maxLen = 0;
    while (s.size !== 0) {
        const n = s.values().next().value;
        s.delete(n);
        let len = 1;
        for (let i = n - 1; s.has(i); -- i) { 
            s.delete(i);
            ++ len;
        }
        for (let i = n + 1; s.has(i); ++ i) { 
            s.delete(i);
            ++ len;
        }
        maxLen = Math.max(maxLen, len);
    }
    return maxLen;
};
