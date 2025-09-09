// Recursive
void preorder(TreeNode* root, vector<int>& ans) {
  if (!root) return;

  ans.push_back(root->val);
  preorder(root->left);
  preorder(root->right);
}

// Iterative
void preorder(TreeNode* root, vector<int>& ans) {
  if (!root) return;

  queue<TreeNode*> q;
  q.push(root);

  while (!q.empty()) {
    TreeNode* n = q.front();
    q.pop();

    ans.push_back(n->val);
    if (q->left) q.push(q->left);
    if (q->right) q.push(q->right);
  }
}
