/**
 * Find the inorder successor of given node is a BST.
 * Note solution to this can be used in BST2Sum.cpp. InorderPrev is symmetric.
 * A pointer from child to parent is needed for this problem.
 *
 * On: 3/2/2015
 */

// This works. From: CC150 4.6. P.g. 229.
TreeNode * inorderSucc(TreeNode * n) {
    if (! n) return NULL;
    
    // if right child exists, return leftmost node of right subtree.
    if (n->right) {
        return leftMostChild(n->right);
    }
    else {
        // Go up until we are on left instead of right (node q is parent x's left child).
        TreeNode * q = n;
        TreeNode * x = q->parent;
        while (x && q == x->right) {
            q = x;
            x = x->parent;
        }
        return x;
    }
}

TreeNode * leftMostChild(TreeNode * n) {
    if (! n) return NULL;
    while (n->left) n = n->left;
    return n;
}
