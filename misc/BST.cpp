//
// To review BST operations.
//
// @Author: Xin Chen
// @Created on: 4/7/2013
// @Last modified: 4/7/2013
// 
#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    int val;
    Node * left;
    Node * right;
    Node(int v) : val(v), left(NULL), right(NULL) {}
};

class BST {
public:
        
    Node * insert(Node * root, int v) {
        if (! root) {
            return new Node(v);
        }
        
        if (root->val == v) {
            // do nothing
        }
        else if (root->val < v) {
            root->left = insert(root->left, v);
        }
        else if (root->val > v) {
            root->right = insert(root->right, v);
        }
        
        return root;
    }
    
    // delete by copy.
    Node * deletec(Node * root, int v) {
        if (! root) return NULL;
        
        if (root->val < v) {
            root->left = deletec(root->left, v);
        }
        else if (root->val > v) {
            root->right = deletec(root->right, v);
        }
        else {
            if (root->left && root->right) {
                //Node * n = findMin(root->right);
                Node * n = root->right;
                while (n->left) n = n->left;
                
                root->val = n->val;
                root->right = deletec(root->right, n->val);
            }
            else if (root->left || root->right) {
                Node * tmp = root;
                root = root->left ? root->left : root->right;
                delete tmp;
            }
            else {
                delete root;
                root = NULL;
            }
        }
        
        return root;
    }
    
    // delete by merge
    Node * deletem (Node * root, int v) {
        if (! root) return NULL;
        
        if (root->val < v) {
            root->left = deletem(root->left, v);
        }
        else if (root->val > v) {
            root->right  = deletem(root->right, v);
        }
        else {
            if (root->left == NULL && root->right == NULL) {
                delete root;
                root = NULL;
            }
            else if (root->left == NULL || root->right == NULL) {
                Node * tmp = root;
                root = root->left ? root->left : root->right;
                delete tmp;
            }
            else {
                Node * tmp = root;
                
                // attach root's right child to left side's largest offspring.
                Node * n = root->left;
                while (n->right) n = n->right;
                n->right = root->right;
                
                root = root->left;
                delete tmp;
            }
        }
        
        return root;
    }
    
    void draw(Node * root) {
        cout << "tree: " << endl;
        draw2(root, 0);
    } 
    
    void draw2(Node * n, int level) {
        if (! n) return;
        
        draw2(n->left, level + 2);
        string sp(level, ' ');
        cout << sp << n->val << endl;
        draw2(n->right, level + 2);
    }
    
    Node * findMin(Node * n) {
        if (! n) return NULL;
        while (n->left) {
            n = n->left;
        }
        
        return n;
    }
};

int main() {
    BST t;
    Node * root = NULL;
    
    int A[] = {2,1,3,4,6,5,7,8};
    int n = sizeof(A) / sizeof(int);
    
    for (int i = 0; i < n; ++ i) {
        root = t.insert(root, A[i]);
        t.draw(root);
    }

    for (int i = 0; i < n; ++ i) {
        root = t.deletem(root, A[i]);
        t.draw(root);
    }    
    
    return 0;
}
