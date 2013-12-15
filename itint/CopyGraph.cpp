
GraphNode * copy_helper(GraphNode * root, map<GraphNode *, GraphNode *> &m) {
        if (! root) return NULL;
        
        map<GraphNode *, GraphNode *>::iterator it = m.find(root);
        if (it != m.end()) return (*it).second;
        
        GraphNode * n = new GraphNode(root->data);
        m[root] = n;
        
        for (int i = 0; i < root->neighbors.size(); ++ i) {
            n->neighbors.push_back( copy_helper(root->neighbors[i], m) );
        }
        
        return n;
    
}

GraphNode *cloneGraph(GraphNode *node) {
        map<GraphNode *, GraphNode *> m;
        return copy_helper(node, m);
}
    
