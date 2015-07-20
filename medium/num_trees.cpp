#include <vector>
#include <iostream>

using std::vector;

class Solution {
public:
  int numTrees(int n) {
    if (n <= 0) return 0;

    vector<int> vec(n + 1, 0);

    vec[0] = 1;

    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= i; ++j) {
        vec[i] += vec[j-1] * vec[i-j];
      }
    }

    return vec[n];
  }
};

int main() {
  Solution a;
  vector<int> test{1, 2, 3, 4, 5};
  for (auto it = test.begin(); it != test.end(); ++it) {
    std::cout << a.numTrees(*it) << " ";
  }
  std::cout << std::endl;
}
