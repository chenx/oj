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

/**
To optimize finding the k-th smallest element in a frequently modified BST, the most efficient approach
involves augmenting the BST nodes with additional information.

Augmented BST with Node Counts:
    Node Augmentation:
    Modify each node in the BST to store an additional field, typically count or size, representing the
    total number of nodes in its subtree (including itself).

Maintaining Counts during Operations:

    Insert: When inserting a new node, traverse the tree as usual. For every node encountered on the
    path from the root to the insertion point, increment its count field.

Delete: When deleting a node, traverse the tree to find the node. After performing the deletion 
(and any necessary rebalancing, if it's a self-balancing BST like an AVL tree or Red-Black Tree), 
decrement the count field of all nodes on the path from the root to the deleted node's effective position.

Finding the k-th Smallest:
    Start at the root.
 
    At each node, compare k with the count of its left child's subtree (let's call it left_subtree_size).
    - If k <= left_subtree_size, the k-th smallest element is in the left subtree. 
      Recurse on the left child with the same k. 
    - If k == left_subtree_size + 1, the current node is the k-th smallest element.
    - If k > left_subtree_size + 1, the k-th smallest element is in the right subtree. 
      Recurse on the right child with k - (left_subtree_size + 1). 

This approach allows finding the k-th smallest element in O(log n) time (for balanced BSTs), as the 
search path is guided by the subtree counts, similar to a binary search. Insert and delete operations
also remain O(log n) as only the nodes along the path to the inserted/deleted node need their counts updated.
 */
