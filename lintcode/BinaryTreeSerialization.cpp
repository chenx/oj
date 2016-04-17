/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * This method will be invoked first, you should design your own algorithm 
     * to serialize a binary tree which denote by a root node to a string which
     * can be easily deserialized by your own "deserialize" method later.
     */
    string serialize(TreeNode *root) {
        string s;
        ser(root, s);
        return s;
    }
    
    void ser(TreeNode * root, string & s) {
        if (! root) {
            if (s != "")  s += " ";
            s += "null";
            return;
        }
        
        if (s != "")  s += " ";
        s += to_string(root->val);
        
        ser(root->left, s);
        ser(root->right, s);
    }

    /**
     * This method will be invoked second, the argument data is what exactly
     * you serialized at method "serialize", that means the data is not given by
     * system, it's given by your own serialize method. So the format of data is
     * designed by yourself, and deserialize it here as you serialize it in 
     * "serialize" method.
     */
    TreeNode *deserialize(string data) {
        stringstream ss(data);
        string w;
        vector<string> nodes;
        while (getline(ss, w, ' '))
            nodes.push_back(w);
            
        TreeNode * root = NULL;
        int pos = 0;
        des(root, nodes, pos);
        return root;
    }
    
    void des(TreeNode *& root, vector<string> & nodes, int &pos) {
        //if (pos == nodes.size() || nodes[pos] == "null") {
        if (nodes[pos] == "null") { // ok w/o pos == nodes.size().
            root = NULL;            // since data always ends with "null".
            ++ pos; // don't forget this!
            return;
        }
        
        root = new TreeNode(stoi(nodes[pos ++]));
        des(root->left, nodes, pos);
        des(root->right, nodes, pos);
    }
};


/**
Binary Tree Serialization

Design an algorithm and write code to serialize and deserialize a binary tree. 
Writing the tree to a file is called 'serialization' and reading back from the 
file to reconstruct the exact same binary tree is 'deserialization'.

There is no limit of how you deserialize or serialize a binary tree, you only 
need to make sure you can serialize a binary tree to a string and deserialize 
this string to the original structure.

Example

An example of testdata: Binary tree {3,9,20,#,#,15,7}, denote the following structure:

  3
 / \
9  20
  /  \
 15   7

Our data serialization use bfs traversal. This is just for when you got wrong 
answer and want to debug the input.

You can use other method to do serializaiton and deserialization.

 */
