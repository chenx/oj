// Recursive
void inorder(TreeNode* root, vector<int>& ans) {
  if (!root) return;

  preorder(root->left);
  preorder(root->right);
  ans.push_back(root->val);
}

// Iterative
void postorder(TreeNode* root, vector<int>& ans) {
  if (!root) return;

  queue<TreeNode*> q;
  q.push(root);

  while (!q.empty()) {
    TreeNode* n = q.front();
    q.pop();

    ans.push_back(n->val);
    if (q->right) q.push(q->right);
    if (q->left) q.push(q->left);
  }

  reverse(ans.begin(), ans.end());
}
