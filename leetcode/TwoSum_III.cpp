#include <iostream>
#include <vector>
#include <set>
using namespace std;

// This works.
class TwoSum {
public:
        void add(int number) {
            nums.push_back(number);
        }

        bool find(int value) {
            if (sumFound.find(value) != sumFound.end()) return true;
            
            set<int> m;
            for (int i = 0; i < nums.size(); ++ i) {
                if (m.find(nums[i]) == m.end()) {
                    m.insert(value - nums[i]);
                }
                else {
                    sumFound.insert(value);
                    break;
                }
            }

            return sumFound.find(value) != sumFound.end();
        }

private:
    vector<int> nums; // store numbers added.
    set<int> sumFound;  // store values that are sum of 2 numbers added.
};

void ok(bool isOk, string s) {
    if (isOk) cout << "ok: " << s << endl;
    else cout << "Not ok: " << s << endl;
}

void test() {
    TwoSum ts;
    ok(ts.find(2) == false, "2 not exist");

    ts.add(1);
    ts.add(0);
    ts.add(2);
    ok(ts.find(2) == true, "2 exists");
}

int main() {
    test();
    return 0;
}

/**
Two Sum III - Data structure design
Difficulty: Easy

Design and implement a TwoSum class. It should support the following operations: add and find.

add - Add the number to an internal data structure.
find - Find if there exists any pair of numbers which sum is equal to the value.

For example,

add(1); add(3); add(5);
find(4) -> true
find(7) -> false
 */
