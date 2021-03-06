// See: https://leetcode.com/discuss/66048/5ms-java-in-a-readable
public class Solution {
    public int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area1 = (C-A) * (D-B);
        int area2 = (G-E) * (H-F);
        int overlap = overlapArea(A, B, C, D, E, F, G, H);
        return area1 + area2 - overlap;
    }
    
    private int overlapArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int bottomX = Math.max(A, E); 
        int bottomY = Math.max(B, F);
        int topX = Math.min(C,G);
        int topY = Math.min(D,H);
    
        int overlap = 0; 
        if(topX > bottomX && topY > bottomY) { 
            overlap = (topX - bottomX) * (topY - bottomY);   
        } 
        return overlap; 
    }
    
}


/**
Rectangle Area
Difficulty: Easy

Find the total area covered by two rectilinear rectangles in a 2D plane.

Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.

(A, B) is for x, y coordinates of left bottom corner of the first rectangle.
(C, D) is for x, y coordinates of upper right corner of the first rectangle.

(E, F) is for x, y coordinates of left bottom corner of the second rectangle.
(G, I) is for x, y coordinates of upper right corner of the second rectangle.

Assume that the total area is never beyond the maximum possible value of int.

 */
