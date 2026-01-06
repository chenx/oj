
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (! root) return NULL;

        if (root->val == key) {
            if (! root->left && ! root->right) {
                return NULL;
            } else if (! root->left) {
                return root->right;
            } else if (! root->right) {
                return root->left;
            } else {
                // get smallest element on RHS.
                TreeNode* node = root->right;
                while (node->left) node = node->left;
                root->val = node->val;
                root->right = deleteNode(root->right, node->val);
                return root;
            }
        } else {
            if (key < root->val) root->left = deleteNode(root->left, key);
            else root->right = deleteNode(root->right, key);
            return root;
        }
    }
};

/**
Steps to Delete a Node in a Binary Search Tree (BST)
    Search for the Node: Traverse the BST to locate the node with the given key. 
    If the key is smaller than the current node's value, move to the left subtree. 
    If the key is larger, move to the right subtree.

    Handle Case 1: Node is a Leaf (No Children): 
    If the node has no children, simply remove it from the tree by setting its parent's reference to null.

    Handle Case 2: Node has One Child: 
    Replace the node with its only child (left or right). Update the parent node's reference to point to the child.

    Handle Case 3: Node has Two Children: 
    Find the inorder successor (smallest node in the right subtree) or inorder predecessor (largest node in the left subtree). 
    Copy the value of the successor/predecessor to the node to be deleted. Recursively delete the successor/predecessor node, 
    which will now fall into one of the simpler cases (leaf or single child).

    Update the Tree: Ensure the BST properties are maintained after deletion. 
    Return the updated root node of the tree. 
 */

/**
450. Delete Node in a BST
Medium

Given a root node reference of a BST and a key, delete the node with the given key in the BST. 
Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

    Search for a node to remove.
    If the node is found, delete the node.
 */
