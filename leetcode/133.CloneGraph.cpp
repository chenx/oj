// Another DFS.
class Solution9 {
public:
    Node* cloneGraph(Node* node) {
        map<Node*, Node*> map;
        return clone(node, map);
    }

    Node* clone(Node* node, map<Node*, Node*>& map) {
        if (! node) return NULL;

        if (map.contains(node)) return map[node];

        map[node] = new Node(node->val);
        for (auto neighbor : node->neighbors) {
            map[node]->neighbors.push_back(clone(neighbor, map));
        }
        return map[node];
    }
};

// DFS.
class Solution8 {
public:
    Node* cloneGraph(Node* node) {
        map<Node*, Node*> map;
        return clone(node, map);
    }

    Node* clone(Node* node, map<Node*, Node*>& map) {
        if (! node) return NULL;

        map[node] = new Node(node->val);
        for (auto neighbor : node->neighbors) {
            if (! map.contains(neighbor)) {
                map[neighbor] = clone(neighbor, map);
            }
            map[node]->neighbors.push_back(map[neighbor]);
        }
        return map[node];
    }
};

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */

// Works. BFS, more clean than Solution6.
// Time O(n+m), Space O(n).
// n - number of nodes, m - number of edges.
class Solution7 {
public:
    Node* cloneGraph(Node* node) {
        if (! node) return NULL;

        unordered_map<Node*, Node*> m;
        m[node] = new Node(node->val);

        queue<Node*> q;
        q.push(node);

        while (! q.empty()) {
            Node* n = q.front();
            q.pop();

            for (Node* neighbor : n->neighbors) {
                if (! m.contains(neighbor)) {
                    m[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }
                m[n]->neighbors.push_back(m[neighbor]);
            }
        }

        return m[node];
    }
}

// Works. Tested. So far best BFS.
class Solution6 {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *root) {
        if (! root) return NULL;
        
        unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> m;
        m[root] = new UndirectedGraphNode(root->label);
        
        queue<UndirectedGraphNode *> q;
        q.push(root);
        
        while (! q.empty()) {
            UndirectedGraphNode * node = q.front();
            q.pop();
            
            UndirectedGraphNode * copy = m[node];
            
            for (int i = 0; i < node->neighbors.size(); ++ i) {
                UndirectedGraphNode * n = node->neighbors[i];
                if (m.find(n) == m.end()) { // or: if (m[n] == NULL) {
                    m[n] = new UndirectedGraphNode(n->label);
                    q.push(n);
                }
                copy->neighbors.push_back(m[n]);
            }
        }
        
        return m[root];
    }
};

// DFS. Works too.
class Solution5 {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *root) {
        unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> m;
        return clone(root, m);
    }
    
    UndirectedGraphNode *clone(UndirectedGraphNode *root, 
            unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> & m) {
        if (root == NULL) return NULL;

        if (! m.count(root)) {  //if (m.find(root) == m.end()) { // both work.
            m[root] = new UndirectedGraphNode(root->label);
            
            for (int i = 0; i < root->neighbors.size(); ++ i) {
                m[root]->neighbors.push_back(clone(root->neighbors[i], m));
            }
        }
        
        return m[root];
    }
};

// Works. Tested. So far best DFS.
class Solution4 {
public:
    UndirectedGraphNode *cloneGraph2(UndirectedGraphNode *node) {
        unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> m;
        return clone(node, m);
    }
    
    UndirectedGraphNode * clone(UndirectedGraphNode * node, 
            unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> &m) {
        if (! node) return NULL;
        
        if (m.find(node) != m.end()) return m[node];
        
        UndirectedGraphNode * copy = new UndirectedGraphNode(node->label);
        m[node] = copy;
        for (int i = 0; i < node->neighbors.size(); ++ i) {
            copy->neighbors.push_back(clone(node->neighbors[i], m));
        }

        return copy;
    }
};

 
class Solution3 {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        map<UndirectedGraphNode *, UndirectedGraphNode *> m;
        return clone(node, m);
    }
    
    // DFS
    UndirectedGraphNode * clone(UndirectedGraphNode * root, 
            map<UndirectedGraphNode *, UndirectedGraphNode *> &m) {
        if (! root) return NULL;
        
        map<UndirectedGraphNode *, UndirectedGraphNode *>::iterator it = m.find(root);
        if (it != m.end()) return (*it).second;
        
        UndirectedGraphNode * n = new UndirectedGraphNode(root->label);
        m[root] = n;  // Note: this can NOT go after the for loop below!
        
        for (int i = 0; i < root->neighbors.size(); ++ i) {
            n->neighbors.push_back( clone(root->neighbors[i], m) );
        }
        
        return n;
    }
};


// DFS. This works too. 10/30/2014.
// Notice that no matter DFS or BFS, mapping is always m[old] = new.
class Solution2 {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> m;
        return clone(node, m);
    }
    
    UndirectedGraphNode * clone(UndirectedGraphNode *node, unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> &m) {
        if (! node) return NULL;
        
        UndirectedGraphNode * c = new UndirectedGraphNode(node->label);
        m[node] = c;
        
        for (int i = 0; i < node->neighbors.size(); ++ i) {
            UndirectedGraphNode * n = node->neighbors[i];
            if (m.find(n) != m.end()) {
                c->neighbors.push_back(m[n]);
            }
            else {
                c->neighbors.push_back( clone(n, m) );
            }
        }
        
        return c;
    }
};


// BFS.
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == NULL) return NULL;
        map<UndirectedGraphNode *, UndirectedGraphNode *> m;

        queue<UndirectedGraphNode *> q;
        q.push(node);

        UndirectedGraphNode * n = new UndirectedGraphNode(node->label);
        m[node] = n;
        
        while(! q.empty()) {
            UndirectedGraphNode *h = q.front();
            q.pop();
            
            for (int i = 0; i < h->neighbors.size(); ++ i) {
                UndirectedGraphNode *t = h->neighbors[i];
                map<UndirectedGraphNode *, UndirectedGraphNode *>::iterator it = m.find(t);
                if (it == m.end()) {
                    UndirectedGraphNode *t2 = new UndirectedGraphNode(t->label);
                    m[h]->neighbors.push_back(t2);
                    m[t] = t2;
                    q.push(t);
                }
                else {
                    m[h]->neighbors.push_back(m[t]);
                }
            }
        }
        
        return n;
    }
}


/**
133. Clone Graph
Difficulty: Medium

Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.

OJ's undirected graph serialization:

Nodes are labeled uniquely.
We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.

As an example, consider the serialized graph {0,1,2#1,2#2,2}.

The graph has a total of three nodes, and therefore contains three parts as separated by #.

    First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
    Second node is labeled as 1. Connect node 1 to node 2.
    Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.

Visually, the graph looks like the following:

       1
      / \
     /   \
    0 --- 2
         / \
         \_/

 */


