#include <iostream>

class Solution {
public:
  bool isUgly(int num) {
    int x[3] = {2, 3, 5};
    for (int i = 0; i < 3; ++i) {
      while (num % x[i] == 0) {
        num /= x[i];
      }
    }

    return num == 1;
  }
};

int main() {
  Solution a;
  std::cout << a.isUgly(1) << a.isUgly(7) << std::endl;

  return 0;
}
