class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        n = len(temperatures)
        hottest = - sys.maxsize - 1
        result = [0] * n

        for i in range(n-1, -1, -1):
            if temperatures[i] >= hottest:
                hottest = temperatures[i]
                result[i] = 0
            else:
                days = 1
                while temperatures[i] >= temperatures[i + days]:
                    days += result[i + days]
                result[i] = days
        return result


/**
739. Daily Temperatures
Solved
Medium
Topics
conpanies iconCompanies
Hint

Given an array of integers temperatures represents the daily temperatures, return an array answer such that 
answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is 
no future day for which this is possible, keep answer[i] == 0 instead.

 

Example 1:

Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]

Example 2:

Input: temperatures = [30,40,50,60]
Output: [1,1,1,0]

Example 3:

Input: temperatures = [30,60,90]
Output: [1,1,0]
 */
