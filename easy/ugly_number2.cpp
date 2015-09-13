#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
  int nthUglyNumber(int n) {
    std::vector<int> li;
    li.push_back(1);
    int n2, n3, n5;
    n2 = n3 = n5 = 0;

    while (--n) {
      int m = std::min(2*li[n2], std::min(3*li[n3], 5*li[n5]));

      if ()
    }
  }
};
