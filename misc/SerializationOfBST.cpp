//
// BST serialization and de-serialization.
// From: http://leetcode.com/2010/09/saving-binary-search-tree-to-file.html
// 
// @By: Xin Chen
// @Created on: 4/15/2013
// @Last modified: 4/15/2013
//

#include <iostream>
#include <fstream>
using namespace std;

class Node {
public:
    int val;
    Node * left;
    Node * right;
    Node(int v) {
        val = v;
        left = right = NULL;
    }
};

class BST {
public:
    void serialization(Node * root) {
        if (! root) return;
        
        output(root->val);
        serialization(root->left);
        serialization(root->right);
    }
    void output(int v) {
        cout << v << " ";
    }
    
    Node * deserialization(Node *& root, ifstream & fin) {
        if (fin == NULL) return NULL;
        int v;
        fin >> v;
        readBST(INT_MIN, INT_MAX, v, root, fin);
    }

    // This works.
    void readBST(int minv, int maxv, int &v, Node *& root, ifstream &fin) {
        //cout << "v = " << v << ", minv = " << minv << ", maxv = " << maxv << endl;
        if (v > minv && v < maxv) {
            int val = v;
            root = new Node(val);
            if (fin >> v) { // note: must be v here, and v is reference.
                readBST(minv, val, v, root->left, fin);
                readBST(val, maxv, v, root->right, fin);
            }
        }
    }
    
    // This works too.
    void readBST2(int minv, int maxv, int &v, Node *& root, ifstream & fin) {
        cout << "v = " << v << ", minv = " << minv << ", maxv = " << maxv << endl;
        if (v > minv && v < maxv) {
            root = new Node(v);
            int val = v;
            if (fin >> v) {
                readBST2(minv, val, v, root->left, fin);
                readBST2(val, maxv, v, root->right, fin);
            }
        }
    }

    // This magically does NOT work.
    void readBST2_bak(int minv, int maxv, int v, Node *& root, ifstream & fin) {
        //cout << "v = " << v << ", minv = " << minv << ", maxv = " << maxv << endl;
        if (v > minv && v < maxv) {
            root = new Node(v);
            int val;
            if (fin >> val) {
                readBST2(minv, v, val, root->left, fin);
                readBST2(v, maxv, val, root->right, fin);
            }
        }
    }

    
    void draw(Node * root) {
        draw(root, 0);
        cout << endl;
    }
    
    void draw(Node * n, int level) {
        if (! n) return;
        
        draw(n->right, level+1);
        string indent = string(2 * level, ' ');
        cout << indent << n->val << endl;
        draw(n->left, level+1);
    }
    
    Node * insert(Node * root, int v) {
        if (root == NULL) {
            root = new Node(v);
            return root;
        }
        
        if (v < root->val) {
            root->left = insert(root->left, v);
        }
        else if (v > root->val) {
            root->right = insert(root->right, v);
        }
        
        return root;
    }
};

int main() {
    BST t;
    Node * r = NULL;
    
    int A[] = {4,3,1,2,5,6,7};
    int n = sizeof(A) / sizeof(int);
    
    for (int i = 0; i < n; ++ i) {
        r = t.insert(r, A[i]);
        t.draw(r);
    }
    
    t.serialization(r); cout << endl;
    
    ifstream fin("SerializationOfBST.txt");
    //fin.open("BST_serialization.txt", ios::in);
    Node * s = NULL;
    t.deserialization(s, fin);
    t.draw(s);
    fin.close();
    
    return 0;
}


/*
   Serialization/Deserialization of a Binary Search Tree
   http://www.leetcode.com/2010/09/saving-binary-search-tree-to-file.html
   
   Serialization: Use Pre-order traversal.
   De-serialization: similar to check if a BT is BST:
    void readBSTHelper(int min, int max, int &insertVal,
                       BinaryTree *&p, ifstream &fin) {
      if (insertVal > min && insertVal < max) {
        int val = insertVal;
        p = new BinaryTree(val);
        if (fin >> insertVal) {
          readBSTHelper(min, val, insertVal, p->left, fin);
          readBSTHelper(val, max, insertVal, p->right, fin);
        }
      }
    }
     
    void readBST(BinaryTree *&root, ifstream &fin) {
      int val;
      fin >> val;
      readBSTHelper(INT_MIN, INT_MAX, val, root, fin);
    }
 */
