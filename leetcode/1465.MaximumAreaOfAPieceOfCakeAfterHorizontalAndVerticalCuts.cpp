// From: https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/editorial
// Time complexity: O(N⋅log(N)+M⋅log(M))
// Space: O(1)
class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        int m = horizontalCuts.size(), n = verticalCuts.size();
        
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());

        int maxH = max(horizontalCuts[0], h - horizontalCuts[m-1]);
        for (int i = 1; i < m; ++ i) {
            maxH = max(maxH, horizontalCuts[i] - horizontalCuts[i-1]);
        }
        int maxW = max(verticalCuts[0], w - verticalCuts[n-1]);
        for (int i = 1; i < n; ++ i) {
            maxW = max(maxW, verticalCuts[i] - verticalCuts[i-1]);
        }

        return (int) ((long long) maxH * maxW % 1000000007);
    }
};

/**
1465. Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts
Medium

You are given a rectangular cake of size h x w and two arrays of integers horizontalCuts and verticalCuts where:

    horizontalCuts[i] is the distance from the top of the rectangular cake to the ith horizontal cut and similarly, and
    verticalCuts[j] is the distance from the left of the rectangular cake to the jth vertical cut.

Return the maximum area of a piece of cake after you cut at each horizontal and vertical position provided 
in the arrays horizontalCuts and verticalCuts. Since the answer can be a large number, return this modulo 109 + 7.
 */
