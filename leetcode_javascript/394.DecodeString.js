/**
 * @param {string} s
 * @return {string}
 */
var decodeString = function(s) {
    const n = s.length;
    const strStack = [], numStack = [];

    let cur = '', count = 0;

    for (let i = 0; i < n; ++ i) {
        const c = s.charAt(i);

        if (c >= '0' && c <= '9') {
            count = count * 10 + (c - '0');
        } else if (c === '[') {
            numStack.push(count);
            strStack.push(cur);

            cur = '';
            count = 0;
        } else if (c === ']') {
            let str = strStack.pop();
            const ct = numStack.pop();

            str += cur.repeat(ct);
            cur = str;
        } else {
            cur += c;
        }
    }

    return cur;
};
