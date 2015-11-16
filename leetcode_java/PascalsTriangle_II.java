// O(k) space
public class Solution {
    public List<Integer> getRow(int rowIndex) {
        List<Integer> list = new ArrayList<Integer>();
        list.add(1);
        if (rowIndex <= 0) return list;
        
        for (int i = 1; i <= rowIndex; ++ i) {
            list.add(1);
            for (int j = i - 1; j >= 1; -- j) {
                list.set(j, list.get(j) + list.get(j-1));
            }
        }
        
        return list;
    }
}

/**
Pascal's Triangle II
Difficulty: Easy

Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space? 
 */
