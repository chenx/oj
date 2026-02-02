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


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)

/**
208. Implement Trie (Prefix Tree)
Solved
Medium
Topics
conpanies iconCompanies

A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and 
retrieve keys in a dataset of strings. There are various applications of this data structure, such 
as autocomplete and spellchecker.

Implement the Trie class:

    Trie() Initializes the trie object.
    void insert(String word) Inserts the string word into the trie.
    boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted 
        before), and false otherwise.
    boolean startsWith(String prefix) Returns true if there is a previously inserted string word that 
        has the prefix prefix, and false otherwise.
 */
