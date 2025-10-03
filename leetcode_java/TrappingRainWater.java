class Solution {
    public int trap(int[] height) {
        int len = height.length, water = 0;
        
        Stack<Integer> stack = new Stack<>();
        for (int i = 0; i < len; ++ i) {
            if (stack.isEmpty() || height[i] <= height[stack.peek()]) {
                stack.push(i);
            } else {
                int bottom = height[stack.peek()];
                stack.pop();
                while (!stack.isEmpty() && height[stack.peek()] <= height[i]) {
                    int width = i - stack.peek() - 1;
                    water += width * (height[stack.peek()] - bottom);
                    
                    bottom = height[stack.peek()];
                    stack.pop();
                }
                if (!stack.isEmpty()) {
                    int width = i - stack.peek() - 1;
                    water += width * (height[i] - bottom);
                }
                stack.push(i);
            }
        }
        return water;
    }
}

/**
Trapping Rain Water

Given n non-negative integers representing an elevation map where the width of each bar is 1, 
compute how much water it can trap after raining.
 */
