//
// Use std::next_permutation
//
#include <iostream>
#include <vector>
#include <algorithm> // For std::next_permutation and std::sort

int main() {
    std::vector<int> numbers = {1, 2, 3, 4};
    int k = 2; // Choose combinations of size 2

    // Create a boolean mask: 'true' for selected elements, 'false' for unselected
    std::vector<bool> v(numbers.size());
    std::fill(v.begin() + numbers.size() - k, v.end(), true); // Mark 'k' elements as true

    do {
        for (int i = 0; i < numbers.size(); ++i) {
            if (v[i]) {
                std::cout << numbers[i] << " ";
            }
        }
        std::cout << std::endl;
    } while (std::next_permutation(v.begin(), v.end()));

    return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//
// Recursion.
//
#include <iostream>
#include <vector>
#include <algorithm> // For std::sort

void generateCombinations(const std::vector<int>& elements, int k, int start_index,
                          std::vector<int>& current_combination) {
    if (current_combination.size() == k) {
        // Found a combination, print or store it
        for (int element : current_combination) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
        return;
    }

    for (int i = start_index; i < elements.size(); ++i) {
        current_combination.push_back(elements[i]);
        generateCombinations(elements, k, i + 1, current_combination); // Recursively call for next element
        current_combination.pop_back(); // Backtrack
    }
}

int main() {
    std::vector<int> numbers = {1, 2, 3, 4};
    int k = 2; // Choose combinations of size 2

    // Sort the elements to ensure unique combinations if there are duplicates
    std::sort(numbers.begin(), numbers.end());

    std::vector<int> current_combination;
    generateCombinations(numbers, k, 0, current_combination);

    return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//
// Simulation.
//

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

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
