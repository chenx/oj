/**
 * Convert Binary Tree to (circular) double linked list.
 *
 * By: X.C.
 * On: 3/5/2015
 */
#include <iostream>
#include <stack>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int v) : val(v), left(NULL), right(NULL) {}
};

class BT2Dll {
    void append(TreeNode * t, TreeNode *& head, TreeNode *& tail) {
        if (head == NULL) {
            head = tail = t;
            t->left = t->right = NULL;
        }
        else {
            tail->right = t;
            t->left = tail;
            t->right = NULL;
            tail = t;
        }
    }
public:
    BT2Dll() {

    }

    // iterative version. This works.
    TreeNode * convert(TreeNode * root) {
        if (! root) return NULL;

        TreeNode * head = NULL, * tail = NULL;

        stack<TreeNode *> s;
        TreeNode * n = root;
        while (1) {
            while (n) {
                s.push(n);
                n = n->left;
            }

            if (s.empty()) {
                if (head) { // connect head and tail, if need circular DLL.
                    head->left = tail;
                    tail->right = head;
                }
                break;
            }
            else {
                TreeNode * tmp = s.top();
                s.pop();
                n = tmp->right;
                
                cout << tmp->val << endl;
                append(tmp, head, tail);
            }
        }
        
        return head;
    }
    
    // recursive version. This works too.
    TreeNode * convert_recursive(TreeNode * root) {
        if (! root) return NULL;
        TreeNode * head = NULL, * tail = NULL, * prev = NULL;
        get(root, head, tail, prev);
        if (head) {
            head->left = tail;
            tail->right = head;
        }
        return head;
    }

    void get(TreeNode * root, TreeNode *& head, TreeNode *& tail, TreeNode *& prev) {
        if (! root) return;

        get(root->left, head, tail, prev);
        if (! prev) {
            head = tail = root;
        }
        else {
            tail->right = root;
            root->left = tail;
            tail = root;
        }
        prev = root;
        get(root->right, head, tail, prev);
    }
    
    
    void dumpDll(TreeNode * head) {
        if (! head) return;
        
        TreeNode * n = head;
        do {
            cout << "[" << (n->left ? n->left->val : 0) << "]"
                 << n->val 
                 << "[" << (n->right ? n->right->val : 0) << "] ";
            n = n->right;
        } while (n && n != head); // use "n &" to guard against the case Dll is not circular.
        cout << endl;
    }
};

// Output: [6]1[2] [1]2[3] [2]3[4] [3]4[5] [4]5[6] [5]6[1]
void test1() {
/* 
   3
  / \
 1   5
  \ / \
  2 4  6
 */ 
    TreeNode * root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->left->right = new TreeNode(2);
    root->right = new TreeNode(5);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(6);
    
    BT2Dll bd; 
    TreeNode * head = bd.convert(root);
    bd.dumpDll(head);
}

int main() {
    test1();
    return 0;
}
