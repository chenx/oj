class Solution:
    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:
        def writeRow(row, rowLen, maxWidth):
            if len(row) == 1:
                return row[0] + ' ' * (maxWidth - len(row[0]))
            
            spaces = maxWidth - rowLen
            intervals = len(row) - 1
            a = spaces // intervals
            b = spaces % intervals
            i = 0
            result = ''
            for i in range(0, b):
                result += row[i] + ' ' * (a + 1)
            for i in range(b, intervals):
                result += row[i] + ' ' * a
            result += row[-1] # last item
            return result
        
        def writeLastRow(row, rowLen, maxWidth):
            result = ''
            for word in row:
                if result != '':
                    result += ' '
                result += word
            result += ' ' * (maxWidth - len(result))
            return result

        rowLen = 0
        row = []
        result = []

        i = 0
        while i < len(words):
            if rowLen + len(row) + len(words[i]) > maxWidth:
                result.append(writeRow(row, rowLen, maxWidth))
                row.clear()
                rowLen = 0
            else:
                row.append(words[i])
                rowLen += len(words[i])
                i += 1
        result.append(writeLastRow(row, rowLen, maxWidth))
        return result
    
    



/**
68. Text Justification
Solved
Hard
Topics
conpanies iconCompanies

Given an array of strings words and a width maxWidth, format the text such that each line has exactly maxWidth 
characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra 
spaces ' ' when necessary so that each line has exactly maxWidth characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line does 
not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left-justified, and no extra space is inserted between words.

Note:

    A word is defined as a character sequence consisting of non-space characters only.
    Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.
    The input array words contains at least one word.
 */
