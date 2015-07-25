#include <iostream>
#include <cmath>

class Solution {
public:
  double myPow(double x, int n) {
    if (n < 0) {
      return 1.0 / Pow(x, -n);
    } else {
      return Pow(x, n);
    }
  }
  double Pow(double x, int n) {
    if (n == 0)
      return 1;
    if (n % 2 == 0) {
      return myPow(x * x, n / 2);
    } else {
      return myPow(x * x, n / 2) * x;
    }
  }
};

int main() {
  Solution a;
  std::cout << a.myPow(34.00515, -3) << std::endl;
}
