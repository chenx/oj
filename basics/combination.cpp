#include <iostream>
#include <vector>

using namespace std;

void getComb(vector<int>& input, vector<int> output, int pos, vector<vector<int>>& result, int k) {
  if (pos == k) {
    result.push_back(output);
    return;
  }

  for (int i = 0; i < input.size(); ++ i) {
      output[pos] = input[i];
      vector<int> input2(input.begin() + i + 1, input.end()); // include elements [i+1, ...]
      getComb(input2, output, pos + 1, result, k);
  }
}
vector<vector<int>> getCombinations(vector<int>& input, int k) {
  vector<vector<int>> result;
  vector<int> output(k);

  getComb(input, output, 0, result, k);

  return result;
}


// Get all 2^n combinations: C(n, 0), C(n, 1), ... C(n, n)
vector<vector<int>> getAllCombinations(vector<int>& input) {
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

  vector<vector<int>> comb = getAllCombinations(input);
  // vector<vector<int>> comb = getAllCombinations(input, 2); // C(n, k)

  int count = 0;
  for (auto c : comb) {
    cout << to_string(++ count) << ": ";
    for (int v : c) cout << v << " ";
    cout << endl;
  }
  return 0;
}
