// Group Elements by the Sum of Row and Column Indices
// From: https://leetcode.com/problems/diagonal-traverse-ii/editorial/
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        map<int, vector<int>> groups;
        for (int row = nums.size() - 1; row >= 0; row--) {
            for (int col = 0; col < nums[row].size(); col++) {
                int diagonal = row + col;
                groups[diagonal].push_back(nums[row][col]);
            }
        }
        
        vector<int> ans;
        int curr = 0;
        
        while (groups.contains(curr)) {
            for (int num : groups[curr]) {
                ans.push_back(num);
            }
            curr++;
        }
        
        return ans;
    }
};



// BFS
// From: https://leetcode.com/problems/diagonal-traverse-ii/editorial/
// Time complexity: O(n)
// Space complexity: O(sqrt(n))
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        queue<pair<int, int>> queue;
        queue.push({0, 0});
        vector<int> ans;
        
        while (!queue.empty()) {
            auto [row, col] = queue.front();
            queue.pop();
            ans.push_back(nums[row][col]);
            
            if (col == 0 && row + 1 < nums.size()) {
                queue.push({row + 1, col});
            }
            
            if (col + 1 < nums[row].size()) {
                queue.push({row, col + 1});
            }
        }
        
        return ans;
    }
};


/**
1424. Diagonal Traverse II
Medium

Given a 2D integer array nums, return all elements of nums in diagonal order as shown in the below images.

 

Example 1:

Input: nums = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,4,2,7,5,3,8,6,9]
 */
