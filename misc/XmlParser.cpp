//
// Xml Parser.
//
// @by: X.C.
// @created on: 5/9/2016
// @last modified: 5/9/2016
//
#include <iostream>
#include <vector>
#include <stack>
using namespace std;


class Node {
public:
    string tag;
    string val;
    vector<Node *> children;

    Node(string t) { tag = t; val = ""; }
};

// xml := head list
// head := "<xml>"
// list := item {list}
// item := '<' tag '>' val '</' tag '>'
// val  := string | list
// string := [a-zA-Z0-9]+

class XmlParser {
    const char * p;
    Node * root;
public:
    XmlParser() { }

    Node * parse(string s) {
        root = NULL; 
        p = s.c_str();
        head();
        list();
        return root;
    }

    void head() {
        string header = "<xml>";
        for (int i = 0; i < header.length(); ++ i) {
            if (*p ++ != header[i]) error("invalid header");
        }
    }

    // This uses 2 stacks. Similar to shunting-yard.
    void list() {
        stack<Node *> tree;
        tree.push(new Node("root"));

        pair<int, string> t = getToken();
        for (; t.first != 0; t = getToken()) {
            //cout << "next token: " << t.first << ", " << t.second << endl;
            if (t.first == 1) {
                cout << "open tag: " << t.second << endl;
                tree.push(new Node(t.second));
            }
            else if (t.first == 2) {
                if (tree.top()->tag == t.second) {
                    Node * n = tree.top();
                    tree.pop();
                    tree.top()->children.push_back(n);
                }
                else error("unmatched close tag: " + t.second);
            }
            else if (t.first == 3) {
                cout << "found value: " << t.second << endl;
                tree.top()->val += t.second;
            }
        }

        cout << "parse tree:\n"; dump(tree.top(), 0);
    }

    void dump(Node * n, int level) {
        if (n == NULL) return;
        cout << string(2 * level, ' ') << n->tag << ": " << n->val << endl;
        for (int i = 0; i < n->children.size(); ++ i) {
            dump(n->children[i], level + 1);
        }
    }

    void list_back() {
        stack<string> s;

        pair<int, string> t = getToken();
        for (; t.first != 0; t = getToken()) {
            //cout << "next token: " << t.first << ", " << t.second << endl;
            if (t.first == 1) {
                cout << "open tag: " << t.second << endl;
                s.push(t.second);
            }
            else if (t.first == 2) {
                if (s.top() == t.second) {
                    cout << "end tag: " << t.second << endl;
                    s.pop();
                }
                else error("unmatched tag: " + t.second);
            }
            else if (t.first == 3) {
                cout << "found value: " << t.second << endl;
            }
        }
    }

    void list2() {
cout << "...list()\n";

        /*pair<int, string> t = getToken();
        for (; t.first != 0; t = getToken()) {
            cout << "next token: " << t.first << ", " << t.second << endl;
        }*/

        ignoreSpace();
        if (! *p) return;
        item();
        list();
    }

    void item() {
cout << "...item()\n";
        if (! *p) return;

        int type = checkToken();
        if (type == 1) 
        {
        string tag = openTag();
        value();
        closeTag(tag);
        cout << "end of an item" << endl;
        }
    }

    string openTag() {
        pair<int, string> t = getToken();
        if (t.first != 1) error("invalid open tag: " + t.second);
        return t.second;
    }

    void closeTag(string tag) {
        pair<int, string> t = getToken();
        if (t.first != 2 || t.second != tag) 
            error("invalid close tag: " + t.second + ", expecting: " + tag);
    }

    void value() {
        int type = checkToken();
        //pair<int, string> t = getToken();
//cout << "...value(). t: " << t.first << ", " << t.second << "\n";

        if (type == 1) list();
        else if (type == 2) {
            cout << "empty value. close tag" << endl;
        }
        else if (type == 3) {
            pair<int, string> t = getToken();
            cout << "get value: " << t.second << endl;
        }
    }

    void expect(char c) {
        ignoreSpace();
        if (*p != c) error("expecting: " + c);
        ++ p;
    }

    void ignoreSpace() {
        while (isspace(*p)) ++ p;
    }

    // type: 0 - EOF, 1 - open tag, 2 - close tag, 3 - val.
    pair<int, string> getToken() {
        int type = 0;
        string val;

        ignoreSpace();
        if (! *p) return pair<int, string>(0, "");

        if (*p == '<') {
            ++ p;
            if (*p == '/') {
                type = 2;
                ++ p;
            }
            else type = 1;
            while (*p && *p != '>') val += *p ++;
            expect('>');
        }
        else {
            type = 3;
            while (*p != '<') val += *p ++;
        }
        
        //cout << "getToken(): type: " << type << ", value: " << val << endl;
        return pair<int, string>(type, val);
    }

    int checkToken() {
        int type = 0;

        ignoreSpace();
        if (! *p) return 0;

        if (*p == '<') {
            if (*(p + 1) == '/') {
                type = 2;
            }
            else type = 1;
        }
        else {
            type = 3;
        }

        return type;
    }

    void error(string msg) {
        cout << msg << endl;
        throw exception();
    }
};


void test(string s) {
    try {
        XmlParser xp;
        Node * root = xp.parse(s);
    }
    catch (...) { // (exception ex) {
        cout << "exception happended while parsing" << endl;
    }
    cout << endl;
}

void test1() {
    string s = 
"<xml> \
<e1> \
  <e2>1</e2> \
  <e2>2</e2> \
</e1> \
";
    test(s);
}

void test2() {
    string s =
"<xml> \
<html> \
  <head><title>Test</title><meta>Description</meta></head> \
  <body> \
    <p>Paragraph 1. <b>Bold text</b>.</p> \
    <p>Paragraph 2</p> \
  </body> \
</html> \
";
    test(s);
}

int main() {
    test1();
    test2();
    return 0;
}
