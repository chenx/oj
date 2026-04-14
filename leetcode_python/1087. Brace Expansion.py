class Solution:
    def expand(self, s: str) -> List[str]:
        def dfs(tokens, pos, cur):
            if (pos == len(tokens)):
                result.append(cur)
                return
            
            for token in tokens[pos]:
                dfs(tokens, pos + 1, cur + token)

        # Only 1 level of parenthesis.
        tokens0 = s.split('{')
        tokens1 = []
        for token in tokens0:
            # tokens.extend(token.split('}')) # this may contain empty strings.
            # use filter to remove empty strings from list.
            tokens1.extend(list(filter(None, token.split('}'))))
        
        tokens = []
        for token in tokens1:
            tokens.extend([token.split(',')])
        
        # print(tokens)  # [['a', 'b'], ['c'], ['d', 'e'], ['f']]

        result = []
        dfs(tokens, 0, '')
        result.sort()
        return result


/**
1087. Brace Expansion
Solved
Medium
Topics
conpanies iconCompanies
Hint

You are given a string s representing a list of words. Each letter in the word has one or more options.

    If there is one option, the letter is represented as is.
    If there is more than one option, then curly braces delimit the options. For example, "{a,b,c}" 
        represents options ["a", "b", "c"].

For example, if s = "a{b,c}", the first character is always 'a', but the second character can be 'b' or 'c'. 
The original list is ["ab", "ac"].

Return all words that can be formed in this manner, sorted in lexicographical order.

 

Example 1:

Input: s = "{a,b}c{d,e}f"
Output: ["acdf","acef","bcdf","bcef"]

Example 2:

Input: s = "abcd"
Output: ["abcd"]
 */
