/**
 * @param {string} s
 * @return {number}
 */
var longestValidParentheses2 = function(s) {
    let openCount = 0, total = 0, maxLen = 0;

    const getMaxLen = (isOpenChar) => {
            if (isOpenChar) {
                ++ openCount;
                ++ total;
            } else {
                -- openCount;
                ++ total;
            }

            if (openCount == 0) {
                maxLen = Math.max(maxLen, total);
            } else if (openCount < 0) {
                openCount = 0;
                total = 0;
            }
    }

    for (let i = 0; i < s.length; ++ i) {
        getMaxLen(s.charAt(i) === '(');
    }

    openCount = total = 0;
    for (let i = s.length - 1; i >= 0; -- i) {
        getMaxLen(s.charAt(i) === ')');
    }
    return maxLen;
};


/**
 * @param {string} s
 * @return {number}
 */
var longestValidParentheses = function(s) {
    let openCount = 0, total = 0, maxLen = 0;

    for (let i = 0; i < s.length; ++ i) {
        getMaxLen(s.charAt(i) === '(');
    }

    openCount = total = 0;
    for (let i = s.length - 1; i >= 0; -- i) {
        getMaxLen(s.charAt(i) === ')');
    }
    return maxLen;
    
    function getMaxLen(isOpenChar) {
            if (isOpenChar) {
                ++ openCount;
                ++ total;
            } else {
                -- openCount;
                ++ total;
            }

            if (openCount == 0) {
                maxLen = Math.max(maxLen, total);
            } else if (openCount < 0) {
                openCount = 0;
                total = 0;
            }
    }
};


/**
32. Longest Valid Parentheses
Hard

Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses.

 

Example 1:

Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".

Example 2:

Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".

Example 3:

Input: s = ""
Output: 0
 */
