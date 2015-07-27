#include <vector>
#include <iostream>
using std::vector;

class Solution {
public:
  bool isHappy(int n) {
    vector<bool> hashTable(false, 730);  // 9*9*9 = 729

    while (1) {
      if (n == 1) return true;

      int sum = 0;
      while (n) {
        sum += (n % 10) * (n % 10);
        n /= 10;
      }
      n = sum;

      if (hashTable[n]) {
        return false;
      } else {
        hashTable[n] = true;
      }
    }
  }
};

int main() {
  Solution a;
  std::cout << a.isHappy(2291) << std::endl;
}
