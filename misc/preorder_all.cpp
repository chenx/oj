//
// Given preorder traversal of a binary tree, give all possible trees 
// (output in inorder).
//
// Idea: 1 2 3 4 ... 
// 1 is root, for 2, 3, ..., n, the first 0, 1, ..., n-1 can be on left child,
// rest on right child. Do child recursively.
//
// For 1 element, answer contains 1 tree.
// For 2 element, answer contains 2 tree.
// For 3 element, answer contains 5 tree.
// For 4 element, answer contains 14 tree.
//
// This is not that difficult algorithm wise.
// Similarly, given inorder traversal of a binary tree, we can choose any
// element to be the middle node, then recursively add left and right children.
// Postorder is similar too.
//
// @Author: Xin Chen
// @Created on: 3/22/2013
// @Last modified: 3/22/2013
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int v) : val(v), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<TreeNode *> getAllTrees(vector<int> & preorder) {
        return getNext(preorder, 0, preorder.size() - 1);
    }
    
    vector<TreeNode *> getNext(vector<int> & preorder, int L, int R) {
        vector<TreeNode *> ans;
        if (L > R) { return ans; }
        if (L == R) {
            ans.push_back(new TreeNode(preorder[L]));
            return ans;
        }
        
        for (int i = L; i <= R; ++ i) {
            vector<TreeNode *> lc = getNext(preorder, L+1, i);
            vector<TreeNode *> rc = getNext(preorder, i+1, R);
            
            if (lc.size() == 0) {
                for (int k = 0; k < rc.size(); ++ k) {
                    TreeNode * root = new TreeNode(preorder[L]);                    
                    //root->left = lc[j]; // root->left is NULL
                    root->right = rc[k];
                    ans.push_back(root);
                }            
            } else if (rc.size() == 0) {
                for (int j = 0; j < lc.size(); ++ j) {
                    TreeNode * root = new TreeNode(preorder[L]);                    
                    root->left = lc[j];
                    //root->right = rc[k]; // root->right is NULL
                    ans.push_back(root);
                }                   
            } else {            
                for (int j = 0; j < lc.size(); ++ j) {
                    for (int k = 0; k < rc.size(); ++ k) {
                        TreeNode * root = new TreeNode(preorder[L]);                    
                        root->left = lc[j];
                        root->right = rc[k];
                        ans.push_back(root);
                    }
                }
            }
        }
        
        return ans;
    }
    
    void dump_inorder(TreeNode * n) {
         if (! n) return;
         dump_inorder(n->left);
         cout << n->val << " ";
         dump_inorder(n->right);
    }
    
    // iterative version of inorder traversal.
    void inorder(TreeNode * root) {
        if (! root) return;
        
        stack<TreeNode *> s;
        TreeNode * n = root;
        
        while (1) {
            while (n) {
                s.push(n);
                n = n->left;
            }
            
            if (! s.empty()) {
                n = s.top();
                s.pop();
                cout << n->val << " ";
                n = n->right;
            } else {
                break;
            }
        }
    }
};

void test() {
    int a[] = {1,2,3,4};
    int n = sizeof(a) / sizeof(int);
    vector<int> pre;
    for (int i = 0; i < n; ++ i) pre.push_back(a[i]);
    
    Solution so;
    vector<TreeNode *> ans = so.getAllTrees(pre);
    
    for (int i = 0; i < ans.size(); ++ i) {
        cout << (i+1) << " : ";
        so.dump_inorder(ans[i]);
        cout << endl;
    }
    cout << endl;
    
    for (int i = 0; i < ans.size(); ++ i) {
        cout << (i+1) << " : ";
        so.inorder(ans[i]);
        cout << endl;
    }

}

int main() {
    test();
    return 0;
}
