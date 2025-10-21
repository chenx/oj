/**
 * @param {character[]} chars
 * @return {number}
 */
var compress = function(chars) {
    let cur = '', s = '';
    let count = 0;
    for (let i = 0, n = chars.length; i < n; ++ i) {
        if (chars[i] !== cur) {
            s += cur; 
            if (count > 1) s += count.toString();

            cur = chars[i];
            count = 1;
        } else {
            ++ count;
        }
    }
    s += cur; 
    if (count > 1) s += count.toString();

    for (let i = 0; i < s.length; ++ i) {
        chars[i] = s.charAt(i);
    }

    return s.length;
};
