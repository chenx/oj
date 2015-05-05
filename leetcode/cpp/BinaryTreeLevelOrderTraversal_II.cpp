//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 12/17/2012
// @Last modified: 1/13/2013
//

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 *
 * Same as BinaryTreeLevelOrderTraversal, but use a deque to push_front(),
 * then transfer to deque to vector.
 * 
 * vector: push_back(), pop_back(), 
 *         insert, erase, front(), back(), at, []
 * deque:  push_back(), pop_back(), push_front(), pop_front(), 
 *         insert(), erase, swap, clear, front, back, at, [].
 */
class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        int level_ct, ct;
        TreeNode * n;
        vector<vector<int> > vs;
        deque<vector<int> > qs;
        if (NULL == root) return vs;
        
        queue<TreeNode *> q;
        q.push(root);
        level_ct = 1;
                
        while(q.size() > 0) {
            vector<int> v;
            ct = 0;
            while (level_ct > 0) {
                n = q.front();
                if (n->left != NULL) {
                    q.push(n->left);
                    ct ++;
                }
                if (n->right != NULL) {
                    q.push(n->right);
                    ct ++;
                }
                
                v.push_back(n->val);
                q.pop();
                level_ct --;
            }
            qs.push_front(v);
            
            level_ct = ct;
        }
        
        for (int i = 0; i < qs.size(); i ++) {
            vs.push_back(qs[i]);
        }
        
        return vs;
        
    }
};


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 *
 * Same as BinaryTreeLevelOrderTraversal.cpp, only change is
 * from: vs.push_back(v);
 * to:   vs.insert(vs.begin(), v); // <---- only change.
 *
 * 1/13/2013
 */
class Solution2 {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > vs;
        if (! root) return vs;
        
        queue<TreeNode *> Q;
        Q.push(root);
        
        int level_ct = 1, ct = 0;
        TreeNode * n;
        vector<int> v;
        
        while (Q.size() > 0) {
            
            while (level_ct > 0) {
                n = Q.front();
                Q.pop();
                v.push_back(n->val);
                -- level_ct;

                if (n->left) {
                    Q.push(n->left);
                    ++ ct;
                }
                if (n->right) {
                    Q.push(n->right);
                    ++ ct;
                }
            }

            vs.insert(vs.begin(), v); // <---- only change.
            v.clear();
            level_ct = ct;
            ct = 0;
        }
        
        return vs;
    }
};


// This also works.
class Solution3 {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > ans;
        if (! root) return ans;
        
        queue<TreeNode *> q;
        q.push(root);
        int level_ct = 1;
        
        while (level_ct > 0) {
            int ct = 0;
            vector<int> R;
            
            for (; level_ct > 0; -- level_ct) {
                TreeNode * t = q.front();
                q.pop();
                R.push_back(t->val);
                
                if (t->left) { q.push(t->left); ++ ct; }
                if (t->right) { q.push(t->right); ++ ct; }
            }
            
            level_ct = ct;
            ans.insert(ans.begin(), R);
        }
        
        return ans;
    }
};
