//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 1/4/2013
// @Last modified: 1/4/2013
//

// Works. Tested. Best so far.
class Solution2 {
public:
    int maxArea(vector<int>& height) {
        int L = 0, R = height.size() - 1, mArea = 0;
        
        while (L < R) {
            int h = min(height[L], height[R]);
            mArea = max(mArea, h * (R - L));
            
            if (h == height[L]) while (height[++ L] < h) ;
            else while (height[-- R] < h) ;
        }
        
        return mArea;
    }
};

class Solution {
public:
    // This is O(n). Better.
    // http://basicalgos.blogspot.com/2012/03/11-container-with-most-water.html
    int maxArea(vector<int> &height) {
        if (height.size() <= 1) return 0;
        
        int marea = 0, area, minh;
        
        for (int i = 0, j = height.size() - 1; i < j; ) {
            minh = min(height[i], height[j]);
            tmp_area = minh * (j - i);
            if (marea < tmp_area) marea = tmp_area;
            
            if (height[i] == minh) {
                // could be while (height[++ i] < minh && i < j) ; but i < j not necessary.
                while (height[++ i] < minh) ; 
            } 
            else {
                while (height[-- j] < minh) ;
            }
        }
        
        return marea;
    }
    
    // This is O(n^2). 
    int maxArea(vector<int> &height) {
        if (height.size() <= 1) return 0;
        
        int marea = 0, tmp_area;
        int len = height.size();
        
        for (int i = 0; i < len - 1; ++ i) {
            for (int j = i + 1; j < len; ++ j) {
                tmp_area = min(height[i], height[j]) * (j - i);
                marea = max(marea, tmp_area);
            }
        }
        
        return marea;
    }
};

/*
Problem:
        
Given n non-negative integers a1, a2, ..., an, where each represents a point at 
coordinate (i, ai). n vertical lines are drawn such that the two endpoints of 
line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis 
forms a container, such that the container contains the most water.

Note: You may not slant the container. 
 */
