#include <iostream>
#include <vector>
using namespace std;

vector<int> addOne(vector<int> n) {
   int carry = 1;
   for (int i = 0; i < n.size(); ++ i) {
        int sum = carry + n[i];
        if (sum >= 10) {
            n[i] = sum - 10;
            carry = 1;
        } else {
            n[i] = sum;
            carry = 0;
            break;
        }
   }
   if (carry == 1) {
      n.push_back(1); // push to n[size() - 1], which is the highest digit.
   }
   return n;
}

void dump(vector<int> s) {
    for (int i = s.size() - 1; i >= 0; -- i) {
        printf("%d ", s[i]);
    }
    puts("");
}

int main() {
    vector<int> v;
    v.push_back(8);
    v.push_back(9);
    v.push_back(9);
    dump(v);
    v = addOne(v); dump(v);
    v = addOne(v); dump(v);
    return 0;
}
