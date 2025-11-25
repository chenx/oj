/**
 * @param {string} s
 * @param {string} t
 * @return {string}
 */
var minWindow = function(s, t) {
    const toFind = new Map(), found = new Map();

    const inc = (map, ch) => {
        if (map.has(ch)) map.set(ch, map.get(ch) + 1);
        else map.set(ch, 1);
    };
    const get = (map, ch) => {
        return map.has(ch) ? map.get(ch) : 0;
    };

    // for (const c of t.split('')) inc(toFind, c);
    t.split('').forEach((c) => inc(toFind, c));

    let minLen = 0, pos = 0, total = 0;
    for (let i = 0, left = 0; i < s.length; ++ i) {
        const c = s.charAt(i);
        inc(found, c);
        if (get(found, c) <= get(toFind, c)) ++ total;

        if (total === t.length) {
            let d = s.charAt(left);
            // while ( get(toFind, d) === 0 || found.get(d) > toFind.get(d)) {
            while (get(found, d) > get(toFind, d)) {
                found.set(d, found.get(d) - 1);
                d = s.charAt(++ left);
            }

            const len = i - left + 1;
            if (minLen === 0 || minLen > len) {
                minLen = len;
                pos = left;
            }
        }
    }
    return s.substr(pos, minLen);

    // function inc(map, ch) {
    //     if (map.has(ch)) map.set(ch, map.get(ch) + 1);
    //     else map.set(ch, 1);
    // }

    // function get(map, ch) {
    //     return map.has(ch) ? map.get(ch) : 0;
    // }
};


/**
76. Minimum Window Substring
Hard

Given two strings s and t of lengths m and n respectively, return the minimum window

of s such that every character in t (including duplicates) is included in the window. If there is no 
such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

 

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
 */
