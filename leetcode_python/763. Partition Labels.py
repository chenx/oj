# Time: O(n)
# Space: O(26) = O(1)
class Solution2:
    def partitionLabels(self, s: str) -> List[int]:
        lastPosition : dict[str, int] = {}
        for i in range(len(s)):
            lastPosition[s[i]] = i
        
        result = []
        start, end = 0, 0
        for i in range(len(s)):
            end = max(end, lastPosition[s[i]])
            if i == end:
                result.append(i - start + 1)
                start = i + 1
        return result

        
      
class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        lastPosition = [0] * 26
        for i in range(len(s)):
            lastPosition[ord(s[i]) - ord('a')] = i
        
        result = []
        start, end = 0, 0
        for i in range(len(s)):
            end = max(end, lastPosition[ord(s[i]) - ord('a')])
            if i == end:
                result.append(i - start + 1)
                start = i + 1
        return result

        

/**
763. Partition Labels
Solved
Medium
Topics
conpanies iconCompanies
Hint

You are given a string s. We want to partition the string into as many parts as possible so that 
each letter appears in at most one part. For example, the string "ababcc" can be partitioned into 
["abab", "cc"], but partitions such as ["aba", "bcc"] or ["ab", "ab", "cc"] are invalid.

Note that the partition is done so that after concatenating all the parts in order, the resultant 
string should be s.

Return a list of integers representing the size of these parts.

 

Example 1:

Input: s = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits s into less parts.
 */
