// Works. Tested.
class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        if (root == NULL) return 0;
        
        double mdist = abs(target - root->val), dist;
        int val = root->val;
        stack<TreeNode *> s;
        s.push(root);
        
        while (! s.empty()) {
            TreeNode * n = s.top();
            s.pop();
            
            dist = abs(target - n->val);
            if (mdist > dist) {
                mdist = dist;
                val = n->val;
            }
            
            if (n->right != NULL) s.push(n->right);
            if (n->left != NULL) s.push(n->left);
        }
        
        return val;
    }
};

/**
Closest Binary Search Tree Value My Submissions Question
Difficulty: Easy

Given a non-empty binary search tree and a target value, 
find the value in the BST that is closest to the target.

Note:
Given target value is a floating point.
You are guaranteed to have only one unique value in the 
BST that is closest to the target.
 */
