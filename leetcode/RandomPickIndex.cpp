class Solution {
   unordered_map<int, vector<int>> m;
public:
   Solution(vector<int>& nums) {
       for (int i = 0, n = nums.size(); i < n; i ++) {
           m[nums[i]].push_back(i);
       }
   }
  
   int pick(int target) {
       int ct = m[target].size();
       if (ct == 0) return -1;
       return m[target][random(0, ct-1)];
   }

   int random(int minVal, int maxVal) {
       return minVal + rand() % (maxVal - minVal + 1);
   }
};

/**
* Your Solution object will be instantiated and called as such:
* Solution* obj = new Solution(nums);
* int param_1 = obj->pick(target);
*/

/**
Given an integer array nums with possible duplicates, randomly output the index of a given target number.
You can assume that the given target number must exist in the array.

Implement the Solution class:

    Solution(int[] nums) Initializes the object with the array nums.
    int pick(int target) Picks a random index i from nums where nums[i] == target. If there are multiple
    valid i's, then each index should have an equal probability of returning.

Example 1:

Input
["Solution", "pick", "pick", "pick"]
[[[1, 2, 3, 3, 3]], [3], [1], [3]]
Output
[null, 4, 0, 2]

Explanation
Solution solution = new Solution([1, 2, 3, 3, 3]);
solution.pick(3); // It should return either index 2, 3, or 4 randomly. 
                  // Each index should have equal probability of returning.
solution.pick(1); // It should return 0. Since in the array only nums[0] is equal to 1.
solution.pick(3); // It should return either index 2, 3, or 4 randomly.
                  // Each index should have equal probability of returning.
 */
