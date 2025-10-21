/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
    let entries = [['{', '}'], ['[', ']'], ['(', ')']];
    const map = new Map(entries);

    const stack = [];

    const chars = s.split('');
    for (const c of chars) {
        switch(c) {
            case '[':
            case '{':
            case '(':
                stack.push(map.get(c));
                break;
            case ')':
            case '}':
            case ']':
                if (stack.length === 0 || stack[stack.length - 1] != c) return false;
                stack.pop();
                break;
        }
    }
    return stack.length === 0;
};

/*
map<char, char> m = {{'(', ')'}, {'{', '}'}, {'[', ']'}};
        stack<char> st;

        for (char c : s) {
            switch (c) {
                case '(':
                case '{':
                case '[':
                    st.push(m[c]);
                    break;
                case ')':
                case '}':
                case ']':
                    if (st.empty() || c != st.top()) return false;
                    st.pop();
                    break;
                default:
                    return false;
            }
        }
        return st.empty();
*/
