/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function(strs) {
    const n = strs.length;
    if (n === 0) return 0;

    let maxLen = strs[0].length;

    for (let i = 1; i < n; ++ i) {
        let len = Math.min(maxLen, strs[i].length);
        let j = 0;
        for (; j < len; ++ j) {
            if (strs[0].charAt(j) !== strs[i].charAt(j)) {
                break;
            }
        }
        maxLen = Math.min(maxLen, j);
    }

    return strs[0].substring(0, maxLen);
};
