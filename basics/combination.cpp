#include <iostream>
#include <vector>

using namespace std;

// Get all 2^n combinations: C(n, 0), C(n, 1), ... C(n, n)
vector<vector<int>> getComb(vector<int>& input) {
  vector<vector<int>> result;

  int n = input.size(), len = 1 << n;
  for (int i = 0; i < len; ++ i) {
    vector<int> row;
    for (int j = 0; j < n; ++ j) {
      if (i & (1 << j)) {
        row.push_back(input[j]);
      }
    }
    result.push_back(row);
  }
  return result;
}

int main() {
  vector<int> input = {1,2,3,4};

  vector<vector<int>> comb = getComb(input);

  int count = 0;
  for (auto c : comb) {
    cout << to_string(++ count) << ": ";
    for (int v : c) cout << v << " ";
    cout << endl;
  }
  return 0;
}
