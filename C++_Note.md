# C++ Notes

### concatenate strings in an array

``
string words[] = {"ab", "c"};
string result = accumulate(words.begin(), words.end(), string{}); // "abc"

```

### replace char

Replace all occurences of 'a' by 'x'.
```
#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string str = "hello world";
    std::replace(str.begin(), str.end(), 'o', 'x'); // Replace all 'o' with 'x'
    std::cout << str << std::endl; // Output: hellx wxrld
    return 0;
}
```

Replace a string:
```
#include <iostream>
#include <string>

int main() {
    std::string str = "hello world";
    str.replace(6, 5, "there"); // Replace "world" (starting at index 6, length 5) with "there"
    std::cout << str << std::endl; // Output: hello there
    return 0;
}
```

### split function

  1) split with delimiter char.
```
    void split(string data, vector<string> &vals, char delim) {
        stringstream ss(data);
        string val;
        while (std::getline(ss, val, delim)) {
            vals.push_back(val);
        }
    }
```

  2) split with blank space.
```
    void split(string data, vector<string> &vals) {
        stringstream ss(data);
        string val;
        while (ss >> val) {
            vals.push_back(val);
        }
    }
```

  3) split with multiple characters
  
    Use strtok() if don't need delimiters, or use custom function.
    See: https://github.com/chenx/oj/blob/master/misc/strtok.cpp

  4) split with string
```
// for string delimiter
// https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c
std::vector<std::string> split(std::string s, std::string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    std::string token;
    std::vector<std::string> res;

    while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    return res;
}
 ```   
  
### Create priority queue

  1) int
```
  max heap: priority_queue<int, vector<int>, std::less<int>> maxPQ;
  min heap: priority_queue<int, vector<int>, std::greater<int>> minPQ;
```

  2) node
```
  priority_queue<ListNode *, vector<ListNode *>, comp> minPQ;
  
  class comp {
  public:    
      bool operator()(const ListNode * a, const ListNode * b) const {
          return a->val > b->val; // min heap.
      }
  };
```

  3) use make_heap
```
  vector<ListNode *> h;
  make_heap(h.begin(), h.end(), cmp);
  
  bool cmp(const ListNode * a, const ListNode * b) {
      return a->val > b->val;
  }
```

In summary, a default std::priority_queue<int> behaves as follows:
- It stores int values.
- It uses a std::vector<int> internally to manage the elements.
- It functions as a max-heap, meaning the largest integer will always be accessible at the top using top().
- The comparison is based on std::less<int>, which orders elements in ascending order for the underlying container, but results in a max-heap structure for the priority queue's interface.

### Sort with custom comparator

https://ayanc.medium.com/passing-custom-parameter-in-c-custom-comparator-81e4daaf25a4

For vector container, use a "static bool comp()" function in the same class; or a struct/class (either an inner class or outer class), but needs to be a class object.

For non-vector container, such as priority_queue above, use a struct/class, just the struct/class name will work.

```
class Solution() {
public:
  void func() {
    vector<vector<int>> arr = {{1,2}, {0, 1}};
    sort(arr.begin(), arr.end(), comp);
    // sort(arr.begin(), arr.end(), comp2());
  }

  static bool comp(vector<int>& a, vector<int>& b) {
    return a[0] < b[0];
  }

  struct comp2 {
    bool operator()(vector<int>& a, vector<int>& b) {
      return a[0] < b[0];
    }
  };
};
```

For priority_queue, if need to pass a parameter to the comparator, do it this way:
```
    // Custom Comparator Class with Parameters.
    int swimInWater(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) return 0;

        int m = grid.size(), n = grid[0].size();

        Comp comp(grid); // <--
        priority_queue<vector<int>, vector<vector<int>>, Comp> minHeap(comp); // <--

        return 0;
    }

    struct Comp {
        vector<vector<int>> grid;

        Comp(vector<vector<int>>& grid) : grid(grid) {} // pass in parameter

        bool operator()(vector<int>& a, vector<int>& b) {
            return grid[a[0]][a[1]] > grid[b[0]][b[1]];
        }
    };
```

Or use lambda function with captured variables:
```
    int swimInWater(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) return 0;

        int m = grid.size(), n = grid[0].size();

        // use reference "&grid" to avoid making a copy.
        auto comp = [&grid](vector<int>& a, vector<int>& b) {.
            return grid[a[0]][a[1]] > grid[b[0]][b[1]];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> minHeap(comp);
    }
```

Note:
- Capture by reference ([&]):
  - Allows the lambda to access variables from its enclosing scope by reference.
- Parameter by reference ((int& param)):
  - Allows the lambda to receive arguments passed to it during invocation by reference.

### Create pair

  1) pair<int, int> v = pair<int, int>(1, 2);
  2) auto v = make_pair(1, 2); // note the use of auto keyword.
  3) pair<int, int> v = {1, 2); // C++ 20
  

### Convert int to string

  1) A quick way: std::to_string(type val)
  Type can be int, long, double etc. 
  
  See: http://www.cplusplus.com/reference/string/to_string/
  
  2) 
```
    int toInt(string s) {
        stringstream iss(s); // istringstream works too.
        int val;
        iss >> val;
        return val;
    }
```

  3) 
```
    int toInt(string s) {
        int val = 0, i = 0, val0;
        bool neg = s[0] == '-';
        if (neg) ++ i;
        else if (s[0] == '+') ++ i;
        
        for (; i < s.length(); ++ i) {
            val0 = val;
            val = val * 10 + s[i] - '0';
            if (val / 10 != val0) throw overflow_error();
        }
        
        if (neg) val = - val;
        return val;
    }
```

### Convert char to string

1) Using std::string constructor:
```
  std::string s(1, 'A'); // Creates a string with one 'A'
```

2) Using std::string initializer list:
```
  std::string s = {c};
```

3) Using push_back() method:
```
  std::string s;
  s.push_back('A);
```

4) Using std::format() (C++20 and later):
```
std::string s = std::format("{}", 'A'); // Formats 'A' into a string
```
  
### Convert string to int/long/long-long:
```
  std::stoi(string val)
  std::stol(stirng val)
  std::stoll(string val)
```
  See: http://en.cppreference.com/w/cpp/string/basic_string/stol


### Difference of stringstream, istringstream and ostringstream

  - Stringstream is bigger. The other two make code more readable.
  - They can be interchangeable. 
  - E.g., in the split functions above, replace stringstream with istringstream is ok too.
  
  
### keyword "auto" started in C++11.


### set / map / unordered_map
  - set/map/unordered_set/unordered_map contains a "count()" method to judge if an element exists.
    - so instead of using: x.find(e) != x.end(), one can now use: x.count(e) > 0
  - There is a contains() method since C++20, so one can use: x.contains(e) 
  
### string.length() type is: std::basic_string<char>::size_type
  - so max or min(int, string.length()) will report error such as:
     no matching function for call to ‘min(int&, std::basic_string<char>::size_type)’
  - so you need to do a cast here: min(int, (int) string.length())
  
  
### Some built-in functions (so no need to re-invent wheel):
  isspace, ispunct, isdigit, isalpha, isalnum, islower, isupper, tolower, toupper
  
  See: http://www.cplusplus.com/reference/cctype/


### Multiset, lower_bound(), upper_bound(), std::distance().
  See implementation in https://github.com/chenx/oj/blob/master/leetcode/CountOfRangeSum.cpp


### Intialize vector
  - In C++03: vector<int> v; v.push_back(1);
  - In C++11: vector<int> v {1};
  
  See: http://www.informit.com/articles/article.aspx?p=1852519
  

### Find substring in a string: string.find(string s, int start_pos);
```
  string s = "abcb";
  int pos = s.find("b", 0); // returns 1.
  pos = s.find("b", 1); // returns 1.
  pos = s.find("b", 2); // returns 3.
  pos = s.find("d", 0); // returns string::npos = 18446744073709551615
```
  See: http://www.cplusplus.com/reference/string/string/find/
  
  
### Return a string made of n repeated characters c:
```
  char c = 'a';
  int n = 3;
  string s = string(n, c);  // s = "aaa".
```

### Simple way to print a number in binary format.
```
  int n = 100;
  cout << bitset<8>(n) << endl;
```

### Erase() of set, map, multiset.
```
  For set and map, erase using iterator or value both work.
  If use value, when the value does not exist nothing happens;
  If use iterator, when the iterator is NULL, it'll raise an error.

  However, for multiset, which can contain duplicates,
  use value will remove all elements with such value;
  use iterator will remove the first element found with such value.
```
  
### Template function.

Use this to avoid writing different functions for different data types:
```
    template<typename T>
    void dump(vector<T> v) {
        for (int i = 0; i < v.size(); ++ i) {
            cout << v[i] << " ";
        }
        cout << endl;
    }
```

### substr

substr(): used in C++ and JavaScript
- std::string substr (size_type startIndex = 0, size_type len = npos) const;
- substr(startIndex)  // starting at pos, until end of string

substring(): used in Java and JavaScript
- substring(startIndex, endIndex)

Or:
- C++: substr()
- Java: substring()
- JavaScript: both substr() and substring()


### accumulate()
- std::int accumulate(begin, end, init, [func]);  // init is 0 by default.

### splice()

- list::splice(): 
  - Allows for the efficient transfer of elements between lists or within the same list. 
    Unlike copying or moving elements, splice() only rearranges the internal pointers of the list nodes, 
    making it a constant-time operation for transferring single elements or entire lists (though range 
    splicing might have different complexities depending on the specific std::list implementation and C++ standard).

  - entire list (1): void splice (iterator position, list& x);
    Transfers all elements from list x into *this (the current list) before the element pointed to by position. 
    After the operation, x becomes empty. Transferring a single element.
  
  - single element (2): void splice (iterator position, list& x, iterator i);
    Transfers the single element pointed to by it from list x into *this before the element pointed to by position. 
    Transferring a range of elements.
  
  - element range (3): void splice (iterator position, list& x, iterator first, iterator last);
    Transfers the elements in the range [first, last) from list x into *this before the element pointed to by position.
    

### std::multiset

In C++, std::multiset is an associative container provided by the Standard Template Library (STL) that stores elements in a sorted order. It is similar to std::set, but with a key distinction: std::multiset allows for the storage of duplicate elements.

Key characteristics of std::multiset:
- Sorted Order
- Associative Container:
  - Elements are stored in a way that allows for efficient retrieval based on their values, which serve as the keys.
- Logarithmic Complexity:
  - Search, insertion, and removal operations typically have logarithmic time complexity (O(log n)), due to its usual implementation as a self-balancing binary search tree (e.g., a red-black tree).
  - Eements are automatically sorted based on their values, using a comparison function (by default, std::less<Key>).
- Duplicate Elements:
  - Unlike std::set, std::multiset allows multiple elements with equivalent values to be stored.
- The **std::multiset::lower_bound** function in C++ STL. It returns an iterator to the first element whose value is greater than or equal to the specified key.
- The **std::multiset::upper_bound** member function of the std::multiset container in C++. It returns an iterator pointing to the first element in the multiset that is greater than a specified key.


### std::distance

The distance between two iterators is calculated using the std::distance function, which is available in the &lt;iterator> header. This function determines the number of elements between the first and last iterators in a given range.

