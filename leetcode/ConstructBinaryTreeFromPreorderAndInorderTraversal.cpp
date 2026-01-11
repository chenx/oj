//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 12/18/2012
// @Last modified: 12/18/2012
//

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 
 
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Works. Use a map to get index in inorder traversal.
class Solution3 {
    unordered_map<int, int> inorderIndexMap;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); ++ i) inorderIndexMap[inorder[i]] = i;
        return build(preorder, inorder, 0, 0, inorder.size() - 1);
    }

    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int ip, int il, int ir) {
        if (il > ir) return NULL;

        TreeNode* root = new TreeNode(preorder[ip]);
        int mid = inorderIndexMap[preorder[ip]];
        root->left = build(preorder, inorder, ip + 1, il, mid - 1);
        root->right = build(preorder, inorder, ip + (mid - il) + 1, mid + 1, ir);
        return root;
    }
};
  
// This works too.
// Note that this is BT, not BST, so no binary search.
// Also note that for preorder vector, only need to pass its root value,
// but for inorder vector, needs to pass both il and ir.
class Solution2 {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int len = preorder.size();
        return build(preorder, inorder, 0, 0, len - 1);
    }
    
    TreeNode * build(vector<int> &preorder, vector<int> &inorder, int pi, int il, int ir) {
        if (il > ir) return NULL;
        
        TreeNode * r = new TreeNode(preorder[pi]);
        
        int m = find(inorder, il, ir, preorder[pi]); 
        
        r->left = build(preorder, inorder, pi+1, il, m-1);
        r->right = build(preorder, inorder, pi+(m-il)+1, m+1, ir);
        
        return r;
    }
    
    int find(vector<int> &inorder, int left, int right, int v) {
        for (int i = left; i <= right; ++ i) {
            if (inorder[i] == v) return i;
        }
        
        return -1;
    }
};


// This works.
class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        TreeNode * r = NULL;
        bT(&r, preorder, 0, inorder, 0, inorder.size() - 1);
        return r;
    }
    
    // pi: index of current root node.
    // [il, ir]: range of current root's children in the inorder list.
    void bT(TreeNode ** n, vector<int> &preorder, int pi, vector<int> &inorder, int il, int ir) {
        if (il > ir || pi >= preorder.size() || pi < 0) {
            *n = NULL;
            return;
        }
        *n = new TreeNode(preorder[pi]);
        if (il == ir) return;
        
        int ni = find(preorder[pi], inorder, il, ir);
        // pi + 1: left child position.
        bT(& ((*n)->left), preorder, pi + 1, inorder, il, ni - 1);
        // important: length of left wing: x = (ni - 1) - il + 1 = ni - il,
        // so right child position: pi + 1 + x, 1 for left child.
        bT(& ((*n)->right), preorder, pi + ni - il + 1, inorder, ni + 1, ir);
    }
    
    // return index of n in v.
    int find(int n, vector<int> v, int left, int right) {
        for (int i = left; i <= right; i ++) {
            if (n == v[i]) return i;
        }
        return -1;
    }
};

void pre(TreeNode *n) {
    if (n == NULL) return;
    printf("%d ", n->val);
    pre(n->left);
    pre(n->right);
}
void in(TreeNode *n) {
    if (n == NULL) return;
    in(n->left);
    printf("%d ", n->val);
    in(n->right);
}

vector<int> makeVec(int a[], int len) {
    vector<int> v;
    for (int i = 0; i < len; i ++) {
        v.push_back(a[i]);
    }
    return v;
}

int main() {
    int a[] = {4,1,2,3};
    int lena = sizeof(a) / sizeof(int);
    vector<int> p = makeVec(a, lena);
    
    int b[] = {1,2,3,4};
    int lenb = sizeof(b) / sizeof(int);
    vector<int> i = makeVec(b, lenb);
    
    Solution s;
    TreeNode * r = s.buildTree(p, i);
    
    puts("");
    pre(r); puts("");
    in(r); puts("");
    
    return 0;
}

