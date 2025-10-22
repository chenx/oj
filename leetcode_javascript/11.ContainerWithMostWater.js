/**
 * @param {number[]} height
 * @return {number}
 */
var maxArea = function(height) {
    let n = height.length, L = 0, R = n - 1, maxWater = 0;

    while (L < R) {
        const ht = Math.min(height[L], height[R]);
        const water = ht * (R - L);
        maxWater = Math.max(maxWater, water);
        
        if (height[L] < height[R]) ++ L;
        else -- R;
    }
    return maxWater;
};
