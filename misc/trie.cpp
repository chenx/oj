//
// Implementation of trie in C++.
//
// @From: http://login2win.blogspot.com/2011/06/c-tries.html
// @Created on: 3/26/2013
// @Last modified: 3/26/2013
//

#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    Node() : mContent(' '), mMarker(false), parent(NULL) {}
    ~Node() {}
    char content() { return mContent; }
    void setContent(char c) { mContent = c; } // can use this->mContent.
    bool wordMarker() { return mMarker; }
    void setWordMarker(bool v) { mMarker = v; }
    Node * findChild(char c);
    void appendChild(Node * child) { 
         mChildren.push_back(child); 
         child->parent = this; /// by X.C.
    }
    // X.C. Use reference, so modification in Trie::deleteWord() is possible.
    vector<Node *> &children() { return mChildren; } 
    Node * getParent() { return parent; }
private:
    char mContent;
    bool mMarker;
    vector<Node *> mChildren;
    Node * parent; /// by X.C.
};

class Trie {
public:
    Trie();
    ~Trie();
    void addWord(string s);
    bool searchWord(string s);
    void deleteWord(string s);
    void draw(Node * n = NULL, int level = 0); /// by X.C. Call with draw().
private:
    Node * root;
    void deleteNode(Node *); // used by destructor.
};


Node * Node::findChild(char c) {
    for (int i = 0; i < mChildren.size(); ++ i) {
        if (c == mChildren[i]->content()) return mChildren[i]; // or mChildren.at(i).
    }
    return NULL;
}

Trie::Trie() {
    root = new Node();
    //cout << "new Trie created" << endl;
}

Trie::~Trie() {
    // Free memory.
    deleteNode(root);
    //cout << "Trie destroyed" << endl;
}

void Trie::deleteNode(Node * n) {
    for (int i = 0; i < n->children().size(); ++ i) {
        deleteNode(n->children()[i]);
    }
    //cout << "delete node " << n->content() << endl;
    delete n;
}

void Trie::addWord(string s) {
    Node * current = root;
    if (s.length() == 0) {
        current->setWordMarker(true); // an empty word.
        return;
    }
    
    for (int i = 0; i < s.length(); ++ i) {
        Node * child = current->findChild(s[i]);
        if (child) {
            current = child;
        } else {
            Node * tmp = new Node();
            tmp->setContent(s[i]);
            current->appendChild(tmp);
            current = tmp;
        }
        
        if (i == s.length() - 1) {
            current->setWordMarker(true);
        }
    }
}

bool Trie::searchWord(string s) {
    Node * current = root;
    
    for (int i = 0; i < s.length(); ++ i) {
        Node * tmp = current->findChild(s[i]);
        if (! tmp) return false;
        current = tmp;
    }

    return current->wordMarker();
    //return false;
}

/// By X.C.
void Trie::deleteWord(string s) {
    Node * current = root;
    for (int i = 0; i < s.length(); ++ i) {
        Node * tmp = current->findChild(s[i]);
        if (! tmp) return; // s not found in this trie.
        current = tmp;
    }
       
    current->setWordMarker(false); 
    
    //return; // in lazy delete mode (for efficiency), can ignore code below.
    
    // Now, delete useless nodes.
    if (current->children().size() > 0) { 
        return; 
    } else {
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
}

// Call with draw(); omit default parameters.
void Trie::draw(Node * n, int level) {
    if (n == NULL) {
        n = root;
        level = 0;
    }
    string marker = (n->wordMarker()) ? "*" : "";
    cout << string(level, ' ') << n->content() << marker << endl;
    for (int i = 0; i < n->children().size(); ++ i) {
        draw(n->children()[i], 1 + level);
    }    
}


void testFind(Trie * trie, string word) {
    if (! trie) return;
    if (trie->searchWord(word)) {
        cout << "Found: " << word << endl;
    } else {
        cout << "NOT found: " << word << endl;
    }
}

void test()
{
    Trie trie2;
    Trie * trie = new Trie();
    trie->addWord("");
    trie->addWord(" ");
    trie->addWord("Hello");
    trie->addWord("Balloon");
    trie->addWord("Ball");

    trie->draw();
    trie->deleteWord("Balloon");
    trie->deleteWord("");
    trie->deleteWord(" ");
    trie->draw();
    
    testFind(trie, "Hell");
    testFind(trie, "Hello");
    testFind(trie, "Helloo");
    testFind(trie, "Ball");
    testFind(trie, "Balloon");
    
    delete trie;
}

int main() {
    test();
    return 0;
}



/*
// 
// Another trie implementation. 
// From: https://gist.github.com/andmej/2222829
// 
// This one is not so good since it wastes many space (26) at each node.
// 

#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;
 
const int MAXS = 100005; // Max number of states
 
struct Trie {
    int g[MAXS][26];
    int stateCount;
    
    Trie() {
        clear();
    }
    
    void clear() {
        memset(g[0], -1, sizeof g[0]);
        stateCount = 1;
    }
    
    void add(char * s) {
        int state = 0; // root
        for (; *s; s++) {
            int next = (*s - 'a');
            if (g[state][next] == -1) { // Add new state
                g[state][next] = stateCount;
                memset(g[stateCount], -1, sizeof g[stateCount]);
                stateCount++;
            }
            state = g[state][next];
        }
    }
    
    void add(const string &s) {
        add(s.c_str());
    }
};
 
 
int main() {
    static Trie t;
    t.add("bang");
    t.add("bing");
    t.add("bong");
    t.add("bon");
    t.add("bo");
    t.add("b");
    printf("There are %d non-empty prefixes in total.\n", t.stateCount - 1);
}
 */
