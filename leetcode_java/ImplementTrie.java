class TrieNode {
    // Initialize your data structure here.
    public TrieNode() {
        mContent = ' ';
        mMarker = false;
        mChildren = new ArrayList<TrieNode>();
    }
    
    public TrieNode findChild(char c) {
        for (int i = 0; i < mChildren.size(); ++ i) {
            if (c == mChildren.get(i).content()) return mChildren.get(i); 
        }
        return null;
    }
    
    public boolean wordMarker() { return mMarker; }
    public void setWordMarker(boolean v) { mMarker = v; }
    public char content() { return mContent; }
    public void setContent(char c) { mContent = c; }
    public void appendChild(TrieNode child) { mChildren.add(child); }
    
    private char mContent;
    private boolean mMarker;
    private ArrayList<TrieNode> mChildren;   
}

public class Trie {
    private TrieNode root;

    public Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    public void insert(String word) {
        TrieNode current = root;
        if (word.length() == 0) {
            current.setWordMarker(true); // an empty word.
            return;
        }
        
        for (int i = 0; i < word.length(); ++ i) {
            TrieNode child = current.findChild(word.charAt(i));
            if (null != child) {
                current = child;
            } else {
                TrieNode tmp = new TrieNode();
                tmp.setContent(word.charAt(i));
                current.appendChild(tmp);
                current = tmp;
            }
            
            if (i == word.length() - 1) {
                current.setWordMarker(true);
            }
        }
    }

    // Returns if the word is in the trie.
    public boolean search(String word) {
        TrieNode current = root;
    
        for (int i = 0; i < word.length(); ++ i) {
            TrieNode tmp = current.findChild(word.charAt(i));
            if (null == tmp) return false;
            current = tmp;
        }
    
        return current.wordMarker();        
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    public boolean startsWith(String prefix) {
        TrieNode current = root;
    
        for (int i = 0; i < prefix.length(); ++ i) {
            TrieNode tmp = current.findChild(prefix.charAt(i));
            if (null == tmp) return false;
            current = tmp;
        }
    
        return true;
    }
}

// Your Trie object will be instantiated and called as such:
// Trie trie = new Trie();
// trie.insert("somestring");
// trie.search("key");


/**
Implement Trie (Prefix Tree)
Difficulty: Medium

Implement a trie with insert, search, and startsWith methods.

Note:
You may assume that all inputs are consist of lowercase letters a-z. 
 */
