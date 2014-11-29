/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
// This works.
class Solution {
public:
    /**
     * @param root: The root of the binary search tree.
     * @param node: insert this node into the binary search tree
     * @return: The root of the new binary search tree.
     */
    TreeNode* insertNode(TreeNode* root, TreeNode* node) {
        // write your code here
        if (! root) return node;
        
        if (root->val == node->val) return root;
        else if (root->val > node->val) root->left = insertNode(root->left, node);
        else root->right = insertNode(root->right, node);
    }
};


/**
Insert Node in a Binary Search Tree 

Given a binary search tree  and a new tree node, insert the node into the tree. You should keep the tree still be a valid binary search tree.

E.g.,
Given binary search tree as follow:

     2

  /    \

1        4

         /   

       3 

after Insert node 6, the tree should be:

     2

  /    \

1        4

         /   \ 

       3        6
       
Challenge: Do it withough recursion.
 */
