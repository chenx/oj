class Solution2:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        def inorder(node):
            nonlocal k, kthSmallestVal
            if node == None:
                return
            
            inorder(node.left)
            k -= 1
            if k == 0:
                kthSmallestVal = node.val
                return
            inorder(node.right)

        kthSmallestVal = 0  # it's ok without this
        inorder(root)
        return kthSmallestVal


class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        def inorder(node):
            if node is None:  # ok to use: "node == None", or "not node != None"
                return
            
            inorder(node.left)
            self.k -= 1
            if (self.k == 0):
                self.kthSmallestVal = node.val
                return
            inorder(node.right)

        self.k = k
        self.kthSmallestVal = 0  # it's ok without this line
        inorder(root)
        return self.kthSmallestVal


/**
230. Kth Smallest Element in a BST
Medium

Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of 
all the values of the nodes in the tree.

 

Example 1:

Input: root = [3,1,4,null,2], k = 1
Output: 1
 */
