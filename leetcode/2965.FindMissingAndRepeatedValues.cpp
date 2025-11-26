// From: https://leetcode.com/problems/find-missing-and-repeated-values/editorial/
// Use math.
// perfectSum = n^2⋅(n^2+1)​​ / 2, perfectSqrSum = n2⋅(n2+1)⋅(2n2+1)​​ / 6
// sumDiff = x−y​, sqrDiff = x^2−y^2​
// x = sqrDiff/sumDiff+sumDiff​​ / 2, y = sqrDiff/sumDiff−sumDiff​​ / 2
// Time: O(n^2)
// Space: O(n^2)
class Solution2 {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        long long sum = 0, sqrSum = 0;
        long long n = grid.size();
        long long total = n * n;

        // Calculate actual sum and squared sum from grid
        for (int row = 0; row < n; ++row) {
            for (int col = 0; col < n; ++col) {
                sum += grid[row][col];
                sqrSum +=
                    static_cast<long long>(grid[row][col]) * grid[row][col];
            }
        }

        // Calculate differences from expected sums
        // Expected sum: n(n+1)/2, Expected square sum: n(n+1)(2n+1)/6
        long long sumDiff = sum - total * (total + 1) / 2;
        long long sqrDiff = sqrSum - total * (total + 1) * (2 * total + 1) / 6;

        // Using math: If x is repeated and y is missing
        // sumDiff = x - y
        // sqrDiff = x² - y²
        int repeat = (sqrDiff / sumDiff + sumDiff) / 2;
        int missing = (sqrDiff / sumDiff - sumDiff) / 2;

        return {repeat, missing};
    }
};


// From: https://leetcode.com/problems/find-missing-and-repeated-values/editorial/
// Use map.
// Time: O(n^2)
// Space: O(n^2)
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int missing = -1, repeat = -1;

        // Store frequency of each number in the grid
        unordered_map<int, int> freq;
        for (auto& row : grid) {
            for (int num : row) {
                freq[num]++;
            }
        }

        // Check numbers from 1 to n^2 to find missing and repeated values
        for (int num = 1; num <= n * n; num++) {
            if (!freq.count(num)) {
                missing = num;  // Number not present in grid
            } else if (freq[num] == 2) {
                repeat = num;  // Number appears twice
            }
        }

        return {repeat, missing};
    }
};


/**
2965. Find Missing and Repeated Values
Easy

You are given a 0-indexed 2D integer matrix grid of size n * n with values in the range [1, n2]. 
Each integer appears exactly once except a which appears twice and b which is missing. The task 
is to find the repeating and missing numbers a and b.

Return a 0-indexed integer array ans of size 2 where ans[0] equals to a and ans[1] equals to b.

 

Example 1:

Input: grid = [[1,3],[2,2]]
Output: [2,4]
Explanation: Number 2 is repeated and number 4 is missing so the answer is [2,4].

Example 2:

Input: grid = [[9,1,7],[8,9,2],[3,4,6]]
Output: [9,5]
Explanation: Number 9 is repeated and number 5 is missing so the answer is [9,5].
 */
