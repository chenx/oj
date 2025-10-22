/**
 * @param {number[][]} intervals
 * @return {number[][]}
 */
var merge = function(intervals) {
    const ans = [];

    // This also works: intervals.sort((a, b) => a[0] - b[0]);
    intervals.sort((a, b) => { return a[0] - b[0]; });

    const n = intervals.length;
    for (let i = 1; i < n; ++ i) {
        const a = intervals[i-1], b = intervals[i];
        if (a[1] < b[0]) {
            ans.push(a);
        } else if (a[1] <= b[1]) {
            b[0] = a[0];
        } else {
            b[0] = a[0], b[1] = a[1];
        }
    }
    ans.push(intervals[n-1]);

    return ans;
};

/**
--- 
    --

----
  --

----
 -
 */
