class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() {
        mContent = ' ';
        mMarker = false;
    }

    TrieNode * findChild(char c) {
        for (int i = 0; i < mChildren.size(); ++ i) {
            if (c == mChildren[i]->content()) return mChildren[i]; // or mChildren.at(i).
        }
        return NULL;
    }
    
    bool wordMarker() { return mMarker; }
    void setWordMarker(bool v) { mMarker = v; }
    char content() { return mContent; }
    void setContent(char c) { mContent = c; }
    void appendChild(TrieNode * child) { mChildren.push_back(child); }
    
private:
    char mContent;
    bool mMarker;
    vector<TrieNode *> mChildren;    
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode * current = root;
        if (word.length() == 0) {
            current->setWordMarker(true); // an empty word.
            return;
        }
        
        for (int i = 0; i < word.length(); ++ i) {
            TrieNode * child = current->findChild(word[i]);
            if (child) {
                current = child;
            } else {
                TrieNode * tmp = new TrieNode();
                tmp->setContent(word[i]);
                current->appendChild(tmp);
                current = tmp;
            }
            
            if (i == word.length() - 1) {
                current->setWordMarker(true);
            }
        }
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode * current = root;
    
        for (int i = 0; i < word.length(); ++ i) {
            TrieNode * tmp = current->findChild(word[i]);
            if (! tmp) return false;
            current = tmp;
        }
    
        return current->wordMarker();
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode * current = root;
    
        for (int i = 0; i < prefix.length(); ++ i) {
            TrieNode * tmp = current->findChild(prefix[i]);
            if (! tmp) return false;
            current = tmp;
        }
    
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");


/**
Implement Trie (Prefix Tree)
Difficulty: Medium

Implement a trie with insert, search, and startsWith methods.

Note:
You may assume that all inputs are consist of lowercase letters a-z. 
 */
