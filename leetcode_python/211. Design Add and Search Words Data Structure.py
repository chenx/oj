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
        return self.search2(word, self.root)

    def search2(self, word: str, node: TrieNode) -> bool:
        for i in range(len(word)):
            if word[i] == '.':
                for child in node.children:
                    if self.search2(word[i+1:], child):
                        return True
                return False
            else:
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


class WordDictionary:

    def __init__(self):
        self.trie = Trie()

    def addWord(self, word: str) -> None:
        self.trie.insert(word)

    def search(self, word: str) -> bool:
        return self.trie.search(word)
        


# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)

/**
211. Design Add and Search Words Data Structure
Solved
Medium
Topics
conpanies iconCompanies
Hint

Design a data structure that supports adding new words and finding if a string matches any previously added string.

Implement the WordDictionary class:

    WordDictionary() Initializes the object.
    void addWord(word) Adds word to the data structure, it can be matched later.
    bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. 
        word may contain dots '.' where dots can be matched with any letter.
 */
