/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution2 {
public:
    Node* construct(vector<vector<int>>& grid) {
        return solve(grid, 0, 0, grid.size());
    }

    Node* solve(vector<vector<int>>& grid, int x, int y, int size) {
        if (size == 1) {
            return new Node(grid[x][y], true);
        }

        size /= 2;
        Node* a = solve(grid, x, y, size); // upper left
        Node* b = solve(grid, x, y + size, size); // upper right
        Node* c = solve(grid, x + size, y, size); // bottom left
        Node* d = solve(grid, x + size, y + size, size); // bottom right

        if (a->isLeaf && b->isLeaf && c->isLeaf && d->isLeaf &&
            a->val == b->val && b->val == c->val && c->val == d->val) {
            return new Node(a->val, true);
        }

        return new Node(0 /* any value works */, false, a, b, c, d);
    }
};

class Solution {
public:
    Node* solve(vector<vector<int>>& grid, int x1, int y1, int length) {
        // Return a leaf node if the matrix size is one.
        if (length == 1) {
            return new Node(grid[x1][y1], true);
        }
        
        // Recursive calls to the four sub-matrices.
        Node* topLeft = solve(grid, x1, y1, length / 2);
        Node* topRight = solve(grid, x1, y1 + length / 2, length / 2);
        Node* bottomLeft = solve(grid, x1 + length / 2, y1, length / 2);
        Node* bottomRight = solve(grid, x1 + length / 2, y1 + length / 2, length / 2);
            
        // If the four returned nodes are leaf and have the same values
        // Return a leaf node with the same value.
        if (topLeft -> isLeaf && topRight -> isLeaf && bottomLeft -> isLeaf && bottomRight -> isLeaf
           && topLeft -> val == topRight -> val && topRight -> val == bottomLeft -> val 
           && bottomLeft -> val == bottomRight -> val) {
            return new Node(topLeft -> val, true);
        }
        
        // If the four nodes aren't identical, return non-leaf node with corresponding child pointers.
        return new Node(false, false, topLeft, topRight, bottomLeft, bottomRight);
    }
    
    Node* construct(vector<vector<int>>& grid) {
        return solve(grid, 0, 0, grid.size());
    }
};

/**
427. Construct Quad Tree

Given a n * n matrix grid of 0's and 1's only. We want to represent grid with a Quad-Tree.

Return the root of the Quad-Tree representing grid.

A Quad-Tree is a tree data structure in which each internal node has exactly four children. Besides, each node has two attributes:

    val: True if the node represents a grid of 1's or False if the node represents a grid of 0's. Notice that you can assign 
         the val to True or False when isLeaf is False, and both are accepted in the answer.
    isLeaf: True if the node is a leaf node on the tree or False if the node has four children.

class Node {
    public boolean val;
    public boolean isLeaf;
    public Node topLeft;
    public Node topRight;
    public Node bottomLeft;
    public Node bottomRight;
}

We can construct a Quad-Tree from a two-dimensional area using the following steps:

    If the current grid has the same value (i.e all 1's or all 0's) set isLeaf True and set val to the value of the grid and 
    set the four children to Null and stop.
    If the current grid has different values, set isLeaf to False and set val to any value and divide the current grid into 
    four sub-grids as shown in the photo.
    Recurse for each of the children with the proper sub-grid.

If you want to know more about the Quad-Tree, you can refer to the wiki.

Quad-Tree format:

You don't need to read this section for solving the problem. This is only if you want to understand the output format here. 
The output represents the serialized format of a Quad-Tree using level order traversal, where null signifies a path terminator 
where no node exists below.

It is very similar to the serialization of the binary tree. The only difference is that the node is represented as a 
list [isLeaf, val].

If the value of isLeaf or val is True we represent it as 1 in the list [isLeaf, val] and if the value of isLeaf or 
val is False we represent it as 0.
 */
