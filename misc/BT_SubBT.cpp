/**
 * Given a large binary tree t1 and a small binary tree t2, find if t2 is a subtree of t1.
 *
 * CC150 4.8. Page 235.
 * Method 1: compare if the preorder and inorder traveral representations of the 2 trees are the same.
 * (note NULL node needs to be represented by a special marker).
 * Method 2: compare each node value of t1 to t2's root; if equal, compare the rest nodes of t2 from that node of t1.
 * 
 * On: 3/2/2015
 */

// This works. From CC150 4.8. Page 236.
bool containsTree(TreeNode * t1, TreeNode * t2) {
    if (! t2) return true;
    return subtree(t1, t2);
}

bool subtree(TreeNode * t1, TreeNode * t2) {
    if (! t1) return false;
    if (t1->val == t2->val && isSameTree(t1, t2)) return true;
    return subtree(t1->left, t2) || subtree(t1->right, t2);
}

bool isSameTree(TreeNode * t1, TreeNode * t2) {
    if (! t1 && ! t2) return true;
    if (! t1 || ! t2) return false;
    return t1->val == t2->val && isSameTree(t1->left, t2->left) && isSameTree(t1->right, t2->right);
}
