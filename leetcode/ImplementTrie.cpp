class Trie4 {
    struct TrieNode {
        unordered_map<char, TrieNode*> children;
        bool wordMarker;

        TrieNode() : wordMarker(false) {}

        TrieNode* insert(char ch) {
            if (! children.contains(ch)) {
                children[ch] = new TrieNode();
            }
            return children[ch];
        }

        TrieNode* find(char ch) {
            return children.contains(ch) ? children[ch] : NULL;
        }
    };

    TrieNode root;

public:
    Trie() {
        
    }
    
    void insert(string word) {
        TrieNode* node = &root;
        for (char ch : word) {
            cout << "ch = " << ch << endl;
            if (! node) {
                cout << "Error: node is NULL." << endl;
            }
            TrieNode * child = node->find(ch);
            if (! child) {
                child = node->insert(ch);
            }
            node = child; 
        }
        node->wordMarker = true;
    }
    
    bool search(string word) {
        TrieNode* node = &root;
        for (char ch : word) {
            TrieNode * child = node->find(ch);
            if (! child) {
                return false;
            }
            node = child; 
        }
        return node->wordMarker;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = &root;
        for (char ch : prefix) {
            TrieNode * child = node->find(ch);
            if (! child) {
                return false;
            }
            node = child; 
        }
        return true;
    }
};

class Trie3 {
    struct TrieNode {
        unordered_map<char, TrieNode*> children;
        bool wordMarker;
        TrieNode() { wordMarker = false; }

        TrieNode* addChild(char ch) {
            children[ch] = new TrieNode();
            return children[ch];
        }
        TrieNode* findChild(char ch) {
            return children[ch];
            // Note: the above inserts ch into children, children[ch] is NULL.
            // This is same as addChild() and may cause subtle issues. better do:
            // return children.contains(ch) ? children[ch] : nullptr;
            // See Trie4.
        }
    };
    TrieNode root;

public:
    Trie() {}
    
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
    
    bool search(string word) {
        TrieNode* node = &root;
        for (char ch : word) {
            if (node->children.contains(ch)) {
                node = node->children[ch];
            } else {
                return false;
            }
        }
        return node->wordMarker;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = &root;
        for (char ch : prefix) {
            if (node->children.contains(ch)) {
                node = node->children[ch];
            } else {
                return false;
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */


// Works too.
class Trie2 {
    struct TrieNode {
        char content;
        bool wordMarker = false;
        vector<TrieNode *> children;

        TrieNode() {}
        
        TrieNode(char c) {
            content = c;
        }

        // May check find(c) == NULL before calling this.
        TrieNode* appendChild(char c, bool check_first = true) {
            TrieNode * node = NULL;
            if (check_first) {
                node = findChild(c);
                if (node) return node;
            }

            node = new TrieNode(c);
            children.push_back(node);
            return node;
        }

        TrieNode* findChild(char c) {
            for (auto& child : children) {
                if (child->content == c) return child;
            }
            return NULL;
        }

        void setWordMarker(bool val) {
            wordMarker = val;
        }
        bool isWordMarker() {
            return wordMarker;
        }
    };

    TrieNode root;
public:
    Trie() {}
    
    void insert(string word) {
        TrieNode* n = &root;
        for (int i = 0; i < word.length(); ++ i) {
            n = n->appendChild(word[i]);
        }
        n->setWordMarker(true);
    }
    
    bool search(string word) {
        TrieNode* n = &root;
        for (int i = 0; i < word.length(); ++ i) {
            TrieNode *m = n->findChild(word[i]);
            if (m == NULL) return false;
            n = m;
        }
        return n->isWordMarker();
    }
    
    bool startsWith(string prefix) {
        TrieNode* n = &root;
        for (int i = 0, len = prefix.length(); i < len; ++ i) {
            TrieNode *m = n->findChild(prefix[i]);
            if (m == NULL) return false;
            n = m;
        }
        return true;
    }
};

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
