// C++ version translated from Java does not work yet.
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
ser: result = 1#2345#$67$8$9:#$;$<$=$#>$$$#$#
des: data = 1#2345#$67$8$9:#$;$<$=$#>$$$#$#
*/

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(Node* root) {
        if (root == NULL) {
            return "";
        }
        
        string s;
        ser(root, s);
        return s;
    }

    void ser(Node* root, string& s) {
        // Queue to perform a level order traversal of the tree
        queue<Node*> q;
        
        // Two dummy nodes that will help us in serialization string formation.
        // We insert the "endNode" whenever a level ends and the "childNode"
        // whenever a node's children are added to the queue and we are about
        // to switch over to the next node.
        Node* endNode = new Node();
        Node* childNode = new Node();
        q.push(root);
        q.push(endNode);
        
        while (!q.empty()) {
            Node* node = q.front();
            q.pop();
            
            // If this is an "endNode", we need to add another one to mark the end of 
            // the current level unless this was the last level.
            if (node == endNode) { // We add a sentinal value of "#" here
                s += "#";
                if (!q.empty()) {
                    q.push(endNode);  
                }
            } else if (node == childNode) {
                // Add a sentinal value of "$" here to mark the switch to a different parent.
                s += "$";
            } else {
                // Add value of the current node and add all of it's
                // children nodes to the queue. Note how we convert
                // the integers to their corresponding ASCII counterparts.
                // cout << "### ser: node->val = " << node->val << ", in char:" << ((char)(node->val + '0'))  << endl;
                s += (char)(node->val + '0');
                if (node->val >= 100) cout << "node->val = " << node->val << endl;
                for (auto child : node->children) {
                    q.push(child);
                }
                
                // If this is NOT the last one on the current level, add a childNode as well 
                // since we move on to processing the next node.
                if (q.front() != endNode) {
                    q.push(childNode);
                }
            }
        }
    }
	
    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        if (data.empty()) {
            return NULL;
        }
            
        Node* rootNode = new Node(data[0] - '0');
        cout << "deserialize.0" << endl;
        des(data, rootNode);
        cout << "deserialize end" << endl;
        return rootNode;
    }
    
    void des(string& data, Node* rootNode) {  
        // We move one level at a time and at every level, we need access
        // to the nodes on the previous level as well so that we can form
        // the children arrays properly. Hence two arrays.
        queue<Node*> currentLevel;
        queue<Node*> prevLevel;
        currentLevel.push(rootNode);
        Node* parentNode = rootNode;

        cout << "deserialize.1. data =" << data << endl;
        cout << "deserialize.1. data.length()=" << data.length() << endl;

        // Process the characters in the string one at a time.
        for (int i = 1; i < data.length(); i++) {
            char d = data[i];
            // if (i >= 450)
            // cout << "deserialize: i=" << i << ", data[i]=" << d << endl;
            if (d == '#') {
                // Special processing for end of level. We need to swap the
                // array lists. Here, we simply re-initialize the "currentLevel"
                // arraylist rather than clearing it.
                cout << "deserialize.2" << endl;
                cout << "prevLevel.size = " << prevLevel.size() << ", currentLevel.size = " << currentLevel.size() << endl;
                prevLevel = currentLevel;
                cout << "deserialize.3. prevLevelp.size=" << prevLevel.size() << endl;
                queue<Node*> x;
                currentLevel = x; //queue<Node*>();

                cout << "deserialize.4: prevLevel.size = " << prevLevel.size() << endl;
                
                // Since we move one level down, we take the parent as the first
                // node on the current level.
                parentNode = prevLevel.front();
                prevLevel.pop();
            } else {
                if (d == '$') { // Special handling for change in parent on the same level
                    cout << "deserialize.5: prevLevel.size = " << prevLevel.size() << endl;
                    // if (! prevLevel.empty()) 
                    {
                        parentNode = prevLevel.front();
                        prevLevel.pop();
                    }
                    // cout << "deserialize.5.2: parentNode: " << parentNode->val << endl;
                } else {
                    cout << "deserialize.6" << endl;
                    Node* childNode = new Node((int) (d - '0'));    
                    currentLevel.push(childNode);
                    parentNode->children.push_back(childNode);
                }
            }
        }
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));


// Java version. Works. But C++ version does not.
class Codec {
    // Encodes a tree to a single string.
    public String serialize(Node root) {
        
        if (root == null) {
            return "";
        }
        
        StringBuilder sb = new StringBuilder();
        this._serializeHelper(root, sb);

        System.out.println("ser: result = " + sb.toString());
        return sb.toString();
    }
    
    private void _serializeHelper(Node root, StringBuilder sb) {
        
        // Queue to perform a level order traversal of the tree
        Queue<Node> q = new LinkedList<Node>();
        
        // Two dummy nodes that will help us in serialization string formation.
        // We insert the "endNode" whenever a level ends and the "childNode"
        // whenever a node's children are added to the queue and we are about
        // to switch over to the next node.
        Node endNode = new Node();
        Node childNode = new Node();
        q.add(root);
        q.add(endNode);
        
        while (!q.isEmpty()) {
            
            // Pop a node
            Node node = q.poll();
            
            // If this is an "endNode", we need to add another one
            // to mark the end of the current level unless this
            // was the last level.
            if (node == endNode) {
                
                // We add a sentinal value of "#" here
                sb.append('#');
                if (!q.isEmpty()) {
                    q.add(endNode);  
                }
            } else if (node == childNode) {
                
                // Add a sentinal value of "$" here to mark the switch to a
                // different parent.
                sb.append('$');
            } else {
                
                // Add value of the current node and add all of it's
                // children nodes to the queue. Note how we convert
                // the integers to their corresponding ASCII counterparts.
                sb.append((char) (node.val + '0'));
                for (Node child : node.children) {
                    q.add(child);
                }
                
                // If this not is NOT the last one on the current level, 
                // add a childNode as well since we move on to processing
                // the next node.
                if (q.peek() != endNode) {
                    q.add(childNode);
                }
            }
        }
    }

    // Decodes your encoded data to tree.
    public Node deserialize(String data) {
        if (data.isEmpty()) {
            return null;
        }

        System.out.println("des: data = " + data);
            
        Node rootNode = new Node(data.charAt(0) - '0', new ArrayList<Node>());
        this._deserializeHelper(data, rootNode);
        return rootNode;
    }
    
    private void _deserializeHelper(String data, Node rootNode) {  
        
        // We move one level at a time and at every level, we need access
        // to the nodes on the previous level as well so that we can form
        // the children arrays properly. Hence two arrays.
        LinkedList<Node> currentLevel = new LinkedList<Node>();
        LinkedList<Node> prevLevel = new LinkedList<Node>();
        currentLevel.add(rootNode);
        Node parentNode = rootNode;
        
        // Process the characters in the string one at a time.
        for (int i = 1; i < data.length(); i++) {
            char d = data.charAt(i);
            if (d == '#') {
                // Special processing for end of level. We need to swap the
                // array lists. Here, we simply re-initialize the "currentLevel"
                // arraylist rather than clearing it.
                prevLevel = currentLevel;
                currentLevel = new LinkedList<Node>();
                
                // Since we move one level down, we take the parent as the first
                // node on the current level.
                parentNode = prevLevel.poll();
            } else {
                if (d == '$') {
                    
                    // Special handling for change in parent on the same level
                    parentNode = prevLevel.poll();
                } else {
                    Node childNode = new Node(d - '0', new ArrayList<Node>());    
                    currentLevel.add(childNode);
                    parentNode.children.add(childNode);
                }
            }
        }
    }
}


/**
428. Serialize and Deserialize N-ary Tree
Hard

Serialization is the process of converting a data structure or object into a sequence of bits so that 
it can be stored in a file or memory buffer, or transmitted across a network connection link to be 
reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize an N-ary tree. An N-ary tree is a rooted tree in which 
each node has no more than N children. There is no restriction on how your serialization/deserialization 
algorithm should work. You just need to ensure that an N-ary tree can be serialized to a string and this 
string can be deserialized to the original tree structure.

For example, you may serialize the following 3-ary tree

 

as [1 [3[5 6] 2 4]]. Note that this is just an example, you do not necessarily need to follow this format.

Or you can follow LeetCode's level order traversal serialization format, where each group of children is 
separated by the null value.

 

For example, the above tree may be serialized as 
[1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14].

You do not necessarily need to follow the above-suggested formats, there are many more different formats 
that work so please be creative and come up with different approaches yourself.

 

Example 1:

Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
Output: [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]

Example 2:

Input: root = [1,null,3,2,4,null,5,6]
Output: [1,null,3,2,4,null,5,6]

Example 3:

Input: root = []
Output: []
 */
