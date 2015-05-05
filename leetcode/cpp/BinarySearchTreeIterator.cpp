#include <iostream>
#include <stack>
using namespace std;

/**
 * Definition for binary tree
 */
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
/**
 * This works.
 */
class BSTIterator {
    TreeNode * n;
    TreeNode * nextNode;
    stack<TreeNode *> s;
    
    void getNext() {
        while (n) {
            s.push(n);
            n = n->left;
        }
        
        if (s.empty()) {
            nextNode = NULL;
        }
        else {
            n = s.top();
            s.pop();
            nextNode = n;
            n = n->right;
        }        
    }
public:
    BSTIterator(TreeNode *root) {
        n = root;
        getNext();
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return nextNode != NULL;
    }

    /** @return the next smallest number */
    int next() {
        int v = nextNode->val;
        getNext();
        return v;
    }
};


//
// This works too.
//
class BSTIterator2 {
    TreeNode * n;
    bool _hasNext;
    int _nextVal;
    stack<TreeNode *> s;
    
    void getNext() {
        while (n) {
            s.push(n);
            n = n->left;
        }
        
        if (s.empty()) {
            _hasNext = false;
        }
        else {
            n = s.top();
            s.pop();
            _nextVal = n->val;
            n = n->right;
        }        
    }
public:
    BSTIterator(TreeNode *root) {
        n = root;
        _hasNext = true;
        getNext();
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return _hasNext;
    }

    /** @return the next smallest number */
    int next() {
        int v = _nextVal;
        getNext();
        return v;
    }
};


/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */

int main() {
    TreeNode * n = new TreeNode(1);
    n->right = new TreeNode(2);

    BSTIterator i = BSTIterator(n);
    while (i.hasNext()) cout << i.next() << endl;

    return 0;
}


/**
Binary Search Tree Iterator 
Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.

Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
 */
