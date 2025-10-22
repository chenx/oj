/**
 * @param {string} s
 * @return {boolean}
 */
var checkValidString = function(s) {
    const n = s.length;
    let count = 0, count2 = 0;

    for (let i = 0; i < n; ++ i) {
        const c = s.charAt(i);
        if (c === '(' || c === '*') ++ count;
        else -- count;

        const d = s.charAt(n - 1 - i);
        if (d === ')' || d === '*') ++ count2;
        else -- count2;

        if (count < 0 || count2 < 0) return false;
    }

    return true;
};
