from collections import defaultdict
class TrieNode:
    def __init__(self):
        self.children = {}
        self.sentences = defaultdict(int)
    
class AutocompleteSystem:

    def __init__(self, sentences: List[str], times: List[int]):
        self.root = TrieNode()
        for sentence, count in zip(sentences, times):
            self.add_to_trie(sentence, count)
        
        self.cur_sentence = []
        self.cur_node = self.root
        self.dead = TrieNode()
        

    def input(self, c: str) -> List[str]:
        if c == '#':
            cur_sentence = ''.join(self.cur_sentence)
            self.add_to_trie(cur_sentence, 1)
            self.cur_sentence = []
            self.cur_node = self.root
            return []
        
        self.cur_sentence.append(c)
        if c not in self.cur_node.children:
            self.cur_node = self.dead
            return []
        
        self.cur_node = self.cur_node.children[c]
        sentences = self.cur_node.sentences
        sorted_sentences = sorted(sentences.items(), key = lambda x: (-x[1], x[0]))

        ans = []
        for i in range(min(3, len(sorted_sentences))):
            ans.append(sorted_sentences[i][0])
        return ans

    
    def add_to_trie(self, sentence, count):
        node = self.root
        for c in sentence:
            if c not in node.children:
                node.children[c] = TrieNode()
            node = node.children[c]
            node.sentences[sentence] += count
        


# Your AutocompleteSystem object will be instantiated and called as such:
# obj = AutocompleteSystem(sentences, times)
# param_1 = obj.input(c)

/**
642. Design Search Autocomplete System
Solved
Hard
Topics
conpanies iconCompanies

Design a search autocomplete system for a search engine. Users may input a sentence (at least one word and 
end with a special character '#').

You are given a string array sentences and an integer array times both of length n where sentences[i] is a 
previously typed sentence and times[i] is the corresponding number of times the sentence was typed. For each 
input character except '#', return the top 3 historical hot sentences that have the same prefix as the part 
of the sentence already typed.

Here are the specific rules:

    The hot degree for a sentence is defined as the number of times a user typed the exactly same sentence before.
    The returned top 3 hot sentences should be sorted by hot degree (The first is the hottest one). If several 
sentences have the same hot degree, use ASCII-code order (smaller one appears first).
    If less than 3 hot sentences exist, return as many as you can.
    When the input is a special character, it means the sentence ends, and in this case, you need to return an empty list.

Implement the AutocompleteSystem class:

    AutocompleteSystem(String[] sentences, int[] times) Initializes the object with the sentences and times arrays.
    List<String> input(char c) This indicates that the user typed the character c.
        Returns an empty array [] if c == '#' and stores the inputted sentence in the system.
        Returns the top 3 historical hot sentences that have the same prefix as the part of the sentence 
          already typed. If there are fewer than 3 matches, return them all.

 

Example 1:

Input
["AutocompleteSystem", "input", "input", "input", "input"]
[[["i love you", "island", "iroman", "i love leetcode"], [5, 3, 2, 2]], ["i"], [" "], ["a"], ["#"]]
Output
[null, ["i love you", "island", "i love leetcode"], ["i love you", "i love leetcode"], [], []]
 */
