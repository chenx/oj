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
 * BSTIterator iterator = BSTIterator(root);
 * while (iterator.hasNext()) {
 *    TreeNode * node = iterator.next();
 *    do something for node
 */
class BSTIterator {
    stack<TreeNode *> s;
    TreeNode * nextNode, * n;
    
    void getNext() {
        while (n != NULL) {
            s.push(n);
            n = n->left;
        }
        
        if (s.empty()) {
            nextNode = NULL;
        }
        else {
            nextNode = n = s.top();
            s.pop();
            n = n->right;
        }
    }
public:
    //@param root: The root of binary tree.
    BSTIterator(TreeNode *root) {
        n = root;
        getNext();
    }

    //@return: True if there has next node, or false
    bool hasNext() {
        return nextNode != NULL;
    }
    
    //@return: return next node
    TreeNode* next() {
        TreeNode * next = nextNode;
        getNext();
        return next;
    }
};
