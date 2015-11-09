public class WordDictionary {

    // Adds a word into the data structure.
    public void addWord(String word) {
        t.insert(word);
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    public boolean search(String word) {
        return t.search_dot(word);
    }
    
    private Trie t = new Trie();
}

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
    public ArrayList<TrieNode> children() { return mChildren; }
    
    private char mContent;
    private boolean mMarker;
    private ArrayList<TrieNode> mChildren;   
}

class Trie {
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

    // Allow match by ".".
    public boolean search_dot(String word) {
        if (word.length() == 0) return false;
        return search_dot_helper(word, 0, root);
    }
    // Use DFS for '.'.
    private boolean search_dot_helper(String word, int pos, TrieNode current) {
        if (pos == word.length()) {
            return current.wordMarker(); 
        }
        
        char c = word.charAt(pos);
        
        if (c == '.') {
            for (int i = 0, len = current.children().size(); i < len; ++ i) {
                if (search_dot_helper(word, pos+1, current.children().get(i))) return true;
            }
            return false;
        } else {
            TrieNode tmp = current.findChild(c);
            if (null == tmp) return false;
            return search_dot_helper(word, pos+1, tmp);
        }
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

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary = new WordDictionary();
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
