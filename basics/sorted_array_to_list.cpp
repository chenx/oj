// Convert Sorted Array to Binary Search Tree
class Solution {
public:
   TreeNode* sortedArrayToBST(vector<int>& nums) {
       return helper(nums, 0, nums.size() - 1);
   }

   TreeNode* helper(vector<int>& nums, int L, int R) {
       if (L > R) return NULL;

       int M = (L + R) / 2;
       TreeNode* root = new TreeNode(nums[M]);
       root->left = helper(nums, L, M-1);
       root->right = helper(nums, M+1, R);
       return root;
   }
};
