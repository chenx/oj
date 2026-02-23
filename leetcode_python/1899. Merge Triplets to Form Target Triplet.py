# If a triplet contains an element larger than corresponding element in target, exclude it from candidates.
# if count of element in target is >= 1 for each of the 3 elements, we can combine to get the target.
# Time: O(n), n = len(triplets)
# Space: O(n)
class Solution:
    def mergeTriplets(self, triplets: List[List[int]], target: List[int]) -> bool:
        candidates = []
        for t in triplets:
            if t[0] <= target[0] and t[1] <= target[1] and t[2] <= target[2]:
                candidates.append(t)
        
        ct1, ct2, ct3 = 0, 0, 0
        for c in candidates:
            if c[0] == target[0]: ct1 += 1
            if c[1] == target[1]: ct2 += 1
            if c[2] == target[2]: ct3 += 1

        return ct1 > 0 and ct2 > 0 and ct3 > 0
      

/**
1899. Merge Triplets to Form Target Triplet
Solved
Medium
Topics
conpanies iconCompanies
Hint

A triplet is an array of three integers. You are given a 2D integer array triplets, where triplets[i] = [ai, bi, ci] 
describes the ith triplet. You are also given an integer array target = [x, y, z] that describes the triplet you want 
to obtain.

To obtain target, you may apply the following operation on triplets any number of times (possibly zero):

    Choose two indices (0-indexed) i and j (i != j) and update triplets[j] to become [max(ai, aj), max(bi, bj), max(ci, cj)].
        For example, if triplets[i] = [2, 5, 3] and triplets[j] = [1, 7, 5], triplets[j] will be updated to 
    [max(2, 1), max(5, 7), max(3, 5)] = [2, 7, 5].

Return true if it is possible to obtain the target triplet [x, y, z] as an element of triplets, or false otherwise.

 

Example 1:

Input: triplets = [[2,5,3],[1,8,4],[1,7,5]], target = [2,7,5]
Output: true
Explanation: Perform the following operations:
- Choose the first and last triplets [[2,5,3],[1,8,4],[1,7,5]]. Update the last triplet to be [max(2,1), max(5,7), 
  max(3,5)] = [2,7,5]. triplets = [[2,5,3],[1,8,4],[2,7,5]]
The target triplet [2,7,5] is now an element of triplets.

Example 2:

Input: triplets = [[3,4,5],[4,5,6]], target = [3,2,5]
Output: false
Explanation: It is impossible to have [3,2,5] as an element because there is no 2 in any of the triplets.
 */
