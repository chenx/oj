//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 12/18/2012
// @Last modified: 1/13/2013
//

class Solution3 {
    unordered_map<int, int> inorderIndexMap;
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        for (int i = 0; i < n; ++ i) inorderIndexMap[inorder[i]] = i;
        return build(inorder, postorder, n-1, 0, n-1);
    }

    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int ip, int il, int ir) {
        if (il > ir) return NULL;

        TreeNode* root = new TreeNode(postorder[ip]);
        int mi = inorderIndexMap[postorder[ip]];

        root->left = build(inorder, postorder, ip - (ir - mi) - 1, il, mi - 1);
        root->right = build(inorder, postorder, ip-1, mi + 1, ir);
        return root;
    }
};


// This works too.
class Solution2 {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        int len = inorder.size();
        return build(inorder, postorder, len - 1, 0, len - 1);
    }
    
    TreeNode * build(vector<int> &inorder, vector<int> &postorder, int pi, int il, int ir) {
        if (il > ir) return NULL;

        TreeNode * r = new TreeNode(postorder[pi]);

        int m = find(inorder, il, ir, postorder[pi]);

        r->left = build(inorder, postorder, pi - (ir - m) - 1, il, m - 1);
        r->right = build(inorder, postorder, pi - 1, m + 1, ir);

        return r;
    }

    int find(vector<int> &inorder, int left, int right, int v) {
        for (int i = right; i >= left; -- i) {
            if (inorder[i] == v) return i;
        }

        return -1;
    }
};


// For complex input, this has "Memory limit exceeded" error. ?
class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        TreeNode * r;
        bT(&r, postorder, postorder.size() - 1, inorder, 0, inorder.size() - 1);
        return r;
    }
    
    void bT(TreeNode ** n, vector<int> postorder, int pi, vector<int> &inorder, int il, int ir) {
        if (il > ir || pi >= postorder.size() || pi < 0) {
            *n = NULL;
            return;
        }
        *n = new TreeNode(postorder[pi]);
        if (il == ir) return;
        
        int ni = find(postorder[pi], inorder, il, ir);
        // pi - 1: right child position.
        bT(& ((*n)->right), postorder, pi - 1, inorder, ni + 1, ir);
        // length of right wing: x = ir - (ni + 1) + 1 = ir - ni,
        // so left child position: pi - 1 - x.
        bT(& ((*n)->left), postorder, pi - ir + ni - 1, inorder, il, ni - 1);
    }
    
    // return index of n in v.
    int find(int n, vector<int> v, int left, int right) {
        for (int i = left; i <= right; i ++) {
            if (n == v[i]) return i;
        }
        return -1;
    }

};
