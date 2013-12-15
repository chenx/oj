//
// Clone linked structure. The idea is to use a hash table to avoid cycle.
//

#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

class Node {
public:
    int data;
    vector<Node *> next;
    Node(int d) : data(d) {}
};

class CopyLinkedStruct {
public:
    Node * clone_DFS(Node * graph) {
        map<Node *, Node *> m;
        return copy_helper(graph, m);
    }
    
    Node * copy_helper(Node * root, map<Node *, Node *> &m) {
        if (! root) return NULL;
        
        map<Node *, Node *>::iterator it = m.find(root);
        if (it != m.end()) return (*it).second;
        
        Node * n = new Node(root->data);
        m[root] = n; //m.insert(pair<Node*, Node*>(root, n));
        
        for (int i = 0; i < root->next.size(); ++ i) {
            n->next.push_back( copy_helper(root->next[i], m) );
        }
        
        return n;
    }
    
    //
    // http://leetcode.com/2012/05/clone-graph-part-i.html
    //
    Node * clone_BFS(Node * graph) {
        if (! graph) return NULL;
        
        map<Node *, Node *> m;
        
        queue<Node *> q;
        q.push(graph);
        
        Node * cp = new Node(graph->data);
        m[graph] = cp;
        
        while (! q.empty()) {
            Node * n = q.front();
            q.pop();
            
            cp = m[n]; // copy of n
            
            for (int i = 0; i < n->next.size(); ++ i) {
                Node * neighbor = n->next[i];
                if (m.find(neighbor) == m.end()) {
                    Node * c = new Node(neighbor->data);
                    m[neighbor] = c;
                    q.push(neighbor);
                    cp->next.push_back(c);
                }
                else {
                    cp->next.push_back(m[neighbor]);
                }
            }
        }
    }
};

int main() {
    return 0;
}
