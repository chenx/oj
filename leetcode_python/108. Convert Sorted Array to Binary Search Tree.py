class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
        def convert(nums, left, right):
            if left > right:
                return None
            
            mid = left + (right - left) // 2
            root = TreeNode(nums[mid])
            root.left = convert(nums, left, mid - 1)
            root.right = convert(nums, mid + 1, right)
            return root

        return convert(nums, 0, len(nums) - 1)


/**
108. Convert Sorted Array to Binary Search Tree
Solved
Easy
Topics
conpanies iconCompanies

Given an integer array nums where the elements are sorted in ascending order, 
convert it to a binary search tree.
 */
