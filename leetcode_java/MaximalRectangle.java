// This should work. But times out for large input.
public class Solution {
    public int maximalRectangle(char[][] matrix) {
        if (matrix.length == 0 || matrix[0].length == 0) return 0;
        int rows = matrix.length, cols = matrix[0].length;
        int marea = 0;
        int[] v = new int[cols + 1];
        v[cols] = 0;
        
        for (int i = 0; i < rows; ++ i) {
            for (int k = 0; k < cols; ++ k) v[k] = matrix[i][k] == '1' ? 1 : 0;
            marea = Math.max(marea, hist(v));
            
            for (int j = i + 1; j < rows; ++ j) {
                for (int k = 0; k < cols; ++ k) {
                    v[k] = (matrix[j][k] == '1') ? v[k] + 1 : 0;
                }
                marea = Math.max(marea, hist(v));
            }
        }
        return marea;
    }
    
    int hist(int[] height) {
        //height.push_back(0);
        int i = 0, len = height.length, area, marea = 0;
        Stack<Integer> h = new Stack<Integer>();

        while (i < len) {
            if (h.empty() || height[i] >= height[h.peek()]) {
                h.push(i);
                ++ i;
            }
            else {
                int ht = height[h.peek()];
                h.pop();
                marea = Math.max(marea, ht * (h.empty() ? i : i - 1 - h.peek()));
            }
        }
        
        return marea;        
    }
}

/**
Maximal Rectangle
Difficulty: Hard

Given a 2D binary matrix filled with 0's and 1's, 
find the largest rectangle containing all ones and return its area.
 */
