// Time complexity: O(n+k)
// Space complexity: O(k)
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var subarraysDivByK = function(nums, k) {
    let prefixMod = 0, result = 0;
    const modGroups = Array(k).fill(0);
    modGroups[0] = 1;

    nums.forEach(num => {
        prefixMod = (prefixMod + num % k + k) % k;
        // for num, there are modGroups[prefixMod] subarrays where sum / k = 0
        result += modGroups[prefixMod];
        modGroups[prefixMod] ++;
    });

    return result;
};
