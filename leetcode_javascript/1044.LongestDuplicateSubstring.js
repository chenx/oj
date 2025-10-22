/**
 * @param {string} s
 * @return {string}
 */
var longestDupSubstring = function(s) {
    const n = s.length;
    const powers = Array(30010).fill(0);
    const rollingHashes = Array(30010).fill(0);
    const BASE = 131;

    powers[0] = 1;
    rollingHashes[0] = 0;
    for (let i = 0; i < n; ++ i) {
        powers[i+1] = powers[i] * BASE;
        rollingHashes[i+1] = rollingHashes[i] * BASE + s.charCodeAt(i);
    }

    let L = 0, R = n-1, ret = '';
    while (L < R) {
        let M = 1 + Math.floor( (L+R)/2 );
        const dup = findDup(s, M);
        if (dup === '') {
            R = M-1;
        } else {
            ret = dup;
            L = M;
        }
    }
    return ret;

    function findDup(s, len) {
        const foundHashes = new Set();

        for (let i = 0; i + len <= s.length; ++ i) {
            j = i + len;
            const hash = rollingHashes[j] - rollingHashes[i] * powers[j-i];
            if (foundHashes.has(hash)) return s.substring(i, j);
            foundHashes.add(hash);
        }
        return '';
    }
};
