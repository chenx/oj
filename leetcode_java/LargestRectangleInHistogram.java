public class Solution {
    public int largestRectangleArea(int[] height) {
        ArrayList<Integer> h = new ArrayList<Integer>();
        for (int i = 0, n = height.length; i < n; ++ i) h.add(height[i]);
        h.add(0);
        
        Stack<Integer> s = new Stack<Integer>();
        int i = 0, n = h.size(), marea = 0;
        while (i < n) {
            if (s.isEmpty() || h.get(i) >= h.get(s.peek())) {
                s.push(i ++);
            }
            else {
                int ht = h.get(s.peek());
                s.pop();
                int area = ht * (s.isEmpty() ? i : i - s.peek() - 1);
                marea = Math.max(area, marea);
            }
        }
        
        return marea;
    }
}

/**
Largest Rectangle in Histogram
Difficulty: Hard

Given n non-negative integers representing the histogram's bar height where 
the width of each bar is 1, find the area of largest rectangle in the histogram.


Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].


The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given height = [2,1,5,6,2,3],
return 10. 
 */
