/**
 * @param {number[]} temperatures
 * @return {number[]}
 */
var dailyTemperatures = function(temperatures) {
    const n = temperatures.length;
    const ans = new Array(n).fill(0);
    let hottest = 0;

    for (let i = n-1; i >= 0; -- i) {
        const t = temperatures[i];
        if (t >= hottest) {
            hottest = t;  // ans[i] = 0
            continue;
        }

        let day = 1;
        while ( temperatures[i + day] <= t ) {
            day += ans[i + day];
        }
        ans[i] = day;
    }
    return ans;
};
