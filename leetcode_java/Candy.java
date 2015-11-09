public class Solution {
    public int candy(int[] ratings) {
        int len = ratings.length;
        if (len == 0) return 0;
        
        int[] ct = new int[len];
        ct[0] = 1;
        for (int i = 1; i < len; ++ i) {
            if (ratings[i] > ratings[i-1]) ct[i] = ct[i-1] + 1;
            else ct[i] = 1;
        }
        
        //ct[len - 1] = Math.max(1, ct[len - 1]);
        for (int i = len - 2; i >= 0; -- i) {
            if (ratings[i] > ratings[i+1]) ct[i] = Math.max(ct[i], ct[i+1] + 1);
        }
        
        int sum = 0;
        for (int i = 0; i < len; ++ i) {
            sum += ct[i];
        }
        
        return sum;
    }
}


/**
Candy
Difficulty: Hard

There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

    Each child must have at least one candy.
    Children with a higher rating get more candies than their neighbors.

What is the minimum candies you must give? 
 */
