// Time: O(m * alpha(n)) for m operations, n elements. alpha(n): reverse ackerman function =~ 1
// Space: O(n)
class UnionFind {
public:
  UnionFind() : components(0) {}

  void add(int x) {  // O(1)
    if (parent.contains(x)) return;
    
    parent[x] = x;
    rank[x] = 0;
    ++ components;
  }

  // original, recursive version.
  // Time: O(alpha(n)) =~ O(1)
  int find(int x) {  // O(alpha(n))
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
  }

  // Time: O(alpha(n)) =~ O(1)
  void get_union(int x, int y) {  // O(alpha(n))
    x = find(x);
    y = find(y);
    if (x == y) return;

    int rx = rank[x], ry = rank[y];
    if (rx < ry) {
      parent[x] = y;
    } else if (ry < rx) {
      parent[y] = x;
    } else {
      parent[y] = x;
      ++ rank[x];
    }
    -- components;
  }

  const unordered_map<int, int>& get_parent_map() const {
    return parent;
  }

  int components;
private:
  unordered_map<int, int> parent;
  unordered_map<int, int> rank;
};

// Time: O(n)
// Space: O(n)
class Solution2 {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        UnionFind uf;
        unordered_map<int, int> parent; // <node, node's parent>
        for (int i = 0; i < n; ++ i) {
            uf.add(i);
            vector<int> children = {leftChild[i], rightChild[i]};
            for (int child : children) {
                if (child == -1) continue;
                
                if (parent.contains(child) && parent[child] != i) return false; // conflict
                if (parent.contains(i) && parent[i] == child) return false; // cycle
                parent[child] = i;
                uf.add(child);
                uf.get_union(i, child);
            }
        }

        if (uf.components != 1) return false;

        // check for cycle.
        int node = uf.get_parent_map().begin()->second;
        unordered_set<int> used;
        if (has_cycle(node, parent, used)) {
            return false;
        }

        return true;
    }

    bool has_cycle(int node, unordered_map<int, int>& parent, unordered_set<int>& used) {
        if (used.contains(node)) return true;

        used.insert(node);
        if (parent.contains(node)) {
            if (has_cycle(parent[node], parent, used)) {
                return true;
            }
        }
        return false;
    }
};


class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        UnionFind uf;
        unordered_map<int, int> parent; // <node, node's parent>
        for (int i = 0; i < n; ++ i) {
            uf.add(i);
            if (leftChild[i] != -1) {
                if (parent.contains(leftChild[i]) && parent[leftChild[i]] != i) return false; // conflict
                if (parent.contains(i) && parent[i] == leftChild[i]) return false; // cycle
                parent[leftChild[i]] = i;
                // cout << "parent[" << leftChild[i] << "]" << " = " << i << endl;
                uf.add(leftChild[i]);
                uf.get_union(i, leftChild[i]);
            }
            if (rightChild[i] != -1) {
                if (parent.contains(rightChild[i]) && parent[rightChild[i]] != i) return false; // conflict
                if (parent.contains(i) && parent[i] == rightChild[i]) return false; // cycle
                parent[rightChild[i]] = i;
                // cout << "parent[" << rightChild[i] << "]" << " = " << i << endl;
                uf.add(rightChild[i]);
                uf.get_union(i, rightChild[i]);
            }
        }

        unordered_map<int, unordered_set<int>> groups;
        for (auto [key, _] : uf.get_parent_map()) {
            // cout << "group: " << uf.find(key) << ":" << key << endl;
            groups[uf.find(key)].insert(key);
        }
        // cout << "groups.size: " << groups.size() << endl;
        if (groups.size() != 1) return false;

        // check for cycle.
        int node = *groups.begin()->second.begin();
        unordered_set<int> used;
        // used.insert(node);
        // while (true) {
        //     if (! parent.contains(node)) { break; }
        //     node = parent[node];
        //     if (used.contains(node)) return false;
        //     used.insert(node);
        // }
        if (has_cycle(node, parent, used)) {
            return false;
        }

        return true;
    }

    bool has_cycle(int node, unordered_map<int, int>& parent, unordered_set<int>& used) {
        if (used.contains(node)) return true;

        used.insert(node);
        if (parent.contains(node)) {
            if (has_cycle(parent[node], parent, used)) {
                return true;
            }
        }
        return false;
    }
};


/**
1361. Validate Binary Tree Nodes
Solved
Medium
Topics
conpanies iconCompanies
Hint

You have n binary tree nodes numbered from 0 to n - 1 where node i has two children leftChild[i] and rightChild[i], 
return true if and only if all the given nodes form exactly one valid binary tree.

If node i has no left child then leftChild[i] will equal -1, similarly for the right child.

Note that the nodes have no values and that we only use the node numbers in this problem.

 

Example 1:

Input: n = 4, leftChild = [1,-1,3,-1], rightChild = [2,-1,-1,-1]
Output: true

Example 2:

Input: n = 4, leftChild = [1,-1,3,-1], rightChild = [2,3,-1,-1]
Output: false

Example 3:

Input: n = 2, leftChild = [1,0], rightChild = [-1,-1]
Output: false
 */
