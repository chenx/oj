class Solution:
    def candy(self, ratings: List[int]) -> int:
        n = len(ratings)
        if n == 0:
            return 0

        DP = [1] * n
        for i in range(1, n):
            if ratings[i] > ratings[i-1]:
                DP[i] = 1 + DP[i-1]
        
        for i in range(n-2, -1, -1):
            if ratings[i] > ratings[i+1]:
                DP[i] = max(DP[i], 1 + DP[i+1])

        return sum(DP) # note: sum() function adds up all elements in the array !!!

/**
135. Candy
Solved
Hard
Topics
conpanies iconCompanies

There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.

You are giving candies to these children subjected to the following requirements:

    Each child must have at least one candy.
    Children with a higher rating get more candies than their neighbors.

Return the minimum number of candies you need to have to distribute the candies to the children.
 */
