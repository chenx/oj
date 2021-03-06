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
 * Note: use stack.
 *
 */
 
// Works. Most clean so far. Only 3 changes as shown below by "<--".
class Solution6 {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (! root) return ans;
        
        bool rev = false;  // <--
        queue<TreeNode *> q;
        q.push(root);
        
        while (! q.empty()) {
            vector<int> v;
            for (int i = q.size(); i > 0; -- i) {
                TreeNode * n = q.front();
                q.pop();
                
                v.push_back(n->val);
                
                if (n->left) q.push(n->left);
                if (n->right) q.push(n->right);
            }
            
            if (rev) reverse(v.begin(), v.end());  // <--
            rev = ! rev;  // <--
            
            ans.push_back(v);
        }
        
        return ans;
    }
};

class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > vs;
        if (NULL == root) return vs;
        
        TreeNode * n;
        stack<TreeNode *> * q1 = new stack<TreeNode *>(); // same w/o ()
        stack<TreeNode *> * q2 = new stack<TreeNode *>(); // same w/o ()
        stack<TreeNode *> * tmp;
        
        q1->push(root);
        int order = -1; 
        
        while(q1->size() > 0) {
            vector<int> v;
            while(q1->size() > 0) {
                n = q1->top();
                q1->pop();
                if (order == -1) {
                    if (n->left != NULL) q2->push(n->left);
                    if (n->right != NULL) q2->push(n->right);
                } else {
                    if (n->right != NULL) q2->push(n->right);                    
                    if (n->left != NULL) q2->push(n->left);
                }
                v.push_back(n->val);
            }
            vs.push_back(v);
            
            tmp = q1;
            q1 = q2;
            q2 = tmp;
            order *= -1; 
        }
        
        return vs;
    }
};

/*
// version 2, using deque. This works too.
class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > vs;
        if (NULL == root) return vs;
        
        TreeNode * n;
        deque<TreeNode *> * q1 = new deque<TreeNode *>;
        deque<TreeNode *> * q2 = new deque<TreeNode *>;
        deque<TreeNode *> * tmp;
        
        q1->push_front(root);
        int order = -1; 
        
        while(q1->size() > 0) {
            vector<int> v;
            while(q1->size() > 0) {
                n = q1->front();
                q1->pop_front();
                if (order == -1) {
                    if (n->left != NULL) q2->push_front(n->left);
                    if (n->right != NULL) q2->push_front(n->right);
                } else {
                    if (n->right != NULL) q2->push_front(n->right);                    
                    if (n->left != NULL) q2->push_front(n->left);
                }
                v.push_back(n->val);
            }
            vs.push_back(v);
            
            tmp = q1;
            q1 = q2;
            q2 = tmp;
            order *= -1; 
        }
        
        return vs;
    }
};
*/

/**
 * Same as BinaryTreeZigzagLevelOrderTraversal, only 4 changes are shown below.
 * 1/13/2013
 */
class Solution3 {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        int level_ct, ct;
        TreeNode * n;
        vector<vector<int> > vs;
        if (NULL == root) return vs;
        
        queue<TreeNode *> q;
        q.push(root);
        level_ct = 1;
        int order = 1; // -------------> change 1.
                
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
                
                if (order == 1) v.push_back(n->val); // -------------> change 2.
                else v.insert(v.begin(), n->val);    // -------------> change 3.
                q.pop();
                level_ct --;
            }
            vs.push_back(v);
            
            level_ct = ct;
            order = - order;  // -------------> change 4.
        }
        return vs;
    }
};


// This works too. Seems most clean.
class Solution4 {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > ans;
        if (! root) return ans;
        
        queue<TreeNode *> q;
        q.push(root);
        int level_ct = 1;
        int level = 0; // <--
        
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

            if (level & 1) { reverse(R.begin(), R.end()); } // <--
            ans.push_back(R);
            ++ level; // <--
        }
        
        return ans;        
    }
};


// Works. Even better than Solution4.
class Solution5 {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (! root) return ans;
        
        queue<TreeNode *> q;
        q.push(root);
        int ct = 1;
        bool odd = true;
        
        while (! q.empty()) {
            vector<int> v;
            for (; ct > 0; -- ct) {
                TreeNode * n = q.front();
                q.pop();
                if (odd) v.push_back(n->val);
                else v.insert(v.begin(), n->val);
                
                if (n->left != NULL) q.push(n->left);
                if (n->right != NULL) q.push(n->right);
            }
            
            ans.push_back(v);
            ct = q.size();
            odd = ! odd;
        }
        
        return ans;
    }
};


/**
Binary Tree Zigzag Level Order Traversal
Difficulty: Medium

Given a binary tree, return the zigzag level order traversal of 
its nodes' values. (ie, from left to right, then right to left 
for the next level and alternate between).

For example:
Given binary tree {3,9,20,#,#,15,7},

    3
   / \
  9  20
    /  \
   15   7

return its zigzag level order traversal as:

[
  [3],
  [20,9],
  [15,7]
]

 */
