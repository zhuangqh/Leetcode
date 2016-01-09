// create on 2016-01-09 20:39

#include <iostream>
#include <cmath>

class Solution {
public:
  bool isPowerOfThree(int n) {
    return n > 0 ? !(1162261467 % n) : false;
  }
};
