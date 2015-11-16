// O(N) space.
public class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        int len = triangle.size();
        if (len == 0) return 0;
        
        List<Integer> list = new ArrayList<Integer>();
        
        List<Integer> row = triangle.get(len - 1);
        for (int i = 0, rowLen = row.size(); i < rowLen; ++ i) {
            list.add(row.get(i));
        }
        
        for (int i = len - 2; i >= 0; -- i) {
            row = triangle.get(i);
            for (int j = 0; j < row.size(); ++ j) {
                list.set(j, row.get(j) + Math.min(list.get(j), list.get(j + 1)));
            }
        }
        
        return list.get(0);
    }
}

/**
Triangle
Difficulty: Medium

Given a triangle, find the minimum path sum from top to bottom. 
Each step you may move to adjacent numbers on the row below.

For example, given the following triangle

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]

The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space, 
where n is the total number of rows in the triangle. 
 */
