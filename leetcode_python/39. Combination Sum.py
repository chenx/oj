class Solution2:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        DP = [[] for _ in range(1 + target)]

        for i in range(1 + target):
            for j in range(len(candidates)):
                if i < candidates[j]:
                    continue
                elif i == candidates[j]:
                    DP[i].append([i])
                else:
                    u = DP[i - candidates[j]]
                    for k in u:
                        if candidates[j] >= k[-1]:
                            DP[i].append(k[:])
                            DP[i][-1].append(candidates[j])
        
        return DP[target]



class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        DP = [[] for _ in range(target + 1)]
        for i in range(1, target + 1):
            for j in range(len(candidates)):
                if i < candidates[j]:
                    continue
                elif i == candidates[j]:
                    DP[i].append([i])
                else:
                    u = DP[i - candidates[j]]
                    for k in range(len(u)):
                        print(f"u{k}: {u[k]}")
                        if candidates[j] >= u[k][-1]:
                            DP[i].append(u[k].copy()) # NOTE: or use [:] to make a copy
                            DP[i][-1].append(candidates[j])
            # print(f"{i}. DP[{i}] = {DP[i]}")
        return DP[target]


/**
39. Combination Sum
Solved
Medium
Topics
conpanies iconCompanies

Given an array of distinct integers candidates and a target integer target, return a list of all unique 
combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique 
if the of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to target is less 
than 150 combinations for the given input.

 

Example 1:

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
 */
