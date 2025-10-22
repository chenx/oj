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
        result += modGroups[prefixMod];
        modGroups[prefixMod] ++;
    });

    return result;
};
