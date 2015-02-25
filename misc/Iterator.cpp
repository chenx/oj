/**
 * Iterator implementation.
 * The common theme is:
 *  - In private members, use a container, a current element, a nextVal element, a boolean hasNextVal element.
 *  - In iterator, initialize, then do the first getNext() call.
 *  - In hasNext(), just return hasNextVal.
 *  - In next(), store current nextVal, do a getNext(), then return the stored nextVal.
 *  - Finally, you may want a mechanism in next() to avoid out-of-boundary issue when hasNext() is false.
 *
 * In code below, Iterator2 and Iterator3 comply with this and works well.
 * Iterator1 does not comply and is kind of tricky to get right, by using i < size as judgement of hasNext(),
 * there is a tricky off-by-1 concern.
 *
 * By: X.C. 
 * On: 2/2015
 */

#include <iostream>
#include <vector>
using namespace std;

// Given an int array, iterate through it.
class Iterator1 {
    vector<int> A;
    int size;
    int i;
    int nextVal;

    void getNext() {
        if (i == size) return;
        nextVal = A[i ++];
    }

public:
    Iterator1(vector<int> &v) {
        A = v;
        size = A.size();
        i = 0;
    }

    bool hasNext() { return i < size; }
    int next() { getNext(); return nextVal; }
};

// Given an int array, iterate through it.
// Second implementation for Iterator1.
// Use a hasNextVal boolean value.
class Iterator2 {
    vector<int> A;
    int i;
    int nextVal;
    bool hasNextVal;

    void getNext() {
        if (i == A.size()) {
            hasNextVal = false;
            return;
        }
        hasNextVal = true;
        nextVal = A[i ++];
    }

public:
    Iterator2(vector<int> &v) {
        A = v;
        i = 0;
        getNext();
    }

    bool hasNext() { return hasNextVal; }
    int next() { int v = nextVal; getNext(); return v; }
};


// Iterator: input: int array of positive/negative int, output: positive int.
class Iterator3 {
    vector<int> A;
    int i;
    int nextVal;
    bool hasNextVal;

    void getNext() {
        while (i < A.size() && A[i] <= 0) { ++ i; }

        if (i == A.size()) {
            hasNextVal = false;
            return;
        }
        hasNextVal = true;
        nextVal = A[i ++];
    }

public:
    Iterator3(vector<int> &v) {
        A = v;
        i = 0;
        getNext();
    }

    bool hasNext() { return hasNextVal; }
    
    int next() { 
        if (! hasNext()) {
            //cout << "hasNext() == false" << endl;
            //throw exception();
            return -1;
        }
        int v = nextVal; getNext(); return v; 
    }
};


void test1() {
    vector<int> V(3);
    V[0] = 1, V[1] = 2, V[2] = 3;

    Iterator1 it(V);
    while (it.hasNext()) cout << it.next() << " ";
    cout << endl;
}

void test2() {
    vector<int> V(3);
    V[0] = 1, V[1] = 2, V[2] = 3;

    Iterator2 it(V);
    while (it.hasNext()) cout << it.next() << " ";
    cout << endl;
}

void test3() {
    vector<int> V(3);
    V[0] = -1, V[1] = -2, V[2] = -3;

    Iterator3 it(V);
    while (it.hasNext()) cout << it.next() << " ";
    cout << endl;
}


int main() {
    test3();
    return 0;
}
