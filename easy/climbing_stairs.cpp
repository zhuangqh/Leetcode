#include <iostream>
#include <vector>
class Solution {
public:
  int climbStairs(int n) {
    std::vector<int> store(n + 1);
    store[1] = 1;
    store[2] = 2;
    for (int i = 3; i <= n; ++i) {
      store[i] = store[i - 1] + store[i - 2];
    }
    return store[n];
  }
};
int main() {
  Solution a;
  std::cout << a.climbStairs(5) << std::endl;
  return 0;
}
