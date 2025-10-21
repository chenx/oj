/**
 * @param {string} s
 * @return {boolean}
 */
var isPalindrome = function(s) {
    let n = s.length, L = 0, R = n - 1;
    while (L < R) {
        while (L < R && !isAlnum(s.charAt(L))) ++ L;
        while (L < R && !isAlnum(s.charAt(R))) -- R;
        if (L < R) {
            if (s.charAt(L).toLowerCase() != s.charAt(R).toLowerCase()) {
                return false;
            }
            ++ L, -- R;
        }
    }
    return true;
};

var isAlnum = (c) => {
    return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}
