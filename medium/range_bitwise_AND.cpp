#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int rangeBitwiseAnd(int m, int n) {
    int bit[32] = {0};

    int len = 0;
    while (m) {
      bit[len++] = m & 1;
      m >>= 1;
    }

    for (int i = 0; i < len; ++i) {

    }
  }
};
