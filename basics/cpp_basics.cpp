// Basic utitities of C++.
// STL data structures.
// Class.
// See https://www.w3schools.com/cpp/
#include <exception>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <stdexcept>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <exception>

using namespace std;

void test_queue() {
  cout << "==> test_queue" << endl;
  queue<string> q;
  q.push("1");
  q.push("2");
  cout << "queue: " << q.size() << endl;

  while (! q.empty()) {
    cout << q.front() << endl;
    q.pop();
  }
}

void test_priority_queue() {
  cout << "==> test_priority_queue" << endl;
  // priority_queue<string, vector<string>, less<string>> maxQ;
  priority_queue<string, vector<string>> maxQ;
  maxQ.push("1");
  maxQ.push("2");
  cout << "maxHeap priority_queue: " << maxQ.size() << endl;
  while (! maxQ.empty()) {
    cout << maxQ.top() << endl;
    maxQ.pop();
  }
}

void test_deque() {
  cout << "==> test_deque" << endl;
  deque<string> q;
  q.push_back("1");
  q.push_back("2");
  cout << "deque: " << q.size() << endl;
  while (! q.empty()) {
    cout << "front: " << q.front() << ", back: " << q.back() << endl;
    q.pop_front();
  }
}

void test_stack() {
  cout << "==> test_stack" << endl;
  stack<int> s;
  s.push(1);
  s.push(2);
  cout << "stack: " << s.size() << endl;

  while (! s.empty()) {
    cout << s.top() << endl;
    s.pop();
  }
}


void test_set() {
  cout << "==> test_set" << endl;
  unordered_set<int> s;
  s.insert(1);
  s.insert(2);
  cout << "set: " << s.size() << endl;

  for (auto it = s.begin(); it != s.end(); ++ it) {
    cout << *it << endl;
  }

  while (!s.empty()) {
    cout << "set: erase " << *s.begin() << endl;
    s.erase(s.begin());
  }
}


void test_map() {
  cout << "==> test_map" << endl;
  unordered_map<string, int> s;
  s["a"] = 1;
  s["b"] = 2;
  cout << "map: " << s.size() << endl;

  while (!s.empty()) {
    cout << "map: erase " << s.begin()->first << ":" << s.begin()->second << endl;
    s.erase(s.begin());
  }
}


void test_dll() {
  cout << "==> test_dll" << endl;
  list<string> lst;
  lst.push_back("1");
  lst.push_back("2");
  cout << "dll: " << lst.size() << endl;

  while (! lst.empty()) {
    cout << "list back: " << lst.back() << endl;
    lst.pop_back();
  }
}


void test_algorithm() {
  cout << "==> test_algorithm" << endl;
  vector<int> nums = {1,4,2,5,-2};

  sort(nums.begin(), nums.end());
  for (int num : nums) cout << num << ",";
  cout << endl;
  
  auto it = find(nums.begin(), nums.end(), 2);
  cout << ((it != nums.end()) ? "found 2" : "2 not found") << endl;

  it = upper_bound(nums.begin(), nums.end(), 2);
  cout << ((it != nums.end()) ? "upper_bound of 2 found: " + to_string(*it) : "not found") << endl;

  sort(nums.rbegin(), nums.rend());
  for (int num : nums) cout << num << ",";
  cout << endl;

  auto it_min = min_element(nums.begin(), nums.end());
  cout << "min element: " << *it_min << endl;

  vector<int> nums2(6);
  copy(nums.begin(), nums.end(), nums2.begin());
  for (int num : nums2) cout << "copy: " << num << ",";
  cout << endl;

  fill(nums2.begin(), nums2.end(), 128);
  for (int num : nums2) cout << "filled: " << num << ",";
  cout << endl;
}

void test_try_catch() {
  try {
    // int a = 1/0;
    // throw exception();
    throw std::invalid_argument("divide by 0");
  } catch (const std::exception &ex) {
    cout << "exception: " << ex.what() << endl;
  }
}

// Class inheritance.
class A {
public:
  A() {
    cout << "class A is created" << endl;
  }

  virtual void bark(const char * const input = nullptr) {
    cout << "hello world" << endl;
  }
};

class B : public A {
public:
  B() {
    cout << "class B is initialized" << endl;
  }

  void bark(const char * const input = nullptr) override {
    if (input == nullptr) {
      cout << "hello from B" << endl;
    } else {
      cout << "hello from B: " << input << endl;
    }
  }
};

// Permutation and combination.
class Stat {
public:
  void permutation(vector<int>& nums) {
    vector<vector<int>> result;
    perm(result, nums, 0);
    dump_result(result);
  }

  void combination(vector<int>& nums, int k) {
    vector<vector<int>> result;
    vector<int> row;
    comb(result, nums, row, k, 0);
    dump_result(result);
  }

private:
  void comb(vector<vector<int>>& result, vector<int>& nums, vector<int>& row, int k, int pos) {
    if (k == (int) row.size()) {
      result.push_back(row);
      return;
    }

    for (int i = pos; i < (int) nums.size(); ++ i) {
      row.push_back(nums[i]);
      comb(result, nums, row, k, i + 1);
      row.pop_back();
    }
  }

  void perm(vector<vector<int>>& result, vector<int>& nums, int pos) {
    if (pos == (int) nums.size()) {
      result.push_back(nums);
      return;
    }

    for (int i = pos; i < (int) nums.size(); ++ i) {
      swap(nums[i], nums[pos]);
      perm(result, nums, pos + 1);
      swap(nums[i], nums[pos]);
    }
  }

  void dump_result(vector<vector<int>>& result) {
    cout << "result (count = " << result.size() << "):" << endl;
    for (const auto& row : result) {
      for (int elem : row) cout << elem << ", ";
      cout << endl;
    }
  }
};


// To execute C++, please define "int main()"
int main() {
  auto words = { "Hello, ", "World!", "\n" };
  for (const char* const& word : words) {
    cout << word;
  }
  test_queue();
  test_priority_queue();
  test_deque();
  test_stack();
  test_set();
  test_map();
  test_dll();
  test_algorithm();
  test_try_catch();

  B b;
  b.bark();
  b.bark("It's Firday");

  Stat stat;
  vector<int> nums = {1,2,3,4};
  stat.permutation(nums);
  stat.combination(nums, 2);

  return 0;
}


/**
Output:

Hello, World!
==> test_queue
queue: 2
1
2
==> test_priority_queue
maxHeap priority_queue: 2
2
1
==> test_deque
deque: 2
front: 1, back: 2
front: 2, back: 2
==> test_stack
stack: 2
2
1
==> test_set
set: 2
2
1
set: erase 2
set: erase 1
==> test_map
map: 2
map: erase b:2
map: erase a:1
==> test_dll
dll: 2
list back: 2
list back: 1
==> test_algorithm
-2,1,2,4,5,
found 2
upper_bound of 2 found: 4
5,4,2,1,-2,
min element: -2
copy: 5,copy: 4,copy: 2,copy: 1,copy: -2,copy: 0,
filled: 128,filled: 128,filled: 128,filled: 128,filled: 128,filled: 128,
exception: divide by 0
class A is created
class B is initialized
hello from B
hello from B: It's Firday
result (count = 24):
1, 2, 3, 4, 
1, 2, 4, 3, 
1, 3, 2, 4, 
1, 3, 4, 2, 
1, 4, 3, 2, 
1, 4, 2, 3, 
2, 1, 3, 4, 
2, 1, 4, 3, 
2, 3, 1, 4, 
2, 3, 4, 1, 
2, 4, 3, 1, 
2, 4, 1, 3, 
3, 2, 1, 4, 
3, 2, 4, 1, 
3, 1, 2, 4, 
3, 1, 4, 2, 
3, 4, 1, 2, 
3, 4, 2, 1, 
4, 2, 3, 1, 
4, 2, 1, 3, 
4, 3, 2, 1, 
4, 3, 1, 2, 
4, 1, 3, 2, 
4, 1, 2, 3, 
result (count = 6):
1, 2, 
1, 3, 
1, 4, 
2, 3, 
2, 4, 
3, 4, 
 */
