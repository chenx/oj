/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    // 2 pointers
    let maxLen = 0, n = s.length;
    const map = new Map(); // char, count
    for (let i = 0, begin = 0; i < n; ++ i) {
        let c = s.charAt(i);
        map.set(c, map.has(c) ? map.get(c) + 1 : 1);

        while (map.get(c) > 1) {
            let d = s.charAt(begin);
            map.set(d, map.get(d) - 1);
            ++ begin;
        }
        maxLen = Math.max(maxLen, i - begin + 1);
    }
    return maxLen;
};
