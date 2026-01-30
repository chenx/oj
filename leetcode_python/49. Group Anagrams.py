class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        def getKey(s):
            return "".join(sorted(list(s)))
        
        map : dict[key, list(val)] = {}
        for s in strs:
            key = getKey(s)
            if not key in map:
                map[key] = [s]
            else:
                map[key].append(s)
        
        result = []
        for key, val in map.items():
            val.sort()
            result.append(val)

        return result

/**
49. Group Anagrams
Solved
Medium
Topics
conpanies iconCompanies

Given an array of strings strs, group the together. You can return the answer in any order.

 

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]

Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Explanation:

    There is no string in strs that can be rearranged to form "bat".
    The strings "nat" and "tan" are anagrams as they can be rearranged to form each other.
    The strings "ate", "eat", and "tea" are anagrams as they can be rearranged to form each other.

Example 2:

Input: strs = [""]

Output: [[""]]
 */
