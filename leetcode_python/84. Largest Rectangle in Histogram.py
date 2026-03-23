# Time: O(n)
# Space: O(n)
class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        heights.append(0)
        stack = []
        maxArea = 0
        i = 0
        while i < len(heights):
            if len(stack) == 0 or heights[i] >= heights[stack[-1]]:
                stack.append(i)
                i += 1
            else:
                ht = heights[stack[-1]]
                stack.pop()
                width = i if len(stack) == 0 else i - stack[-1] - 1
                maxArea = max(maxArea, ht * width)
        return maxArea


/**
84. Largest Rectangle in Histogram
Solved
Hard
Topics
conpanies iconCompanies

Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, 
return the area of the largest rectangle in the histogram.

 

Example 1:

Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.

Example 2:

Input: heights = [2,4]
Output: 4
 */
