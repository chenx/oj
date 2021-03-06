/**
 * Printing a Binary Tree top-down (column wise). (FB). See:
 * http://codereview.stackexchange.com/questions/36799/printing-a-binary-tree-top-down-column-wise
 * E.g., We have a binary tree, suppose like this:
 *
 *        8
 *      /   \
 *     6     10
 *    / \   /  \
 *   4   7 9    12
 *  / \
 * 3   5
 * Output should be:
 * 3
 * 4
 * 6 5
 * 8 7 9
 * 10
 * 12
 *
 * By: X.C.
 * On: 2/6/2015
 */
#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct Node {
    int val;
    Node * left;
    Node * right;
    Node(int v): val(v), left(NULL), right(NULL) {}
};

// This works.
// However, using pre-order traversal, top-down order may not be guaranteed. 
// E.g., if 5 has a right child in test2().
void printT(Node * n, map<int, vector<int> > & m, int col, int &mi, int &ma) {
    if (n == NULL) return;

    m[col].push_back(n->val);
    mi = min(mi, col);
    ma = max(ma, col);

    printT(n->left, m, col - 1, mi, ma);
    printT(n->right, m, col + 1, mi, ma);
}

void output(map<int, vector<int> > & m, int mi, int ma) {
    for (int i = mi; i <= ma; ++ i) {
        for (int j = 0; j < m[i].size(); ++ j) {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
}

void test1() {
    Node * root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    map<int, vector<int> > m;
    int mi = 0, ma = 0, col = 0;
    printT(root, m, col, mi, ma);
    output(m, mi, ma);
}

void test2() {
    Node * root = new Node(8);
    root->left = new Node(6);
    root->left->left = new Node(4);
    root->left->right = new Node(7);
    root->left->left->left = new Node(3);
    root->left->left->right = new Node(5);
    root->right = new Node(10);
    root->right->left = new Node(9);
    root->right->right = new Node(12);

    map<int, vector<int> > m;
    int mi = 0, ma = 0, col = 0;
    printT(root, m, col, mi, ma);
    output(m, mi, ma);
}

////////////////////
// This works. 
// From: http://www.mitbbs.com/mitbbs_article_t.php?board=JobHunting&gid=32883277&start=32883353&pno=-1
void printBT_BFS(TreeNode *root, map<int, vector<int> > &hash, int &mincol, int &maxcol) {
    if(root==NULL) return;
    queue<pair<TreeNode *, int> > q; //store the node pointer and the column
    q.push(pair<TreeNode *, int>(root, 0));
    while(!q.empty()) {
        pair<TreeNode *, int> item = q.front();
        q.pop();
        TreeNode *node = item.first;
        int col = item.second;
        hash[col].push_back(node->val);
        mincol = min(mincol, col);
        maxcol = max(maxcol, col);
        if(node->left!=NULL) q.push(pair<TreeNode *, int>(node->left, col-1));
        if(node->right!=NULL) q.push(pair<TreeNode *, int>(node->right, col+1));
    }
}
void print(map<int, vector<int> > &hash, int mincol, int maxcol) {
    for(int i=mincol;i<=maxcol;i++) {
        for(int j=0;j<hash[i].size();j++) {
            cout<<hash[i][j]<<" ";
        }
        cout<<endl;
    }
}
////////////////////

int main() {
    test1();
    test2();

    return 0;
}
