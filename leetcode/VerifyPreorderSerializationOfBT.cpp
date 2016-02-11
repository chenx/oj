// Works. From: https://leetcode.com/discuss/85460/c-using-counter
// Why?
class Solution2 {
public:
    bool isValidSerialization(string preorder) {
        replace(preorder.begin(),preorder.end(),',',' ');
        stringstream ss(preorder);
        string value;
        int nbTreeToRead = 1;
        while(ss >> value)
        {
            if (nbTreeToRead == 0) return false;
            if (value == "#") nbTreeToRead --;
            else nbTreeToRead++;
        }
        return (nbTreeToRead == 0);
    }
};

// works. why?
// From: https://leetcode.com/discuss/85616/11-lines-concise-and-easy-understand-c-solution
class Solution {
public:
    bool isValidSerialization(string preorder) {
        int nullcnt = 0, nodecnt = 0;
        string tmp;
        vector<string> vec;

        istringstream iss(preorder);
        while(getline(iss, tmp, ',')) vec.push_back(tmp);

        for(int i = 0; i < vec.size(); i++){
            if(vec[i] != "#") nodecnt++;
            else nullcnt++;
            if(nullcnt == nodecnt + 1 && i != vec.size() - 1) return false;
        }
        
        return nullcnt == nodecnt + 1;
    }
};

/**
Verify Preorder Serialization of a Binary Tree
Difficulty: Medium

One way to serialize a binary tree is to use pre-order traversal. 
When we encounter a non-null node, we record the node's value. 
If it is a null node, we record using a sentinel value such as #.

     _9_
    /   \
   3     2
  / \   / \
 4   1  #  6
/ \ / \   / \
# # # #   # #

For example, the above binary tree can be serialized to the 
string "9,3,4,#,#,1,#,#,2,#,6,#,#", where # represents a null node.

Given a string of comma separated values, verify whether it is a 
correct preorder traversal serialization of a binary tree. 
Find an algorithm without reconstructing the tree.

Each comma separated value in the string must be either an integer 
or a character '#' representing null pointer.

You may assume that the input format is always valid, for example 
it could never contain two consecutive commas such as "1,,3".

Example 1:
"9,3,4,#,#,1,#,#,2,#,6,#,#"
Return true

Example 2:
"1,#"
Return false

Example 3:
"9,#,#,1"
Return false
 */
