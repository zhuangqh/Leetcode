#include <iostream>

class Solution {
public:
  bool isPalindrome(int x) {
    if (x < 0) return false;

    int num = x;
    int reverse_x = 0;
    while (num) {
      reverse_x = reverse_x * 10 + num % 10;
      num /= 10;
    }

    return x == reverse_x;
  }
};

int main() {
  Solution a;
  std::cout << (a.isPalindrome(1) ? "True\n" : "False\n" );
  return 0;
}
