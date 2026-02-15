# Use array. Also works. 
# Time: O(n1 + n2), Space: O(26+26) = O(1)
class Solution3:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        n1, n2 = len(s1), len(s2)

        if s1 > s2:
            return False

        charCount1 = [0] * 26
        for i in range(n1):
            charCount1[ord(s1[i]) - ord('a')] += 1

        charCount2 = [0] * 26
        for i in range(n1):
            charCount2[ord(s2[i]) - ord('a')] += 1
        if charCount1 == charCount2:
            return True

        for i in range(n1, n2):
            charCount2[ord(s2[i]) - ord('a')] += 1
            charCount2[ord(s2[i]) - ord('a') - n1] -= 1
            if charCount1 == charCount2:
                return True
        return False


# Time: O(n1 + n2), Space: O(26 + 26) = O(1)
class Solution2:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        n1, n2 = len(s1), len(s2)
        if n1 > n2: 
            return False
        
        toFind = {}
        for ch in list(s1): # Time, Space: O(n1)
            if not ch in toFind:
                toFind[ch] = 0
            toFind[ch] += 1
        
        found = {}
        for i in range(n2): # Time: O(n2)
            if not s2[i] in found:
                found[s2[i]] = 0
            found[s2[i]] += 1

            if i >= n1:
                found[s2[i - n1]] -= 1
                if found[s2[i - n1]] == 0:
                    found.pop(s2[i - n1])
            if found == toFind: # O(n1 + n2)
                return True

        return False
        

# Time out for large input
class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        n1, n2 = len(s1), len(s2)
        if n1 > n2: 
            return False
        
        key = "".join(sorted(list(s1)))
        for i in range(n2 - n1 + 1):
            t = s2[i: i+n1]
            print(t)
            keyT = "".join(sorted(list(t)))
            if key == keyT:
                return True
        return False

/**
567. Permutation in String
Solved
Medium
Topics
conpanies iconCompanies
Hint

Given two strings s1 and s2, return true if s2 contains a of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

 

Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").

Example 2:

Input: s1 = "ab", s2 = "eidboaoo"
Output: false
 */
