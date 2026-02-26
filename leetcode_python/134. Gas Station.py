class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        n = len(gas)
        if n == 0:
            return 0

        total = 0
        sum = 0
        start = 0

        for i in range(n):
            diff = gas[i] - cost[i]
            total += diff
            if sum < 0:
                sum = 0
                start = i
            sum += diff
        
        if total < 0: return -1
        return start

/**
134. Gas Station
Solved
Medium
Topics
conpanies iconCompanies

There are n gas stations along a circular route, where the amount of gas at the ith station is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from the ith station to 
its next (i + 1)th station. You begin the journey with an empty tank at one of the gas stations.

Given two integer arrays gas and cost, return the starting gas station's index if you can travel around 
the circuit once in the clockwise direction, otherwise return -1. If there exists a solution, it is 
guaranteed to be unique.

 

Example 1:

Input: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
Output: 3
 */
