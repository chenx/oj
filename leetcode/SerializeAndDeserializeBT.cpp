// Works. Improved from Codec. More clean.
class Codec2 {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        ser(root, s);
        return s;
    }
    
    void ser(TreeNode * root, string &s) {
        if (! root) {
            //s += (s == "" ? "" : "," + "null"; // does not compile
            s += (s == "" ? "null" : ",null");
            return;
        }
        
        s += (s == "" ? "" : ",") + to_string(root->val);
        ser(root->left, s);
        ser(root->right, s);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode * root;
        
        vector<string> vals;
        split(data, vals, ',');
        
        int p = 0;
        des(root, vals, p);
        return root;
    }
    
    void des(TreeNode *& root, vector<string> &vals, int &p) {
        if (p == vals.size() || vals[p] == "null") {
            root = NULL;
            ++ p;
            return;
        }
        
        root = new TreeNode(stoi(vals[p++]));
        des(root->left, vals, p);
        des(root->right, vals, p);
    }
    
    // Note how split is defined!
    void split(string data, vector<string> &vals, char delim) {
        stringstream ss(data);
        string val;
        while (getline(ss, val, delim)) {
            vals.push_back(val);
        }
    }
};


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        ser(root, s);
        s = "[" + s.substr(0, s.length() - 1) + "]"; // remove trailing ",", and wrap in "[]"".
        return s;
    }
    
    void ser(TreeNode * root, string &s) {
        if (! root) {
            s += "null,";
            return;
        }
        
        s += to_string(root->val) + ",";
        ser(root->left, s);
        ser(root->right, s);        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode * root;
        vector<string> words;
        
        data = data.substr(1, data.length() - 2); // remove "[]".
        if (data == "" || data == "null") return NULL;
        split(data, ',', words);
        
        int pos = 0;
        readBT(root, words, pos);
        return root;
    }
    
    void readBT(TreeNode *& root, vector<string> &words, int & p) {
        if (p == words.size()) {
            root = NULL;
            return;
        }
        
        string v = words[p ++];
        if (v == "null" || v == "") {
            root = NULL;
            return;
        }
        
        int val = atoi(v.c_str()); // convert string to int.
        
        root = new TreeNode(val);
        readBT(root->left, words, p);
        readBT(root->right, words, p);
    }
    
    vector<string> &split(const string &s, char delim, vector<string> &elems) 
    {
        stringstream ss(s);
        string item;
        while(getline(ss, item, delim)) 
        {
            elems.push_back(item);
        }
        return elems;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec; 
// codec.deserialize(codec.serialize(root));

/**
Serialize and Deserialize Binary Tree
Difficulty: Medium

Serialization is the process of converting a data structure or object into 
a sequence of bits so that it can be stored in a file or memory buffer, or 
transmitted across a network connection link to be reconstructed later in 
the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is 
no restriction on how your serialization/deserialization algorithm should 
work. You just need to ensure that a binary tree can be serialized to a 
string and this string can be deserialized to the original tree structure.

For example, you may serialize the following tree

    1
   / \
  2   3
     / \
    4   5

as "[1,2,3,null,null,4,5]", just the same as how LeetCode OJ serializes a 
binary tree. You do not necessarily need to follow this format, so please 
be creative and come up with different approaches yourself.

Note: Do not use class member/global/static variables to store states. Your 
serialize and deserialize algorithms should be stateless. 
 */
 
 
/** // Complete code.
 
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        ser(root, s);
        s = "[" + s.substr(0, s.length() - 1) + "]";
        return s;
    }

    void ser(TreeNode * root, string &s) {
        if (! root) {
            s += "null,";
            return;
        }

        s += to_string(root->val) + ",";
        if (root->left) ser(root->left, s);
        if (root->right) ser(root->right, s);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode * root;
        vector<string> words;

        data = data.substr(1, data.length() - 2);
        if (data == "" || data == "null") return NULL;

        split(data, ',', words);

        int pos = 0;
        readBT(root, words, pos);
        return root;
    }

    void readBT(TreeNode *& root, vector<string> &words, int & p) {
        if (p == words.size()) {
            root = NULL;
            return;
        }

        string v = words[p ++];
        if (v == "null" || v == "") {
            root = NULL;
            return;
        }

        int val = atoi(v.c_str()); // NOTE: convert string to int.

        root = new TreeNode(val);
        readBT(root->left, words, p);
        readBT(root->right, words, p);
    }

    vector<string> &split(const string &s, char delim, vector<string> &elems)
    {
        stringstream ss(s);
        string item;
        while(getline(ss, item, delim))
        {
            elems.push_back(item);
        }
        return elems;
    }

    string to_string(int v) {
        stringstream ss;
        ss << v;
        return ss.str();
    }
};


int main() {
    Codec c;

    TreeNode * root = c.deserialize("[1]"); // or "[]", or "[null]"
    cout << (root == NULL ? "null" : "not null") << endl;
    cout << c.serialize(root) << endl;

    return 0;
}

  */
