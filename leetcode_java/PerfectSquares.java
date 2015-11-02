public class Solution {
    public int numSquares(int n) {
        if (n <= 0) return 0;

        List<Integer> coinsList = new ArrayList<Integer>(); // Use ArrayList<Integer> coinsList also works.
        for (int i = 1; i * i <= n; ++ i) {
            coinsList.add(i * i);
        }
        Integer[] coins = coinsList.toArray(new Integer[coinsList.size()]);
        
        int[] ans = new int[n+1];
        for (int i = 1; i <= n; ++ i) {
            ans[i] = i;
            for (int j = 0, lenj = coins.length; j < lenj; ++ j) {
                if (i == coins[j]) {
                    ans[i] = 1;
                    break;
                }
                else if (i > coins[j]) {
                    if (ans[i - coins[j]] > 0) {
                        ans[i] = Math.min(ans[i], 1 + ans[i - coins[j]]);
                    }
                }
            }
        }
        
        return ans[n];
    }
}


/**
Perfect Squares
Difficulty: Medium

Given a positive integer n, find the least number of perfect square numbers 
(for example, 1, 4, 9, 16, ...) which sum to n.

For example, given n = 12, return 3 because 12 = 4 + 4 + 4; 
given n = 13, return 2 because 13 = 4 + 9. 
 */
