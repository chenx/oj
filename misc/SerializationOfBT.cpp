//
// BST serialization and de-serialization.
// From: http://www.leetcode.com/2010/09/serializationdeserialization-of-binary.html
// 
// Convert string to int: http://www.cplusplus.com/forum/general/13135/
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
        if (! root) {
            cout << "#" << " ";
            return;
        }
        
        cout << root->val << " ";
        serialization(root->left);
        serialization(root->right);
    }
    
    Node * deserialization(Node *& root, ifstream & fin) {
        readBT(root, fin);
    }

    // This works.
    void readBT(Node *& root, ifstream &fin) {
        if (fin == NULL) return;
        
        string v;
        fin >> v;
        if (v == "#" || v == "") return;
        
        int val = atoi(v.c_str()); // NOTE: convert string to int.
        
        root = new Node(val);
        readBT(root->left, fin);
        readBT(root->right, fin);
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
    
    ifstream fin("SerializationOfBT.txt");
    //fin.open("BST_serialization.txt", ios::in);
    Node * s = NULL;
    t.deserialization(s, fin);
    t.draw(s);
    fin.close();
    
    return 0;
}


/*
 * Serialization/Deserialization of a Binary Tree.
 * http://www.leetcode.com/2010/09/serializationdeserialization-of-binary.html
 * http://en.wikipedia.org/wiki/Binary_tree#Encodings
 * 
 * Serialize:
 * Can use Pre-order traversal with a variation (use a sentinel #):       
    void writeBinaryTree(BinaryTree *p, ostream &out) {
      if (!p) {
        out << "# ";
      } else {
        out << p->data << " ";
        writeBinaryTree(p->left, out);
        writeBinaryTree(p->right, out);
      }
    }
 *
 * Deserializing a Binary Tree:
    void readBinaryTree(BinaryTree *&p, ifstream &fin) {
      int token;
      bool isNumber;
      if (!readNextToken(token, fin, isNumber))
        return;
      if (isNumber) {
        p = new BinaryTree(token);
        readBinaryTree(p->left, fin);
        readBinaryTree(p->right, fin);
      }
    }
    
 * Another solution: level order traversal.
 * Question: how to avoid using sentinel? 
 * Ans: escaping sequence?  1 # means a sentinel; if \#, then means #. \ is escaped by \\.
 */
