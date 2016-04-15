// Should work. Tested locally. 
class Solution2 {
public:
    int countComponents(int n, vector<pair<int, int> >& edges) {
        int ct = 0, node_ct = 0;

        while (! edges.empty()) {
            ++ ct;
            remove(edges, node_ct);
        }
        return ct + (n - node_ct);
    }

    void remove(vector<pair<int, int> >& edges, int & node_ct) {
        pair<int, int> e = edges.back();
        edges.pop_back();

        deque<int> q;
        q.push_back(e.first);
        q.push_back(e.second);
        node_ct += 2;

        while (! q.empty()) {
            int k = q.front();
            q.pop_front();

            for (vector<pair<int, int> >::iterator it = edges.begin(); it != edges.end(); ) {
                pair<int, int> p = *it;
                if (k == p.first || k == p.second) {
                    int u = p.first + p.second - k;
                    if (find(q.begin(), q.end(), u) == q.end()) {
                        q.push_back(u);
                        ++ node_ct;
                    }

                    edges.erase(it);
                }
                else {
                    ++ it;
                }
            }
        }
    }
};


// Works. Tested. By XC.
class Solution {
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        int ct = 0, nodes_ct = 0;
        while (! edges.empty()) {
            removeEdge(edges, nodes_ct);
            ++ ct;
        }
        
        return ct + (n - nodes_ct); // (n - nodes_ct): nodes not used in edges.
    }
    
    void removeEdge(vector<pair<int, int>>& edges, int & nodes_ct) {
        auto e = edges[0];
        edges.erase(edges.begin()); // remove first edge.
        
        deque<int> q;
        q.push_back(e.first); // put first edge's 2 nodes on queue.
        q.push_back(e.second);
        nodes_ct += 2;
        
        while (! q.empty()) {
            int v = q.front();
            q.pop_front();
            
            for (auto it = edges.begin(); it != edges.end(); ) {
                if (v == (*it).first || v == (*it).second) { 
                    // found edge with matching node.
                    int u = (*it).first + (*it).second - v;  // get the other node.
                    if (find(q.begin(), q.end(), u) == q.end()) { 
                        q.push_back(u); // add the other node if it's not on queue.
                        ++ nodes_ct;
                    }
                    edges.erase(it); // remove edge.
                }
                else {
                    ++ it;
                }
            }
        }
    }
};


/**
Number of Connected Components in an Undirected Graph
Difficulty: Medium

Given n nodes labeled from 0 to n - 1 and a list of undirected edges 
(each edge is a pair of nodes), write a function to find the number 
of connected components in an undirected graph.

Example 1:
     0          3
     |          |
     1 --- 2    4
Given n = 5 and edges = [[0, 1], [1, 2], [3, 4]], return 2.

Example 2:
     0           4
     |           |
     1 --- 2 --- 3
Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [3, 4]], return 1.

Note:
You can assume that no duplicate edges will appear in edges. 
Since all edges are undirected, [0, 1] is the same as [1, 0] 
and thus will not appear together in edges.
 */
