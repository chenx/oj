class Solution2:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
        def build(inorder, postorder, pi, li, ri):
            if li > ri:
                return None
            
            root = TreeNode(postorder[pi])
            mi = indexValueMap[postorder[pi]]
            root.left = build(inorder, postorder, pi - 1 - (ri - mi), li, mi - 1)
            root.right = build(inorder, postorder, pi - 1, mi + 1, ri)
            return root

        indexValueMap = {}
        for index, val in enumerate(inorder):
            indexValueMap[val] = index
        n = len(inorder)
        return build(inorder, postorder, n-1, 0, n-1)


class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
        def build(postorder, inorder, pi, li, ri):
            if li > ri:
                return None
            
            root = TreeNode(postorder[pi])
            mi = self.inorderIndexMap[postorder[pi]]
            root.left = build(postorder, inorder, pi - (ri - mi) - 1, li, mi - 1)
            root.right = build(postorder, inorder, pi - 1, mi + 1, ri)
            return root

        n = len(inorder)
        self.inorderIndexMap = {}
        for i in range(n):
            self.inorderIndexMap[inorder[i]] = i

        return build(postorder, inorder, n-1, 0, n - 1)

/**
106. Construct Binary Tree from Inorder and Postorder Traversal
Solved
Medium
Topics
conpanies iconCompanies

Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree 
and postorder is the postorder traversal of the same tree, construct and return the binary tree.
 */
