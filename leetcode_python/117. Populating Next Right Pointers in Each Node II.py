"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""

# Level order traversal
class Solution3:
    def connect(self, root: 'Node') -> 'Node':
        if not root:
            return None
        
        q = collections.deque()
        q.append(root)

        while len(q) > 0:
            count = len(q)
            for i in range(count):
                node = q.popleft()
                node.next = q[0] if i < count - 1 else None

                if node.left: q.append(node.left)
                if node.right: q.append(node.right)

        return root


# Level order traversal
class Solution2:
    def connect(self, root: 'Node') -> 'Node':
        if not root:
            return None
        
        q = collections.deque()
        q.append(root)

        while len(q) > 0:
            count = len(q)
            prev = None
            for i in range(count):
                node = q.popleft()

                if node.left: q.append(node.left)
                if node.right: q.append(node.right)

                if prev: prev.next = node
                # if i == count - 1: node.next = None # optional, since node.next is None by default
                prev = node

        return root


class Solution:
    def connect(self, root: 'Node') -> 'Node':
        def getNext(node):
            if not node: 
                return None
            if node.left: return node.left
            if node.right: return node.right
            return getNext(node.next)

        def conn(root, next):
            if not root: 
                return None
            root.next = next
            root.right = conn(root.right, getNext(next))
            root.left = conn(root.left, root.right if root.right else getNext(next))
            return root

        return conn(root, None)

/**
117. Populating Next Right Pointers in Each Node II
Solved
Medium
Topics
conpanies iconCompanies

Given a binary tree

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}

Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.
 */
