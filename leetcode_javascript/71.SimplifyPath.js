// Note JS has no built in JavaScript. Use [] instead.
/**
 * @param {string} path
 * @return {string}
 */
var simplifyPath = function(path) {
    const n = path.length;

    let token = '';
    const stack = [];
    const process = () => {
        if (token === '' || token === '.') {
            // do nothing.
        } else if (token === '..') {
            if (stack.length > 0) stack.pop();
        } else {
            stack.push(token);
        }
        token = '';
    };

    path.split('').forEach(ch => {
        if (ch === '/') process();
        else token += ch;
    });
    process();

    let ans = '';
    while (stack.length > 0) {
        if (ans !== '') ans = '/' + ans;
        ans = stack[stack.length - 1] + ans;
        stack.pop();
    }
    ans = '/' + ans;

    return ans;
};
