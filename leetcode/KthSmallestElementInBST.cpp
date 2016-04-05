/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 
// Works. Use iterative inorder traversal to find kth element. 2/4/2016.
// O(h) space, O(k) time.
class Solution5 {
public:
    int kthSmallest(TreeNode* root, int k) {
        if (root == NULL) return -1;
        
        stack<TreeNode *> s;
        TreeNode *n = root;
        int ct = 0;
        
        while (true) {
            while (n != NULL) {
                s.push(n);
                n = n->left;
            }
            
            if (s.empty()) break;
            else {
                n = s.top();
                s.pop();
                
                if (++ ct == k) return n->val;
                // or: if (-- k == 0) return n->val; // this does not need ct.
                
                n = n->right;
            }
        }
        
        return -1;
    }
};


// Works. Best recursive answer.
// Need to be sure the answer exists, otherwise will return 0/-1.
class Solution4 {
public:
    int kthSmallest(TreeNode* root, int k) {
        return getKth(root, k);
    }
    
    int getKth(TreeNode * root, int &k) {
        if (! root) return 0; // or -1, does not matter.
        
        int n = getKth(root->left, k);
        if (k == 0) return n;
        
        if (-- k == 0) return root->val;
        else return getKth(root->right, k);
    }
};

 
// This works too, and should be more efficient.
class Solution3 {
public:
    int kthSmallest(TreeNode* root, int k) {
        int ct = 0;
        TreeNode * n = getKth(root, ct, k);
        return n ? n->val : -1;
    }
    
    TreeNode * getKth(TreeNode * root, int & ct, int k) {
        if (! root) return NULL;
        
        TreeNode * L = getKth(root->left, ct, k);
        if (L != NULL) return L;
        
        ++ ct;
        if (ct == k) {
            return root;
        }
        
        return getKth(root->right, ct, k); 
    }
};

// Works. Compared to Solution, this saves "ct".
class Solution2 {
public:
    int kthSmallest(TreeNode* root, int k) {
        int val = 0;
        getKth(root, k, val);
        return val;
    }
    
    void getKth(TreeNode * root, int &k, int &val) {
        if (! root) return;
        
        getKth(root->left, k, val);
        if (k == 0) return;
        
        if (-- k == 0) {
            val = root->val;
            return;
        }
        getKth(root->right, k, val);
    }
};

// This works.
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int ct = 0, val = -1;
        getKth(root, ct, k, val);
        return val;
    }
    
    void getKth(TreeNode * root, int & ct, int k, int & val) {
        if (! root) return;
        
        getKth(root->left, ct, k, val);
        ++ ct;
        if (ct == k) { val = root->val; }
        else if (ct < k) { getKth(root->right, ct, k, val); }
    }
};


/*
Kth Smallest Element in a BST 

Given a binary search tree, write a function kthSmallest to 
find the kth smallest element in it.

Note:
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Follow up:
What if the BST is modified (insert/delete operations) often 
and you need to find the kth smallest frequently? 
How would you optimize the kthSmallest routine? (how?)

Hint:

    Try to utilize the property of a BST.
    What if you could modify the BST node's structure? (store lessThan count in node).
    The optimal runtime complexity is O(height of BST).

 */
