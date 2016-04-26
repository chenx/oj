// Solution6. Works. Don't use the "used" matrix. More clean.
class Solution6 {
    int m, n;
    Trie t;
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;
        if (board.size() == 0 || board[0].size() == 0) return ans;
        m = board.size(), n = board[0].size();
        
        for (auto w : words) t.insert(w);

        for (int i = 0; i < m; ++ i) {
            for (int j = 0; j < n; ++ j) {
                find(board, i, j, t.getRoot(), "", ans);
            }
        }
        
        return ans;
    }
    
    void find(vector<vector<char>>& board, int i, int j, TrieNode * node, string w, vector<string> & ans) {
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] == '.') return;
        node = node->getChild(board[i][j]);
        if (node == NULL) return;
        
        w += board[i][j];
        if (node->getIsEnd()) {
            ans.push_back(w);
            node->setIsEnd(false);
        }
        
        char c = board[i][j];
        board[i][j] = '.';
        find(board, i+1, j, node, w, ans);
        find(board, i-1, j, node, w, ans);
        find(board, i, j+1, node, w, ans);
        find(board, i, j-1, node, w, ans);
        board[i][j] = c;
    }
};

//
// Solution5. Works. Among best so far.
//

class TrieNode {
    char val;
    bool end;
    vector<TrieNode *> children;
public:
    // Initialize your data structure here.
    TrieNode(char c) {
        val = c;
        end = false;
    }
    
    char getVal() { return val; }
    void setIsEnd(bool isEnd) { end = isEnd; }
    bool getIsEnd() { return end; }
    TrieNode * getChild(char c) {
        for (int i = 0; i < children.size(); ++ i) {
            if (c == children[i]->getVal()) return children[i];
        }
        return NULL;
    }
    void addChild(TrieNode * child) {
        children.push_back(child);
    }
};

class Trie {
    TrieNode * root;
public:
    Trie() {
        root = new TrieNode(' ');
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode * cur = root;
        
        for (int i = 0; i < word.length(); ++ i) {
            TrieNode * child = cur->getChild(word[i]);
            if (child == NULL) {
                child = new TrieNode(word[i]);
                cur->addChild(child);
            }
            cur = child;
        }
        
        cur->setIsEnd(true);
    }
    
    TrieNode * getRoot() { return root; }
};


class Solution {
    int m, n;
    Trie t;
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;
        if (board.size() == 0 || board[0].size() == 0) return ans;
        m = board.size(), n = board[0].size();
        
        for (auto w : words) t.insert(w);
        vector<vector<bool>> used(m, vector<bool>(n, false));
        
        for (int i = 0; i < m; ++ i) 
            for (int j = 0; j < n; ++ j) 
                find(board, i, j, t.getRoot(), "", ans, used);
        
        return ans;
    }
    
    void find(vector<vector<char>>& board, int i, int j, TrieNode * node, string w, 
    vector<string> & ans, vector<vector<bool>> & used) {
        if (i < 0 || i >= m || j < 0 || j >= n || used[i][j]) return;
        node = node->getChild(board[i][j]);
        if (node == NULL) return;
        
        w += board[i][j]; // or: w += node->getVal();
        if (node->getIsEnd()) {
            ans.push_back(w);
            node->setIsEnd(false);
        }
        
        used[i][j] = true; // don't forget this!
        find(board, i+1, j, node, w, ans, used);
        find(board, i-1, j, node, w, ans, used);
        find(board, i, j+1, node, w, ans, used);
        find(board, i, j-1, node, w, ans, used);
        used[i][j] = false;
    }
};


// Solution4. Works. Tested. By: XC.

class Node {
private:
    char val;
    bool isEnd;
    vector<Node *> children;
public:    
    Node(char c) : val(c), isEnd(false) {}
    void setVal(char c) { val = c; }
    char getVal() { return val; }
    void setIsEnd(bool end) { isEnd = end; }
    bool getIsEnd() { return isEnd; }

    Node * findChild(char c) {
        for (int i = 0; i < children.size(); ++ i) {
            if (c == children[i]->val) return children[i];
        }
        return NULL;
    }
    void addChild(Node * c) {
        children.push_back(c);
    }
};

class Trie {
private:
    Node * root;
public:
    Trie() { root = new Node(' '); }
    
    void insert(string word) {
        Node * cur = root;
        
        for (int i = 0; i < word.length(); ++ i) {
            Node * c = cur->findChild(word[i]);
            if (c == NULL) {
                c = new Node(word[i]);
                cur->addChild(c);
            }
            cur = c;
        }
        
        cur->setIsEnd(true);
    }
    
    Node * getRoot() {
        return root;
    }
};


class Solution4 {
    int m, n;
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;
        if (board.size() == 0 || board[0].size() == 0) return ans;
        m = board.size(), n = board[0].size();
        
        Trie t;
        for (auto w : words) t.insert(w);
        
        for (int i = 0; i < m; ++ i) {
            for (int j = 0; j < n; ++ j) {
                find(board, i, j, t.getRoot(), "", ans);
            }
        }
        
        return ans;
    }
    
    void find(vector<vector<char>>& board, int i, int j, Node * root, string w, vector<string> & ans) {
        Node * c = root->findChild(board[i][j]);
        if (c == NULL) return;
        
        char val = board[i][j];
        w += val;
        
        if (c->getIsEnd()) {
            ans.push_back(w);
            c->setIsEnd(false); // don't return, continue to search below.
        }

        board[i][j] = '_';
        
        for (int k = 0; k < dirs.size(); ++ k) {
            int x = i + dirs[k][0], y = j + dirs[k][1];
            if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] != '_') {
                find(board, x, y, c, w, ans);
            }
        }
        
        board[i][j] = val;
        w.pop_back();
    }
    
    vector<vector<int>> dirs = {
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}
    };
};

// Works. Tested. Better than Solution.
// From: https://leetcode.com/discuss/83660/recommend-beginners-implementation-detailed-explanation

// Works. Tested. Use the TrieTree definition in Solution2.
class Solution3 {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;
        if (board.size() == 0 || board[0].size() == 0) return ans;
        
        TrieTree t;
        for (auto w : words) t.addWord(w);
        
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; ++ i) {
            for (int j = 0; j < n; ++ j) {
                TrieNode * node = t.getRoot()->children[board[i][j] - 'a'];
                if (node != NULL) {
                    find(board, i, j, node, ans);
                }
            }
        }
        return ans;
    }
    
    void find(vector<vector<char>>& board, int i, int j, TrieNode * n, vector<string> & ans) {
        if (n->isWord) {
            ans.push_back(n->word);
            n->isWord = false; // this modifies the TrieTree. Not too good.
        }
        
        char c = board[i][j];
        board[i][j] = '*';
        
        for (int k = 0; k < dir.size(); ++ k) {
            int x = i + dir[k].first, y = j + dir[k].second;
            if (x >= 0 && x < board.size() && y >= 0 && y < board[0].size() 
                    && board[x][y] != '*') {
                TrieNode * node = n->children[board[x][y] - 'a'];
                if (node != NULL) {
                    find(board, x, y, node, ans);
                }
            }
        }
        
        board[i][j] = c;
    }
    
    vector<pair<int, int>> dir = {
        pair<int, int>(-1, 0),
        pair<int, int>(1, 0),
        pair<int, int>(0, -1),
        pair<int, int>(0, 1)
    };
};


/*
// Note: a better implementation of the Trie class is below.
// In a more space effecient Trie implementation, children is vector<TrieNode *>,
// then it's needed to add the char to the TreeNode to specify what char it is for.
// In the implementation here, it uses a fixed size array for children, and
// use the index number to specify which char it is for. So there is no need
// for a char variable. On the other hand, there is no need to add "word" to
// every intermediate TrieNode, only the last TrieNode needs this information.
class TrieNode{
    public:
        TrieNode() : isWord(false), word("") {
            memset(children, 0, sizeof(children));
        }
    public:
        // store-the-root-cur-pos-word 
        string word;
        bool isWord;
        TrieNode* children[MAX_CHARS];
};

class TrieTree{
    public:
        TrieTree():root(new TrieNode()) {}
        ~TrieTree(){ freeTree(root); }
        TrieNode* getRoot(){
            return root;
        }

        void addWord(string& s){
            TrieNode* node=root;

            for(int i=0; i<s.size(); i++){
                if(node->children[s[i]-'a']==NULL){
                    node->children[s[i]-'a']=new TrieNode();
                }
                node=node->children[s[i]-'a'];
            }
            node->isWord=true;
            node->word = s;
        }
    private:
        void freeTree(TrieNode* node){
            for(int i=0; i<MAX_CHARS; i++){
                if(node->children[i]!=NULL){
                    freeTree(node->children[i]);
                }
            }
            delete node;
        }
        TrieNode* root;
};
*/

const int MAX_CHARS=26;

class TrieNode{
    public:
        TrieNode(string s) : isWord(false), word(s) {
            memset(children, 0, sizeof(children));
        }
    public:
        /*** store-the-root-cur-pos-word ***/
        string word;
        bool isWord;
        TrieNode* children[MAX_CHARS];
};

class TrieTree{
    public:
        TrieTree():root(new TrieNode("")) {}
        ~TrieTree(){ freeTree(root); }
        TrieNode* getRoot(){
            return root;
        }

        void addWord(string& s){
            TrieNode* node=root;
            string t;
            for(int i=0; i<s.size(); i++){
                t+=s[i]; // this is not necessary
                if(node->children[s[i]-'a']==NULL){
                    node->children[s[i]-'a']=new TrieNode(t); 
                }
                node=node->children[s[i]-'a'];
            }
            node->isWord=true;
        }
    private:
        void freeTree(TrieNode* node){
            for(int i=0; i<MAX_CHARS; i++){
                if(node->children[i]!=NULL){
                    freeTree(node->children[i]);
                }
            }
            delete node;
        }
        TrieNode* root;
};

class Solution2 {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieTree t;
        for(int i=0; i<words.size(); i++)   t.addWord(words[i]);
        vector<string> result;
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[i].size(); j++){
                help(board, t.getRoot(), i, j, result);
            }
        }
        return result;
    }

    void help(vector<vector<char>>& board, TrieNode* root, int row, int col, vector<string>& result){
        if(row<0 || col<0 || row>=board.size() || col>=board[0].size() || board[row][col]=='*')  return;
        char ch=board[row][col];
        root=root->children[ch-'a'];
        if(root==NULL)   return;
        if(root->isWord){
            result.push_back(root->word);
            root->isWord=false;
        }
        board[row][col]='*';
        help(board, root, row+1, col, result);
        help(board, root, row-1, col, result);
        help(board, root, row, col+1, result);
        help(board, root, row, col-1, result);
        board[row][col]=ch;
    }
};


// Works. Tested. 
// From: https://leetcode.com/discuss/82810/sharing-my-84ms-c-solution-using-trie-and-recursion
class TrieNode
{
public:
    vector<TrieNode*> children;
    bool endOfWord;

    TrieNode()
    {
        children.resize(26, nullptr);
        endOfWord = false;
    }

    ~TrieNode(){}

    void addWord(string word)
    {
        if(word.length() == 0)
            return;

        TrieNode* node = this;
        for(int i=0; i<word.length(); i++)
        {
            if(node->children[word[i]-'a'])
                node = node->children[word[i]-'a'];
            else
            {
                node->children[word[i]-'a'] = new TrieNode();
                node = node->children[word[i]-'a'];
            }
        }

        node->endOfWord = true;
    }
};

class Solution {
public:
    int m;
    int n;

    void findWordsHelper(vector<vector<char>>& board, TrieNode* node, int x, int y, string& s, vector<string>& result)
    {
        if(x<0 || y<0 || x>=m || y>=n || node == nullptr || board[x][y] == '\0')
            return;

        char t = board[x][y];
        if(node->children[t-'a'] == nullptr)
            return;

        s.push_back(t);
        node = node->children[t-'a'];
        board[x][y] = '\0';
        if(node->endOfWord)
        {
            result.push_back(s);
            node->endOfWord = false; // already been picked up
        }

        findWordsHelper(board, node, x-1, y, s, result);
        findWordsHelper(board, node, x+1, y, s, result);
        findWordsHelper(board, node, x, y-1, s, result);
        findWordsHelper(board, node, x, y+1, s, result);

        board[x][y] = t;
        s.pop_back();
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode *root = new TrieNode();
        int i, x, y;
        for(i=0; i<words.size(); i++)
            root->addWord(words[i]);

        m = board.size();
        n = board[0].size();
        string s;
        vector<string> result;
        for(x=0; x<m; x++)
            for(y=0; y<n; y++)
            {
                findWordsHelper(board, root, x, y, s, result);
            }

        return result;
    }
};


/**
Word Search II
Difficulty: Hard

Given a 2D board and a list of words from the dictionary, find all words 
in the board.

Each word must be constructed from letters of sequentially adjacent cell, 
where "adjacent" cells are those horizontally or vertically neighboring. 
The same letter cell may not be used more than once in a word.

For example,
Given words = ["oath","pea","eat","rain"] and board =

[
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]
Return ["eat","oath"].
Note:
You may assume that all inputs are consist of lowercase letters a-z.
 */
 
/**
Comment: main thing is to be efficient. So use Trie to store the words.
 */
