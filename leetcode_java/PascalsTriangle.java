public class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> list = new ArrayList<List<Integer>>();
        if (numRows == 0) return list;

        List<Integer> ls = new ArrayList<Integer>();
        ls.add(1);
        list.add(ls);
        
        for (int i = 1; i < numRows; ++ i) {
            ls = new ArrayList<Integer>();
            ls.add(1);
            List<Integer> ls0 = list.get(i-1);
            for (int j = 1; j < i; ++ j) { // be careful of boundary: j < 1
                ls.add(ls0.get(j-1) + ls0.get(j));
            }
            ls.add(1);
            list.add(ls);
        }
        
        return list;
    }
}

/**
Pascal's Triangle
Difficulty: Easy

Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
 */
