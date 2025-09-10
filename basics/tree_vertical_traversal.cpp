class Solution {
public:
   vector<vector<int>> verticalOrder(TreeNode* root) {
       vector<vector<int>> ans;
       if (!root) return ans;


       unordered_map<int, vector<int>> cols;  // value, col #
       unordered_map<TreeNode*, int> m;  // node, col
       m[root] = 0;
       int minCol = INT_MAX, maxCol = INT_MIN;
       queue<TreeNode* > q;
       q.push(root);


       while (!q.empty()) {
           for (int i = 0, len = q.size(); i < len; ++ i) {
               TreeNode* n = q.front();
               q.pop();


               int col = m[n];
               cols[col].push_back(n->val);
               minCol = min(minCol, col);
               maxCol = max(maxCol, col);
  
               if (n->left) {
                   m[n->left] = col - 1;
                   q.push(n->left);
               }
               if (n->right) {
                   m[n->right] = col + 1;
                   q.push(n->right);
               }
           }
       }


       for (int i = minCol; i <= maxCol; ++ i) {
           if (cols.contains(i)) {
               ans.push_back(cols[i]);
           }
       }
       return ans;
   }
};
