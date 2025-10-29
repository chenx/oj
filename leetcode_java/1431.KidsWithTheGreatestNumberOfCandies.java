class Solution {
    public List<Boolean> kidsWithCandies(int[] candies, int extraCandies) {
        List<Boolean> ans = new ArrayList<Boolean>();
        int n = candies.length;
        if (n == 0) return ans;

        int maxVal = candies[0];
        for (int i = 1; i < n; ++ i) {
            if (maxVal < candies[i]) maxVal = candies[i];
        }

        for (int i = 0; i < n; ++ i) {
            ans.add(candies[i] + extraCandies >= maxVal ? true : false);
        }
        return ans;
    }
}

/**
1431. Kids With the Greatest Number of Candies
Easy

There are n kids with candies. You are given an integer array candies, where each candies[i] represents the number 
of candies the ith kid has, and an integer extraCandies, denoting the number of extra candies that you have.

Return a boolean array result of length n, where result[i] is true if, after giving the ith kid all the extraCandies, 
they will have the greatest number of candies among all the kids, or false otherwise.

Note that multiple kids can have the greatest number of candies.


Example 1:

Input: candies = [2,3,5,1,3], extraCandies = 3
Output: [true,true,true,false,true] 
 */
