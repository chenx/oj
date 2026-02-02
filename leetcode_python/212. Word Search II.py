class TrieNode:
    def __init__(self, c = '', wordMarker = False):
        self.content = c
        self.children = []
        self.wordMarker = wordMarker

    def findChild(self, c):
        for child in self.children:
            if child.content == c:
                return child
        return None

    def addChild(self, c):
        self.children.append(TrieNode(c))
        return self.children[-1]
        

class Trie:

    def __init__(self):
        self.root = TrieNode()

    def insert(self, word: str) -> None:
        node = self.root
        for i in range(len(word)):
            child = node.findChild(word[i])
            if child == None:
                child = node.addChild(word[i])
            node = child
        node.wordMarker = True

    def search(self, word: str) -> bool:
        node = self.root
        for i in range(len(word)):
            node = node.findChild(word[i])
            if node == None:
                return False
        return node.wordMarker

    def startsWith(self, prefix: str) -> bool:
        node = self.root
        for i in range(len(prefix)):
            node = node.findChild(prefix[i])
            if node is None:
                return False
        return True


# add all words to trie.
# DFS board, if a word is found, add to result, also set wordMarker to false
class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        def dfs(result, board, i, j, node, s):
            if node.wordMarker:
                result.append(s)
                node.wordMarker = False
            
            backup = board[i][j]
            board[i][j] = '.'

            dir = [-1, 0, 1, 0, -1]
            for k in range(4):
                x, y = i + dir[k], j + dir[k+1]
                if x >= 0 and x < self.rows and y >= 0 and y < self.cols:
                    child = node.findChild(board[x][y])
                    if child is not None:
                        dfs(result, board, x, y, child, s + board[x][y])

            board[i][j] = backup
            

        trie = Trie()
        for word in words:
            trie.insert(word)

        result = []
        self.rows = len(board)
        self.cols = len(board[0])
        for i in range(self.rows):
            for j in range(self.cols):
                node = trie.root.findChild(board[i][j])
                if node is not None:
                    s = board[i][j]
                    dfs(result, board, i, j, node, s)
        
        return result

/**
212. Word Search II
Solved
Hard
Topics
conpanies iconCompanies
Hint

Given an m x n board of characters and a list of strings words, return all words on the board.

Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells 
are horizontally or vertically neighboring. The same letter cell may not be used more than once 
in a word.
 */
