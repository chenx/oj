# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def flatten(self, root: Optional[TreeNode]) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        def convert(node):
            if node is None:
                return None
            if node.left is None and node.right is None:
                return node
            
            tail = None
            leftTail = convert(node.left)
            rightTail = convert(node.right)

            if leftTail and rightTail:
                tail = rightTail
                leftTail.right = node.right
                node.right = node.left
                node.left = None
            elif leftTail:
                tail = leftTail
                # leftTail.right = None  # can be ignored
                node.right = node.left
                node.left = None
            elif rightTail:
                tail = rightTail
            # else: both node.left and node.right are None. tail is also None. Just ignore.
            
            return tail

        convert(root)

/**
114. Flatten Binary Tree to Linked List
Solved
Medium
Topics
conpanies iconCompanies
Hint

Given the root of a binary tree, flatten the tree into a "linked list":

    The "linked list" should use the same TreeNode class where the right child pointer points to the 
        next node in the list and the left child pointer is always null.
    The "linked list" should be in the same order as a pre-order traversal of the binary tree.

 

Example 1:

Input: root = [1,2,5,3,4,null,6]
Output: [1,null,2,null,3,null,4,null,5,null,6]
 */
