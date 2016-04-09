//
// The De Bruijn sequence is useful for solving the lock password issue:
// Use a minimal length of sequence to unlock a box, where password is a
// sequence of n digits in the alphabet of length k.
//

#include <iostream>
#include <set>
#include <queue>
#include <bitset>
#include <vector>
using namespace std;


/**
 * Note the De Bruijn sequence is not unique.
 * There are (k! ^ (k^(n-1))) / k^n such sequences.
 * k - size of alphabet, n = sequence length.
 *
 * Algorithm below is from: https://en.wikipedia.org/wiki/De_Bruijn_sequence
 *
 * The following Python code calculates a De Bruijn sequence, given k and n,
 * based on an algorithm from Frank Ruskey's Combinatorial Generation.[13]

def de_bruijn(k, n):
    """
    De Bruijn sequence for alphabet k
    and subsequences of length n.
    """
    try:
        # let's see if k can be cast to an integer;
        # if so, make our alphabet a list
        _ = int(k)
        alphabet = list(map(str, range(k)))

    except (ValueError, TypeError):
        alphabet = k
        k = len(k)

    a = [0] * k * n
    sequence = []

    def db(t, p):
        if t > n:
            if n % p == 0:
                sequence.extend(a[1:p + 1])   # append a[1:p+1] to sequence.
        else:
            a[t] = a[t - p]
            db(t + 1, p)
            for j in range(a[t - p] + 1, k):
                a[t] = j
                db(t + 1, t)
    db(1, 1)
    for j in range(0, n - 1):
        a[j] = 0
    sequence.extend(a[0:n - 1])
    return "".join(alphabet[i] for i in sequence)

print(de_bruijn(2, 3))
print(de_bruijn("abcd", 2))

which prints

0001011100
aabacadbbcbdccdda
 *
 */

class Debruijn {
    int k, n;
    vector<int> sequence, a;
public:
    Debruijn() { k = 2; } // k is always 2 for alphabet {0, 1}.

    void db(int t, int p) {
        //cout << "t = " << t << ", p = " << p << ", n = " << n << endl;
        if (t > n) {
            if (n % p == 0)
                for (int i = 1; i < p + 1; ++ i)
                    sequence.push_back(a[i]);
        }
        else {
            a[t] = a[t - p];
            db(t + 1, p);
            for (int i = a[t - p] + 1; i < k; ++ i) {
                a[t] = i;
                db(t + 1, t);
            }
        }
    }

    void go(int seqLen) {
        n = seqLen; // length of the debruijn string.
        //k = 2;    // length of alphabet. For {0, 1}, it is 2.

        // 1) initialize.
        a.resize(k * n, 0);
        sequence.resize(0);

        // 2) run db routine
        db(1, 1);

        // 3) append n-1 0s to the end of sequence in the end.
        for (int i = 0; i < n-1; ++ i) sequence.push_back(0);

        // 4) output result.
        // for sequence of length n, 1 << n combinations, each of length n.
        cout << "brutal force: length of all combinations: " << ((1 << n) * n) << endl;
        cout << "debruijn sequence len = " << sequence.size() << endl;
        for (int i = 0; i < sequence.size(); ++ i)
            cout << sequence[i] << "";
        cout << endl;
    }
};

struct Node {
    string val;
    bool visited;
    vector<struct Node *> next;
    Node(string s) : val(s), visited(false) {}
};


// Generate all sequences made of {0, 1} of length n = 4, using dfs or bfs.
class Solution {
public:
    void go() {
        set<string> s;
//        dfs(s, "000");
//bfs_node();
//visit(NULL);
    }

    void dfs(set<string> & s, string p) {
        if (s.count(p)) return;
        s.insert(p);

        string code;

        code = p + "0";
        cout << code << endl;
        dfs(s, code.substr(1, 3));

        code = p + "1";
        cout << code << endl;
        dfs(s, code.substr(1, 3));
    }

    void bfs() {
        queue<string> q;
        set<string> codes;

        q.push("000");

        while (! q.empty()) {
            string c = q.front();
            q.pop();

            string code = c + "0";
            if (! codes.count(code)) {
                codes.insert(code);
                q.push(code.substr(1, 3));
            }

            code = c + "1";
            if (! codes.count(code)) {
                codes.insert(code);
                q.push(code.substr(1, 3));
            }
        }

        for (set<string>::iterator it = codes.begin(); it != codes.end(); ++ it) {
            cout << *it << endl;
        }
    }

    void bfs_node() {
        queue<string> q;
        set<string> codes;

        q.push("0000");
        codes.insert("0000");
        Node * n = new Node("0000");

        while (! q.empty()) {
            string c = q.front();
            q.pop();

            c = c.substr(1);

            string code = c + "0";
            if (! codes.count(code)) {
                codes.insert(code);
                n->next.push_back(new Node(code));
                q.push(code);
            }

            code = c + "1";
            if (! codes.count(code)) {
                codes.insert(code);
                n->next.push_back(new Node(code));
                q.push(code);
            }
        }

        for (set<string>::iterator it = codes.begin(); it != codes.end(); ++ it) {
            cout << *it << endl;
        }

        visit(n);
    }

    void visit(Node * n) {
        cout << "gray code" << endl;

        queue<Node *> q;
        q.push(n);

        while (! q.empty()) {
            Node * t = q.front();
            q.pop();
            t->visited = true;

            cout << t->val << endl;
            for (int i = 0; i < t->next.size(); ++ i) {
                if (! t->next[i]->visited) q.push(t->next[i]);
            }
        }
        return;

        int m = 3;
        string deb = "00";
        for (int i = 0, len = 1 << m; i < len; ++ i) {
            int v = i ^ (i >> 1);
            bitset<3> b(v);
            cout << v << " (" << b << ") " << endl;

            char c = (v & 1) ? '1' : '0';
            deb += c;
        }

        cout << deb << endl;
    }
};


int main() {
    Solution so;
    so.go();

    Debruijn de;
    de.go(3);

    return 0;
}
