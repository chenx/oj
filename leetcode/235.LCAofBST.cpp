/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Iterative version of Solution3. Works too.
// See: https://leetcode.com/discuss/44959/3-lines-with-o-1-space-1-liners-alternatives
class Solution5 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (! root) return NULL;
        while ((root->val - p->val) * (root->val - q->val) > 0) 
            root = (root->val > p->val) ? root->left : root->right;
        return root;
    }
};

// Works too. Treat BST as a BT. More general. 
class Solution4 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return NULL;
        if (root == p || root == q) return root;
        TreeNode * L = lowestCommonAncestor(root->left, p, q);
        TreeNode * R = lowestCommonAncestor(root->right, p, q);
        if (L && R) return root;
        return L ? L : R;
    }
}; 
 
// Works too. Basically same as Solution2.
class Solution3 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root->val < p->val && root->val < q->val) return lowestCommonAncestor(root->right, p, q);
        if (root->val > p->val && root->val > q->val) return lowestCommonAncestor(root->left, p, q);
        return root;
    }
};

// This works too. Assume root, p, q all not null.
class Solution2 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p->val > q->val) return lowestCommonAncestor(root, q, p);
        
        if (root->val < p->val) return lowestCommonAncestor(root->right, p, q);
        if (root->val > q->val) return lowestCommonAncestor(root->left, p, q);
        return root;
    }
};


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (! root) return NULL;
        if (p->val > q->val) return lowestCommonAncestor(root, q, p);
        if (root->val >= p->val && root->val <= q->val) return root;
        else if (root->val >= p->val && root->val >= q->val) return lowestCommonAncestor(root->left, p, q);
        else return lowestCommonAncestor(root->right, p, q);
    }
};


/**
Lowest Common Ancestor of a Binary Search Tree
Total Accepted: 34434 Total Submissions: 90966 Difficulty: Easy

Given a binary search tree (BST), find the lowest common ancestor (LCA) 
of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor 
is defined between two nodes v and w as the lowest node in T that has both 
v and w as descendants (where we allow a node to be a descendant of itself).”

        _______6______
       /              \
    ___2__          ___8__
   /      \        /      \
   0      _4       7       9
         /  \
         3   5

For example, the lowest common ancestor (LCA) of nodes 2 and 8 is 6. 
Another example is LCA of nodes 2 and 4 is 2, since a node can be a 
descendant of itself according to the LCA definition.
 */
