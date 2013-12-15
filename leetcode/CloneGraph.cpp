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
    

    UndirectedGraphNode * clone(UndirectedGraphNode * root, 
            map<UndirectedGraphNode *, UndirectedGraphNode *> &m) {
        if (! root) return NULL;
        
        map<UndirectedGraphNode *, UndirectedGraphNode *>::iterator it = m.find(root);
        if (it != m.end()) return (*it).second;
        
        UndirectedGraphNode * n = new UndirectedGraphNode(root->label);
        m[root] = n; 
        
        for (int i = 0; i < root->neighbors.size(); ++ i) {
            n->neighbors.push_back( clone(root->neighbors[i], m) );
        }
        
        return n;
    }

    
};