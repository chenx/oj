class Solution:
    def colorTheArray(self, n: int, queries: List[List[int]]) -> List[int]:
        result = []
        count = 0
        arr = [0] * n
        for [index, newColor] in queries:
            oldColor = arr[index]
            if oldColor != 0:
                if index > 0 and arr[index] == arr[index-1]:
                    count -= 1
                if index < n-1 and arr[index] == arr[index+1]:
                    count -= 1
            
            arr[index] = newColor
            if newColor != 0:
                if index > 0 and arr[index] == arr[index-1]:
                    count += 1
                if index < n-1 and arr[index] == arr[index+1]:
                    count += 1
            
            result.append(count)
        return result
            

/**
2672. Number of Adjacent Elements With the Same Color
Solved
Medium
Topics
conpanies iconCompanies
Hint

You are given an integer n representing an array colors of length n where all elements are set to 0's meaning uncolored. 
You are also given a 2D integer array queries where queries[i] = [indexi, colori]. For the ith query:

    Set colors[indexi] to colori.
    Count the number of adjacent pairs in colors which have the same color (regardless of colori).

Return an array answer of the same length as queries where answer[i] is the answer to the ith query.

 

Example 1:

Input: n = 4, queries = [[0,2],[1,2],[3,1],[1,1],[2,1]]

Output: [0,1,1,0,2]
 */
