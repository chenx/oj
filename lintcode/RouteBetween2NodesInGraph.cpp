// It seems the "graph" parameter is useless.
// Simple BFS or DFS.
/**
 * Definition for Directed graph.
 * struct DirectedGraphNode {
 *     int label;
 *     vector<DirectedGraphNode *> neighbors;
 *     DirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    /**
     * @param graph: A list of Directed graph node
     * @param s: the starting Directed graph node
     * @param t: the terminal Directed graph node
     * @return: a boolean value
     */
    bool hasRoute(vector<DirectedGraphNode*> graph,
                  DirectedGraphNode* s, DirectedGraphNode* t) {
        // write your code here
        if (s->label == t->label) return true;
        
        unordered_set<DirectedGraphNode *> visited;
        visited.insert(s);
        queue<DirectedGraphNode * > q;
        q.push(s);
        
        while (! q.empty()) {
            DirectedGraphNode * n = q.front();
            q.pop();
            
            for (int i = 0; i < n->neighbors.size(); ++ i) {
                DirectedGraphNode * m = n->neighbors[i];
                if (! visited.count(m)) {
                    if (m->label == t->label) return true;
                    visited.insert(m);
                    q.push(m);
                }
            }
        }
        return false;
    }
};


/**
Route Between Two Nodes in Graph

Given a directed graph, design an algorithm to find out whether there is 
a route between two nodes.

Example

Given graph:

A----->B----->C
 \     |
  \    |
   \   |
    \  v
     ->D----->E

for s = B and t = E, return true

for s = D and t = C, return false

 */
