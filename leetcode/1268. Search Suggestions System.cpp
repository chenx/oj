// From: https://leetcode.com/problems/search-suggestions-system/editorial/
// Time complexity : O(M) to build the trie where M is total number of characters in products
// Space complexity : O(26n)=O(n). Here n is the number of nodes in the trie. 26 is the alphabet size.
// Space required for output is O(m) where m is the length of the search word.
class Trie {
    struct TrieNode {
        // Use map to guarantee lexicographic order.
        map<char, TrieNode*> children;
        bool wordMarker;
        TrieNode() { wordMarker = false; }

        TrieNode* addChild(char ch) {
            children[ch] = new TrieNode();
            return children[ch];
        }
        TrieNode* findChild(char ch) {
            return children[ch];
        }
    };
    TrieNode root;

public:
    Trie() {}

    void dfsWithPrefix(TrieNode* node, string& word, vector<string>& result) {
        if (result.size() == 3) return;
        if (node->wordMarker) result.push_back(word);

        for (auto& [ch, child] : node->children) {
            string w = word + ch;
            dfsWithPrefix(child, w, result);
        }
    }

    vector<string> getWordsStartingWith(string& prefix) {
        vector<string> result;
        TrieNode* node = &root;
        for (char ch : prefix) {
            if (node->children.contains(ch)) {
                node = node->children[ch];
            } else {
                return result;
            }
        }
        dfsWithPrefix(node, prefix, result);
        return result;
    }
    
    void insert(string word) {
        TrieNode* node = &root;
        for (char ch : word) {
            if (node->children.contains(ch)) {
                node = node->children[ch];
            } else {
                node = node->addChild(ch);
            }
        }
        node->wordMarker = true;
    }
};


class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> result;
        Trie trie;
        for (string& product : products) trie.insert(product);

        string prefix;
        for (char ch : searchWord) {
            prefix += ch;
            result.push_back(trie.getWordsStartingWith(prefix));
        }
        return result;
    }
};


/**
1268. Search Suggestions System
Solved
Medium
Topics
conpanies iconCompanies
Hint

You are given an array of strings products and a string searchWord.

Design a system that suggests at most three product names from products after each character of searchWord is typed. 
Suggested products should have common prefix with searchWord. If there are more than three products with a common 
prefix return the three lexicographically minimums products.

Return a list of lists of the suggested products after each character of searchWord is typed.

 

Example 1:

Input: products = ["mobile","mouse","moneypot","monitor","mousepad"], searchWord = "mouse"
Output: [["mobile","moneypot","monitor"],["mobile","moneypot","monitor"],["mouse","mousepad"],["mouse","mousepad"],["mouse","mousepad"]]
Explanation: products sorted lexicographically = ["mobile","moneypot","monitor","mouse","mousepad"].
After typing m and mo all products match and we show user ["mobile","moneypot","monitor"].
After typing mou, mous and mouse the system suggests ["mouse","mousepad"].

Example 2:

Input: products = ["havana"], searchWord = "havana"
Output: [["havana"],["havana"],["havana"],["havana"],["havana"],["havana"]]
Explanation: The only word "havana" will be always suggested while typing the search word.
 */
