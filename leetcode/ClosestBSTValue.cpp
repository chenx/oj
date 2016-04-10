// Should work. Tested locally, not in lc. O(n).
class Solution3 {
public:
    int closestValue(TreeNode* root, double target) {
        if (! root) return 0;
        
        double minDist = abs(root->val - target) + 1; // note this initialization!
        int val = 0;
        getVal(root, target, minDist, val);
        return val;
    }     
    
    void getVal(TreeNode * root, double target, double &minDist, int &val) {
        if (! root) return;
        
        double dist = abs(root->val - target);
        if (dist < minDist) {
            minDist = dist;
            val = root->val;
        }
        
        getVal(root->left, target, minDist, val);
        getVal(root->right, target, minDist, val);
    }
};


// Should work. Not tested. O(n).
class Solution2 {
public:
    int closestValue(TreeNode* root, double target) {
        if (root == NULL) return 0;
        
        vector<int> v = postorderTraversal(root);
        
        double mdiff = abs(v[0] - target), val = v[0];
        for (int i = 1; i < v.size(); ++ i) {
            double diff = abs(v[i] - target);
            if (diff < mdiff) {
                mdiff = diff;
                val = v[i];
            }
        }
        
        return val;
    }
};

// Works. Tested. O(n).
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
