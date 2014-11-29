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
 * Example of iterate a tree:
 * Solution iterator = Solution(root);
 * while (iterator.hasNext()) {
 *    TreeNode * node = iterator.next();
 *    do something for node
 */
//
// This works. Passed test cases.
// However, this uses O(n) space, n is size of tree.
// Best method would be Morris algorithm, which is O(1).
//
class Solution {
    vector<TreeNode *> v;
    void inorder(TreeNode * n) {
        if (! n) return;
        inorder(n->left);
        v.push_back(n);
        inorder(n->right);
    }
public:
    //@param root: The root of binary tree.
    Solution(TreeNode *root) {
        // write your code here
        inorder(root);
    }

    //@return: True if there has next node, or false
    bool hasNext() {
        // write your code here
        return v.size() > 0;
    }
    
    //@return: return next node
    TreeNode* next() {
        // write your code here
        TreeNode * head = v[0];
        v.erase(v.begin());
        return head;
    }
};


/**
Implement Iterator of Binary Search Tree 

Design an iterator over a binary search tree with the following properties:
Elements are visited in ascending order (i.e. an inorder traversal)
next() and hasNext() queries run in O(1) time in average.

E.g.,
For the following binary search tree, inorder traversal by using iterator is [1, 6, 10, 11, 12]

      10

    /     \

 1          11

    \           \

       6           12
   
Challenge:
Extra memory usage O(h), h is the height of the tree.
Super Star: Extra memory usage O(1)
 */
