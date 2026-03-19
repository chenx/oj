# Level order traversal
# Time, Space: O(n)
# [1,2,3,null,null,4,5] =>
# serialize result: 1 2 3 null null 4 5
from collections import deque
class Codec4:

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        tokens = []
        q = deque([root])

        while q:
            node = q.popleft()
            if node:
                tokens.append(str(node.val))
                q.append(node.left)
                q.append(node.right)
            else:
                tokens.append('null')
            
        while tokens and tokens[-1] == 'null':
            tokens.pop()

        result = ' '.join(tokens)
        print(f"serialize result: {result}")
        return result
        

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        if data == '':
            return None

        tokens = data.split()
        root = TreeNode(int(tokens[0]))
        q = deque([root])
        i, n = 1, len(tokens)
        while q:
            node = q.popleft()
            if i < n and tokens[i] != 'null':
                node.left = TreeNode(int(tokens[i]))
                q.append(node.left)
            i += 1
            if i < n and tokens[i] != 'null':
                node.right = TreeNode(int(tokens[i]))
                q.append(node.right)
            i += 1

        return root


# Level order traversal
# [1,2,3,null,null,4,5] =>
# serialize result: 1 2 3 null null 4 5 null null null null
# However there are extra "null" at the end. To avoid this, see Codec4 above.
from collections import deque
class Codec3:

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        tokens = []
        q = deque([root])

        while q:
            node = q.popleft()
            if node:
                tokens.append(str(node.val))
                q.append(node.left)
                q.append(node.right)
            else:
                tokens.append('null')

        result = ' '.join(tokens)
        print(f"serialize result: {result}")
        return result
        

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        tokens = data.split()
        if tokens[0] == 'null':
            return None

        root = TreeNode(int(tokens[0]))
        q = deque([root])
        i = 1
        while q:
            node = q.popleft()
            if tokens[i] != 'null':
                node.left = TreeNode(int(tokens[i]))
                q.append(node.left)
            i += 1
            if tokens[i] != 'null':
                node.right = TreeNode(int(tokens[i]))
                q.append(node.right)
            i += 1

        return root


# DFS. Use tokens[] list instead of string.
# Time, Space: O(n)
# Time: O(n)
# Space: O(n)
class Codec2:
    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        def dfs(node):
            if node is None:
                tokens.append('null')
                return
            
            tokens.append(str(node.val))
            dfs(node.left)
            dfs(node.right)

        tokens = []
        dfs(root)
        result = ' '.join(tokens)
        print(f"serialize result: {result}")
        return result
        

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        def dfs():
            nonlocal pos
            if tokens[pos] == 'null':
                if pos < len(tokens):
                    pos += 1
                return None
            
            node = TreeNode(int(tokens[pos]))
            pos += 1
            node.left = dfs()
            node.right = dfs()
            return node

        pos = 0
        tokens = data.split()
        return dfs()


# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Codec:
    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        def dfs(node):
            nonlocal result
            if node is None:
                if result != '':
                    result += ' '
                result += 'null'
                return
            
            if result != '':
                result += ' '
            result += str(node.val)
            dfs(node.left)
            dfs(node.right)

        result = ''
        dfs(root)
        print(f"serialize result: {result}")
        return result
        

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        def dfs():
            nonlocal pos
            if tokens[pos] == 'null':
                if pos < len(tokens):
                    pos += 1
                return None
            
            node = TreeNode(int(tokens[pos]))
            pos += 1
            node.left = dfs()
            node.right = dfs()
            return node

        pos = 0
        tokens = data.split()
        return dfs()
        

# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# ans = deser.deserialize(ser.serialize(root))

/**
297. Serialize and Deserialize Binary Tree
Solved
Hard
Topics
conpanies iconCompanies

Serialization is the process of converting a data structure or object into a sequence of bits so that 
it can be stored in a file or memory buffer, or transmitted across a network connection link to be 
reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your 
serialization/deserialization algorithm should work. You just need to ensure that a binary tree can 
be serialized to a string and this string can be deserialized to the original tree structure.

Clarification: The input/output format is the same as how LeetCode serializes a binary tree. You do 
not necessarily need to follow this format, so please be creative and come up with different approaches yourself.
 */
