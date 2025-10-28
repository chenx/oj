public class Codec3 {
    StringBuilder sb;
    int pos;

    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        sb = new StringBuilder();
        ser(root);
        return sb.toString();
    }

    private void ser(TreeNode root) {
        if (root == null) {
            if (! sb.isEmpty()) {
                sb.append(" ");
            }
            sb.append("null");
            return;
        }

        if (! sb.isEmpty()) {
            sb.append(" ");
        }
        sb.append("" + root.val);
        ser(root.left);
        ser(root.right);
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        String[] values = data.split(" ");
        pos = 0;
        return des(values);
    }

    private TreeNode des(String[] values) {
        if (values[pos].equals("null")) {
            if (pos < values.length) ++ pos;
            return null;
        }
        int val = Integer.valueOf(values[pos ++]);
        TreeNode root = new TreeNode(val);
        root.left = des(values);
        root.right = des(values);
        return root;
    }
}


public class Codec2 {
    StringBuilder sb;
    int pos;

    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        sb = new StringBuilder();
        ser(root);
        return sb.toString();
    }

    private void ser(TreeNode root) {
        if (root == null) {
            if (! sb.isEmpty()) {
                sb.append(" ");
            }
            sb.append("null");
            return;
        }

        if (! sb.isEmpty()) {
            sb.append(" ");
        }
        sb.append("" + root.val);
        ser(root.left);
        ser(root.right);
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        String[] values = data.split(" ");
        pos = 0;
        return des(values);
    }

    private TreeNode des(String[] values) {
        if (values[pos].equals("null")) {
            if (pos < values.length) ++ pos;
            return null;
        }
        try {
            int val = Integer.parseInt(values[pos ++]);
            TreeNode root = new TreeNode(val);
            root.left = des(values);
            root.right = des(values);
            return root;
        } catch (NumberFormatException e) {
            System.err.println("error: " + e);
            return null;
        }
    }
}


/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Codec {

    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        String s = ser(root);
        s = "[" + s.substring(0, s.length() - 1) + "]"; // remove trailing ",", and wrap in "[]"".
        return s;
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        data = data.substring(1, data.length() - 1); // remove "[]".
        if (data.equals("") || data.equals("null")) return null;
        String[] words = data.split(",");
        
        Counter ct = new Counter(); //int pos = 0;
        return readBT(words, ct);
    }
    
    
    private String ser(TreeNode root) {
        if (null == root) return "null,";
        else return root.val + "," + ser(root.left) + ser(root.right);
    }
    
    // Use this in equivalence to passing parameter by reference in C++.
    private class Counter {
        public int pos;
        public Counter() { pos = 0; }
    }

    private TreeNode readBT(String[] words, Counter ct) {
        if (ct.pos == words.length) return null;

        String v = words[ct.pos ++];
        if (v.equals("null") || v.equals("")) return null;
        int val = toInt(v); // convert string to int.

        TreeNode root = new TreeNode(val);
        if (ct.pos < words.length) root.left = readBT(words, ct);
        if (ct.pos < words.length) root.right = readBT(words, ct);

        return root;
    }
    
    private int toInt(String v) {
        try {
            return Integer.parseInt(v);
        } catch (Exception ex) {
            return -1;
        }
    }
}

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
 
 
/** // Complete code
public class Codec {

    private class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode(int x) { val = x; }
    }

    private class Counter {
        public int p;
        public Counter() { p = 0; }
    }

    public static void main(String[] args) {
        Codec c = new Codec();
        if (args.length == 0) return;
        System.out.println("Input: " + args[0]);

        TreeNode root = c.deserialize(args[0]);
        System.out.println(c.serialize(root));
    }

    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        String s = ser(root);
        s = "[" + s.substring(0, s.length() - 1) + "]"; // remove trailing ",", and wrap in "[]"".
        return s;
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        //System.out.println("des: " + data + ", len=" + data.length());
        data = data.substring(1, data.length() - 1); // remove "[]".
        if (data.equals("") || data.equals("null")) return null;
        String[] words = data.split(",");

        Counter ct = new Counter(); //int pos = 0;
        return readBT(words, ct);
    }


    private String ser(TreeNode root) {
        if (null == root) {
            return "null,";
        }

        //return ser(root.left) + (root.val) + "," + ser(root.right);
        return root.val + "," + ser(root.left) + ser(root.right);
    }

    private TreeNode readBT(String[] words, Counter ct) {
        if (ct.p == words.length) return null;

        String v = words[ct.p ++];
        if (v.equals("null") || v.equals("")) return null;
        int val = toInt(v); // convert string to int.

        TreeNode root = new TreeNode(val);
        if (ct.p < words.length) root.left = readBT(words, ct);
        if (ct.p < words.length) root.right = readBT(words, ct);

        return root;
    }

    private int toInt(String v) {
        try {
            return Integer.parseInt(v);
        } catch (Exception ex) {
            return -1;
        }
    }
}
 */
