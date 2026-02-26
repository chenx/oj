class Solution2:
    def trap(self, height: List[int]) -> int:
        n = len(height)
        stack = []
        water = 0
        for i in range(n):
            if i > 0 and height[i] >= height[i-1]:
                bottom = height[stack[-1]]
                stack.pop()
                while stack and height[i] >= height[stack[-1]]:
                    ht = height[stack[-1]] - bottom
                    water += (i - stack[-1] - 1) * ht

                    bottom = height[stack[-1]]
                    stack.pop()
                if stack:
                    ht = height[i] - bottom
                    water += (i - stack[-1] - 1) * ht
            stack.append(i)
        
        return water


# if cur height < height at stack.top(): push to stack
# else: pop from stack, add waters
class Solution:
    def trap(self, height: List[int]) -> int:
        n = len(height)
        water = 0
        stack = []
        for i in range(n):
            if len(stack) > 0 and height[i] >= height[stack[-1]]:
                bottom = height[stack[-1]]
                stack.pop()
                while len(stack) > 0 and height[i] >= height[stack[-1]]:
                    ht = height[stack[-1]] - bottom
                    width = i - stack[-1] - 1
                    water += width * ht

                    bottom = height[stack[-1]]
                    stack.pop()
                if len(stack) > 0:
                    ht = height[i] - bottom
                    width = i - stack[-1] - 1
                    water += width * ht
            stack.append(i)
        return water


        

/**
42. Trapping Rain Water
Solved
Hard
Topics
conpanies iconCompanies

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
 */
