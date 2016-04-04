/**
 * BinaryTreeUpsideDown.
 * @Author: X. Chen
 * @From: 1/25/2015
 */
 
// Works. Top-down approach. From Clean Code Handbook, p.60.
class Solution2 {
public:
    TreeNode * upsideDown(TreeNode *root) {
        TreeNode * parent = NULL, * parentRight = NULL;
        while (root) {
            TreeNode * left = root->left;
            root->left = parentRight;
            parentRight = root->right;
            root->right = parent;
            parent = root;
            root = left;
        }
        return parent;
    }
};


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

// Works. Tested.
class Solution2 {
public:
    /**
     *  Bottom up method. Much more simple.
     * At any p, you want to do: 
     * p->left = parent->right, p->right = parent.
     */
    
    TreeNode * upsideDown(TreeNode *root) {
        return dfs(root, NULL);
    }
    
    TreeNode * dfs(TreeNode *p, TreeNode * parent) {
        if (p == NULL) return parent;
        TreeNode * root = dfs(p->left, p);
        p->left = parent != NULL ? parent->right : NULL;
        p->right = parent;
        return root;
    }
}

// Tested and NOT work yet. Input: [1,2], Output: [2,1], Expected: [2,null,1]
// Use a stack, 2 steps.
class Solution {
public:
    TreeNode * upsideDown(TreeNode * root) {
        if (! root) return NULL;

        // first push to a stack: root, root->right, ...
        stack<TreeNode *> st;
        while (root) {
            TreeNode * tmp = root->left;
            st.push(root);
            if (root->right != NULL) st.push(root->right);
            root->left = root->right = NULL; // must have this.
            root = tmp;
        }

        // next pop from stack, construct new tree.
        root = NULL;
        TreeNode * n, * n2, * tail;
        while (! st.empty()) {
            n = st.top();
            st.pop();
            if (st.empty()) {
                if (root == NULL) { root = tail = n; }
                else tail->right = n;
                break;
            }

            n2 = st.top();
            st.pop();

            if (root == NULL) { root = n; }
            else { tail->right = n; }

            tail = n;
            tail->left = n2;
            tail->right = NULL;
        }

        return root;
    }
};

static void draw_graph(TreeNode * n, int height) {
    int i;
    string indent = "  ";
    if (n == NULL) return;
    draw_graph(n->right, height + 1);
    for (i = 0; i < height; i ++) cout << indent;
    cout << n->val << " " << endl;
    draw_graph(n->left, height + 1);
}

void drawTree(TreeNode * root) {
    draw_graph(root, 0);
}

int main() {
    // test case 1.
    TreeNode * root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    // test case 2, include following block.
    if (1) {
    TreeNode * left = root->left;
    left->left = new TreeNode(4);
    left->right = new TreeNode(5);
    left = left->left;
    left->left = new TreeNode(6);
    left->right = new TreeNode(7);
    }

    drawTree(root); //return 0;

    Solution so;
    TreeNode * newTree = so.upsideDown(root);

    drawTree(newTree);

    return 0;
}

/**
 * Binary Tree Upside Down.
 *
 * Given a binary tree where all the right nodes are leaf nodes, flip it upside down 
 * and turn it into a tree with left leaf nodes. 
 *
 * Keep in mind: ALL RIGHT NODES IN ORIGINAL TREE ARE LEAF NODE.
 *
 * for example, turn these:
 *
 *        1                 1
 *       / \               / \
 *      2   3             2   3
 *     / \
 *    4   5
 *   / \
 *  6   7
 *
 * into these:
 *
 *        1               1
 *       /               /
 *      2---3           2---3
 *     /
 *    4---5
 *   /
 *  6---7
 *
 * where 6 is the new root node for the left tree, and 2 for the right tree.
 * oriented correctly:
 *
 *     6                   2
 *    / \                 / \
 *   7   4               3   1
 *        / \
 *       5   2
 *            / \
 *          3   1
 *
 * Ref:
 * [1] http://www.careercup.com/question?id=6266917077647360
 */
