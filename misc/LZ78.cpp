//
// Implementation of LZ78 (Lempel-Ziv 1978) compression algorithm based on trie in C++.
//
// Algorithm is from [1].
//
// References:
// [1] Data Structures and Algorithms in Java. Pages 576-578.
//     Michael T. Goodrich, Roberto Tamassia. 1998. ISBN 0-471-19308-9.
// [2] https://en.wikipedia.org/wiki/LZ77_and_LZ78
//
// @By: X.C.
// @Created on: 5/13/2016
// @Last modified: 5/13/2016
//

#include <iostream>
#include <vector>
#include <map>
#include <sstream>
using namespace std;


string to_string(int v) {
    stringstream ss;
    ss << v;
    return ss.str();
}

class Node {
public:
    Node(char c) : mContent(c), mMarker(false), parent(NULL), phase(0) {}
    ~Node() {}
    char content() { return mContent; }
    void setContent(char c) { mContent = c; } // can use this->mContent.
    bool wordMarker() { return mMarker; }
    void setWordMarker(bool v) { mMarker = v; }
    Node * findChild(char c) {
        for (int i = 0; i < mChildren.size(); ++ i) {
            if (c == mChildren[i]->content()) return mChildren[i]; // or mChildren.at(i).
        }
        return NULL;
    }
    void appendChild(Node * child) { 
         mChildren.push_back(child); 
         child->parent = this;  // used by deleteWord() only. X.C.
    }
    void deleteChild(char c) {  // used by deleteW() only. X.C.
        //cout << "delete child " << c << " from [" << content() << "]" << endl;
        for (vector<Node *>::iterator it = mChildren.begin(); it != mChildren.end(); ++ it) {
            if ((*it)->content() == c) {  //cout << "found and delete" << endl;
                delete *it;  // free node, to avoid memory leak.
                             // must be done before erase(), otherwise has runtime error.
                mChildren.erase(it);
                break;
            }
        }
    }
    // X.C. Use reference, so modification in Trie::deleteWord() is possible.
    vector<Node *> &children() { return mChildren; } 
    Node * getParent() { return parent; }
    void setPhase(int p) { phase = p; }
    int getPhase() { return phase; }
private:
    char mContent;
    bool mMarker;
    vector<Node *> mChildren;
    Node * parent; /// by X.C. used for delete only.
    int phase;
};

class Trie {
public:
    Trie();
    ~Trie();
    string lzCompress(string s);
    string lzDecompress(string s);
    void addWord(string s);
    bool searchWord(string s);
    void deleteWord(string s);
    void deleteW(string s);  // bottom up version of deleteWord().
    void draw(Node * n = NULL, int level = 0); /// by X.C. Call with draw().
private:
    Node * root;
    void deleteNode(Node *); // used by destructor.
    bool deleteW(Node *, string s, int pos); // used by deleteW.
    void lzCompress(const char *& s, string & output, int & phase);
    void lzDecompress(const char *& s, 
             map<int, string> &mp, map<int, Node *> &mn, string & output, int & phase);
};



Trie::Trie() {
    root = new Node(' ');  //cout << "new Trie created" << endl;
}

Trie::~Trie() {
    deleteNode(root);  //cout << "Trie destroyed" << endl;
}

void Trie::deleteNode(Node * n) {
    for (int i = 0; i < n->children().size(); ++ i) {
        deleteNode(n->children()[i]);
    }
    //cout << "delete node " << n->content() << endl;
    delete n;
}


string Trie::lzDecompress(string input) {
    string output;
    const char * s = input.c_str();
    map<int, string> mp;  // map phase number to plain text.
    map<int, Node *> mn;  // map phase number to node in trie.
    mp[0] = "";
    mn[0] = root;
    int ph = 0;  // phase number.

    while (*s) {
        lzDecompress(s, mp, mn, output, ph);
    }
    return output;
}
void Trie::lzDecompress(const char *& s, 
        map<int, string> & mp, map<int, Node *> &mn, string & output, int & ph) {
    if (! isdigit(*s)) return;
    Node * current = root;
    
    int p = 0;
    for (; isdigit(*s); ++ s) {
        p = p * 10 + *s - '0';
    }

    if (! *s) return; // should not happen.
    char c = *s ++;
    
    output += mp[p] + c; // get output.

    // append the next node into the decompress trie.
    Node * child = new Node(c);
    child->setPhase(++ ph);
    mn[p]->appendChild(child);

    // Add new phase value to maps mp and mn.
    mp[ph] = mp[p] + c;
    mn[ph] = child;
}


string Trie::lzCompress(string input) {
    string output;
    const char * s = input.c_str();
    int ph = 0; // phase
    while (*s) {
        lzCompress(s, output, ph);
    }
    return output;
}
void Trie::lzCompress(const char *& s, string & output, int & ph) {
    Node * current = root;

    for (; *s; ++ s) {
        char c = *s;
        Node * child = current->findChild(c);
        if (child == NULL) {
            output += to_string(current->getPhase()) + c;

            child = new Node(c);
            child->setPhase(++ ph);
            current->appendChild(child);
            ++ s;
            return;
        }
        current = child;
    }
}

/*
// These methods are not needed for LZ78 compression and decompression.
void Trie::addWord(string s) {
    Node * current = root;
    
    for (int i = 0; i < s.length(); ++ i) {
        Node * child = current->findChild(s[i]);
        if (child == NULL) {
            child = new Node(s[i]);
            current->appendChild(child);
        }
        current = child;
    }
        
    current->setWordMarker(true);
}

bool Trie::searchWord(string s) {
    Node * current = root;
    
    for (int i = 0; i < s.length(); ++ i) {
        Node * tmp = current->findChild(s[i]);
        if (! tmp) return false;
        current = tmp;
    }

    return current->wordMarker();
}

// Top down version of deleteWord(). X.C.
// This needs a parent pointer at each node. Not prefered.
void Trie::deleteWord(string s) {
    Node * current = root;
    for (int i = 0; i < s.length(); ++ i) {
        Node * tmp = current->findChild(s[i]);
        if (! tmp) return; // s not found in this trie.
        current = tmp;
    }
       
    current->setWordMarker(false); 
    
    //return; // in lazy delete mode (for efficiency), can ignore code below.
    
    if (current->children().size() > 0) return;

    // else, delete useless nodes.
    // delete nodes upward unless for current node n,
    // n.wordMarker() || n.children().size() > 1.
    // cout << "delete node: " << current->content() << endl;
    while(1) {
        Node * parent = current->getParent();
            
        // remove current node from parent's children list.
        vector<Node *> &v = parent->children();
        for (int i = 0; i < v.size(); ++ i) {
            if (v[i] == current) {
                v.erase(v.begin() + i);
                break;
            }
        }
            
        delete current;
        current = parent;
            
        if (current == root || 
            current->wordMarker() || current->children().size() > 0) {
            break;
        }
    }
}

// Bottom up version of deleteWord(). X.C.
// This does not need a parent pointer at each node. Prefered.
// This needs the Node::deleteChild() function instead.
void Trie::deleteW(string s) {
    deleteW(root, s, 0);
}
bool Trie::deleteW(Node * n, const string s, int pos) {
    if (n == NULL) return false;
    
    // is end node.
    if (pos == s.length()) {
        n->setWordMarker(false);
        if (n->children().size() == 0 && n != root) {
            return true;   // ok for parent to delete n.
        }
        else return false; // parent should not delete n.
    }

    // else, is intermediate node.
    Node * child = n->findChild(s[pos]);
    if (child == NULL) return false; 
    if (deleteW(child, s, pos + 1)) {
        n->deleteChild(s[pos]);  // remove child from n's children list.
        if (n->children().size() == 0 && ! n->wordMarker() && n != root) {
            return true;  // ok for parent to delete n.
        }
    }
    // child is not deleted, or current node contains other child, or
    // current node is an end marker, then do not delete n, and return false.
    return false;  // parent should not delete n.
}
*/

// Call with draw(); omit default parameters.
void Trie::draw(Node * n, int level) {
    if (n == NULL) {
        cout << "== draw trie. Node output as (value, phase) pair ==" << endl;
        n = root;
        level = 0;
    }
    string marker = (n->wordMarker()) ? "*" : "";
    cout << string(level * 2, ' ') << "[" << n->content() << ", " 
         << n->getPhase() << "]" << marker << endl;
    for (int i = 0; i < n->children().size(); ++ i) {
        draw(n->children()[i], 1 + level);
    }    
}


void test(string word, string expect) {
    Trie trie;
    string answer = trie.lzCompress(word);
    cout << "input: " << word << "\ncompress expect: " << expect 
         << "\ncompress output: " << answer
         << "\n... compress: " << (answer == expect ? "pass" : "fail") << endl;
    //trie.draw();

    Trie trie2;
    string answer_decompress = trie2.lzDecompress(answer);
    cout << "decompress output: " << answer_decompress << endl;
    cout << "... decompress: " << (answer_decompress == word ? "pass" : "fail") << endl;
    //trie2.draw();

    cout << endl;
}

void test1() {
    string input = "how now brown cow in town.";
    test(input, "0h0o0w0 0n2w4b0r6n4c6 0i5 0t9.");
}

void test2() {
    string input = "how now brown cow in town. That is another story as I told you.";
    test(input, "0h0o0w0 0n2w4b0r6n4c6 0i5 0t9.4T1a14 12s4a5o14h0e8 0s14o8y20s4I4t2l0d4y2u0.");
}

int main() {
    test1();
    test2();
    return 0;
}


/**
Execution output:

input: how now brown cow in town.
compress expect: 0h0o0w0 0n2w4b0r6n4c6 0i5 0t9.
compress output: 0h0o0w0 0n2w4b0r6n4c6 0i5 0t9.
... compress: pass
decompress output: how now brown cow in town.
... decompress: pass

input: how now brown cow in town. That is another story as I told you.
compress expect: 0h0o0w0 0n2w4b0r6n4c6 0i5 0t9.4T1a14 12s4a5o14h0e8 0s14o8y20s4I4t2l0d4y2u0.
compress output: 0h0o0w0 0n2w4b0r6n4c6 0i5 0t9.4T1a14 12s4a5o14h0e8 0s14o8y20s4I4t2l0d4y2u0.
... compress: pass
decompress output: how now brown cow in town. That is another story as I told you.
... decompress: pass
 */
