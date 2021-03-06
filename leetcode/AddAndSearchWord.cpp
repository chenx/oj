// Version 2. Works. Clean.

class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() : val(' '), isEnd(false) {}
    
    TrieNode(char c) : val(c), isEnd(false) {}
    void setVal(char c) { val = c; }
    char getVal() { return val; }
    void setEnd(bool end) { isEnd = end; }
    bool getEnd() { return isEnd; }
    TrieNode * findChild(char c) {
        for (auto child : children) {
            if (child->val == c) return child;
        }
        return NULL;
    }
    void addChild(TrieNode * child) {
        children.push_back(child);
    }
    vector<TrieNode *> & getChildren() {
        return children;
    }
    
private:
    char val;
    bool isEnd;
    vector<TrieNode *> children;
};

class Trie {
public:
    Trie() : root(new TrieNode()) {}
    
    void insert(string word) {
        TrieNode * cur = root;
        
        for (int i = 0; i < word.length(); ++ i) {
            TrieNode * child = cur->findChild(word[i]);
            if (! child) {
                child = new TrieNode(word[i]);
                cur->addChild(child);
            }
            cur = child;
        }
        
        cur->setEnd(true);
    }
    
    bool search(string word) {
        return search(word, 0, root);
    }
    
private:
    bool search(string word, int pos, TrieNode * root) {
        if (pos == word.length()) return root->getEnd();
        
        if (word[pos] == '.') {
            //vector<TrieNode *> &children = root->getChildren(); //this is ok.
            for (int i = 0, len = root->getChildren().size(); i < len; ++ i) {
                if (search(word, pos + 1, root->getChildren()[i]))
                    return true;
            }
            return false;
        }
        else {
            TrieNode * child = root->findChild(word[pos]);
            if (! child) return false;
            return search(word, pos + 1, child);
        }
    }
    
    TrieNode * root;
};

class WordDictionary {
private:
    Trie t;
    
public:
    // Adds a word into the data structure.
    void addWord(string word) {
        t.insert(word);
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return t.search(word);
    }
};



// Version 1.
// Works. Tested.

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
    vector<TrieNode *> children() { return mChildren; }
    
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

    bool search_dot(string word) {
        if (word.length() == 0) return false;
        return search_dot_helper(word, 0, root);
    }
    bool search_dot_helper(string word, int pos, TrieNode * current) {
        if (pos == word.length()) {
            return current->wordMarker();
        }
        
        char c = word[pos];
        if (c == '.') {
            for (int i = 0, len = current->children().size(); i < len; ++ i) {
                if (search_dot_helper(word, pos+1, current->children()[i])) return true;
            }
            return false;
        }
        else {
            TrieNode * tmp = current->findChild(c);
            if (! tmp) return false;
            return search_dot_helper(word, pos+1, tmp);
        }
    }

    // This works too. Tested.
    bool search_dot2(string word) {
        return helper(word, 0, root);
    }
    bool helper(string word, int pos, TrieNode * current) {
        // Must be word.length(), not word.length()-1 !!!
        if (pos == word.length()) return current->wordMarker();

        if (word[pos] == '.') {
            for (auto c : current->children()) {
                if (helper(word, pos+1, c)) return true;
            }
        }        
        else {
            TrieNode * tmp = current->findChild(word[pos]);
            if (! tmp) return false;
            return helper(word, pos+1, tmp);
        }
    }

    /* // Exact search. Not needed here.
    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode * current = root;
    
        for (int i = 0; i < word.length(); ++ i) {
            TrieNode * tmp = current->findChild(word[i]);
            if (! tmp) return false;
            current = tmp;
        }
    
        return current->wordMarker();
    }*/
    
    /*
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
    }*/

private:
    TrieNode* root;
};


class WordDictionary {
public:

    // Adds a word into the data structure.
    void addWord(string word) {
        t.insert(word);
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return t.search_dot(word);
    }

private:
    Trie t;
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");


/**
Add and Search Word - Data structure design
Difficulty: Medium

Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)

search(word) can search a literal word or a regular expression string containing 
only letters a-z or .. A . means it can represent any one letter.

For example:

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true

Note:
You may assume that all words are consist of lowercase letters a-z.

click to show hint.
You should be familiar with how a Trie works. If not, please work on this problem: 
Implement Trie (Prefix Tree) first. 
 */
