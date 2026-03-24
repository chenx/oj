# Time out for large input.
class Solution:
    def longestDupSubstring(self, s: str) -> str:
        def findDup(size: int, s: str):
            # print(f"findDup({size}, {s})")
            foundHashes = set()
            for i in range(len(s) - size + 1):
                j = i + size
                hash = rollingHashes[j] - rollingHashes[i] * powers[j-i]
                if hash in foundHashes: 
                    # print(f"return s[{i}:{i}+{size}] = {s[i:i+size]}")
                    return s[i:i+size]
                foundHashes.add(hash)
            # print(f"return ''")
            return ""
    
        powers = [0] * 30030
        rollingHashes = [0] * 30030
        BASE = 113

        powers[0] = 1
        rollingHashes[0] = 0
        n = len(s)
        for i in range(n):
            powers[i + 1] = powers[i] * BASE
            rollingHashes[i + 1] = rollingHashes[i] * BASE + ord(s[i])
        
        L, R = 0, n-1
        ret = ''
        while L < R:
            M = 1 + (R+L)//2
            dup = findDup(M, s)
            if dup == '':
                R = M - 1
            else:
                L = M
                ret = dup
        return ret



/**
1044. Longest Duplicate Substring
Solved
Hard
Topics
conpanies iconCompanies
Hint

Given a string s, consider all duplicated substrings: (contiguous) substrings of s that occur 2 or more times. 
The occurrences may overlap.

Return any duplicated substring that has the longest possible length. If s does not have a duplicated substring, 
the answer is "".

 

Example 1:

Input: s = "banana"
Output: "ana"

Example 2:

Input: s = "abcd"
Output: ""
 */
