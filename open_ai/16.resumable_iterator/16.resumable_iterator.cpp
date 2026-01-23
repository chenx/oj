// 8:53 - 9:20

#include <iostream>
#include <vector>

using namespace std;

class Iterator {
    vector<int> vec;
    int index = 0;

public:
    Iterator(vector<int> inputVec) : vec(inputVec) {

    }

    bool iter() {
        if (index + 1 == vec.size()) return false;
        ++ index;
        return true;
    }

    int next() {
        if (index == vec.size()) return -1;
        return vec[index];
    }

    int getState() {
        return index;
    }

    void setState(int index) {
        this->index = index;
    }
};

class ResumableIterator {
    Iterator iterator;
    int curState = 0;
    bool hasNext_ = false;

public:
    ResumableIterator(Iterator it) : iterator(it) {
        hasNext_ = it.next() != -1;
    }

    int next() {
        if (! hasNext_) return -1;

        curState = iterator.getState();

        int val = iterator.next();
        hasNext_ = iterator.iter();
        return val;
    }

    bool hasNext() {
        return hasNext_;
    }

    int getState() {
        return curState;
    }

    void setState(int state) {
        iterator.setState(state);
        hasNext_ = iterator.next() != -1;
    }
};

class ResumableIteratorTest {
    void test1() {
        Iterator it({1, 2, 3, 4, 5});
        ResumableIterator resumableIterator(it);

        int state = 0;
        vector<int> states;
        while (resumableIterator.hasNext()) {
            int val = resumableIterator.next();
            states.push_back(resumableIterator.getState());
            if (val == 2) {
                state = resumableIterator.getState();
                cout << "state = " << state << endl;
            }
            cout << val << endl;
        }

        resumableIterator.setState(state);
        cout << "set state to " << state << endl;
        while (resumableIterator.hasNext()) {
            cout << resumableIterator.next() << endl;
        }

        for (auto state:  states) {
            resumableIterator.setState(state);
            cout << "\nset state to " << state << endl;
            while (resumableIterator.hasNext()) {
                cout << resumableIterator.next() << endl;
            }
        }
    }

public:
    void run_tests() {
        test1();
    }
};

int main() {
    ResumableIteratorTest test;
    test.run_tests();
    return 0;
}
