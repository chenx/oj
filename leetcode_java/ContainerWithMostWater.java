public class Solution {
    public int maxArea(int[] height) {
        int area, marea = 0;
        int L = 0, R = height.length - 1;
        while (L < R) {
            int minh = Math.min(height[L], height[R]);
            area = minh * (R - L);
            if (area > marea) marea = area;
            
            if (minh == height[L]) {
                while (height[++ L] < minh) ;
            }
            else {
                while (height[-- R] < minh) ;
            }
        }
        
        return marea;
    }
}

/*
Container With Most Water
Difficulty: Medium

Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container. 
 */
