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