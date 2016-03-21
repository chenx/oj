/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
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
