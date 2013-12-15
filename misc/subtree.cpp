//
// You have two very large binary trees: T1, with millions of nodes, 
// and T2 with hundreds of nodes. Create an algorithm to decide if T2 
// is a subtree of T1.
//
// @By: wang ya.
// @Created on: 3/9/2013
//

bool subTree(TreeNode* t1, TreeNode* t2) {
    if (!t2) return true;
    if (!t1) return false;

    if(t1->val == t2->val) {
        if(matchTree(t1,t2)) return true;
    }

    return subTree(t1->left,t2) || subtree(t1->right,t2);
}

bool matchTree(TreeNode* t1, TreeNode* t2) {
    if(!t1 && !t2) return true;
    if(!t1 || !t2) return false;
    if(t1->val != t2->val) return false;
    return matchTree(t1->left,t2->left) && 
           matchTree(t1->right,t2->right);
}

