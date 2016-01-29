/**
 * Find the next successor of a node in a BST. 
 * From: Cracking the Coding Interview, 5th Ed. Q4.6, page 229.
 * Note this require a parent pointer on each node.
 */
 
TreeNode * inorderSucc(TreeNode * n) {
    if (NULL == n) return NULL;
    
    if (n->right != NULL) {
        return leftMostChild(n->right);
    }
    else {
        TreeNode * q = n;
        TreeNode x = q->parent;
        // Go up until we are on left instead of right.
        while (x != NULL && x->left != q) {
            q = x;
            x = x->parent;
        }
        return x;
    }
}

TreeNode * leftMostChild(TreeNode * n) {
    if (n == NULL) return NULL;
    
    while (n->left != NULL) {
        n = n->left;
    }
    return n;
}
