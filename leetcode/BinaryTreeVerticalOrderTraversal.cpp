// Works. Tested. 
// The key is to use level_order traversal.
class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL) return ans;
        
        unordered_map<int, vector<int>> m;
        int level = 0, minLevel = INT_MAX, maxLevel = INT_MIN;
        
        queue<pair<int, TreeNode *>> q;
        q.push(pair<int, TreeNode *>(0, root));

        while (! q.empty()) {
            int ct = q.size();
            while (ct > 0) {
                TreeNode * n = q.front().second;
                level = q.front().first;
                q.pop();
                -- ct;
                
                minLevel = min(level, minLevel);
                maxLevel = max(level, maxLevel);
                m[level].push_back(n->val);
                
                if (n->left != NULL) {
                    q.push(pair<int, TreeNode *>(level - 1, n->left));
                }
                if (n->right != NULL) {
                    q.push(pair<int, TreeNode *>(level + 1, n->right));
                }
            }
        }
        
        for (int i = minLevel; i <= maxLevel; ++ i) {
            ans.push_back(m[i]);
        }
        
        return ans;
    }
};    
    
    // Code below use preorder and inorder traversals.
    // Although it outputs correctly on the first level,
    // it cannot guarantee the order in each 2nd level vector.
/*
        stack<pair<int, TreeNode *>> s;
        s.push(pair<int, TreeNode *>(level, root));
        
        while (! s.empty()) {
            TreeNode * n = s.top().second;
            level = s.top().first;
            s.pop();
            
            minLevel = min(level, minLevel);
            maxLevel = max(level, maxLevel);
            m[level].push_back(n->val);

            if (n->right != NULL) {
                s.push(pair<int, TreeNode *>(level + 1, n->right));
            }
            if (n->left != NULL) {
                s.push(pair<int, TreeNode *>(level - 1, n->left));
            }
        }
        
        for (int i = minLevel; i <= maxLevel; ++ i) {
            ans.push_back(m[i]);
        }
        
        return ans;
*/
/*        stack<pair<int, TreeNode *>> s;
        TreeNode * n = root;

        while (true) {
            while (n != NULL) {
                s.push(pair<int, TreeNode *>(level --, n));
                n = n->left;
            }
            
            if (s.empty()) {
                break;
            }
            else {
                n = s.top().second;
                level = s.top().first;
                s.pop();
                
                minLevel = min(level, minLevel);
                maxLevel = max(level, maxLevel);
                m[level].push_back(n->val);
                
                n = n->right;
                ++ level;
            }
        }
        
        for (int i = minLevel; i <= maxLevel; ++ i) {
            ans.push_back(m[i]);
        }
        
        return ans;
*/



/**
Binary Tree Vertical Order Traversal
Difficulty: Medium
Given a binary tree, return the vertical order traversal of 
its nodes' values. (ie, from top to bottom, column by column).

If two nodes are in the same row and column, the order should be from left to right.

Examples:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its vertical order traversal as:
[
  [9],
  [3,15],
  [20],
  [7]
]
Given binary tree [3,9,20,4,5,2,7],
    _3_
   /   \
  9    20
 / \   / \
4   5 2   7
return its vertical order traversal as:
[
  [4],
  [9],
  [3,5,2],
  [20],
  [7]
]
 */
