# DP. Time: O(n), Space: O(1)
class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        oneStep = 0
        twoStep = 0
        for i in range(2, len(cost) + 1):
            tmp = oneStep
            oneStep = min(oneStep + cost[i-1], twoStep + cost[i-2])
            twoStep = tmp
        return oneStep

/**
746. Min Cost Climbing Stairs
Solved
Easy
Topics
conpanies iconCompanies
Hint

You are given an integer array cost where cost[i] is the cost of ith step on a staircase. 
Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the floor.
 */
