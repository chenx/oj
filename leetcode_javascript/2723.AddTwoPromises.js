/**
 * @param {Promise} promise1
 * @param {Promise} promise2
 * @return {Promise}
 */

// See: https://leetcode.com/problems/add-two-promises/editorial/
// Time complexity: O(max(promise1,promise2))
// Space complexity: O(1)
//
var addTwoPromises2 = async function(promise1, promise2) {
    try {
        const [p1, p2] = await Promise.all([promise1, promise2]);
        return p1 + p2;
    } catch (error) {
        throw error;
    }
};


// See: https://leetcode.com/problems/add-two-promises/editorial/
// Time complexity: O(max(promise1,promise2))
// Space complexity: O(1)
//
var addTwoPromises = async function(promise1, promise2) {
    try {
        let p1 = await promise1;
        let p2 = await promise2;
        return p1 + p2;
    } catch (error) {
        throw error;
    }
};

/**
 * addTwoPromises(Promise.resolve(2), Promise.resolve(2))
 *   .then(console.log); // 4
 */


/**
2723. Add Two Promises
Solved

Given two promises promise1 and promise2, return a new promise. promise1 and promise2 will both resolve 
with a number. The returned promise should resolve with the sum of the two numbers.

 

Example 1:

Input: 
promise1 = new Promise(resolve => setTimeout(() => resolve(2), 20)), 
promise2 = new Promise(resolve => setTimeout(() => resolve(5), 60))
Output: 7
Explanation: The two input promises resolve with the values of 2 and 5 respectively. The returned promise 
should resolve with a value of 2 + 5 = 7. The time the returned promise resolves is not judged for this problem.
 */
