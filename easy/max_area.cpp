#include <vector>
#include <algorithm>
#include <iostream>

using std::max;
using std::min;
using std::vector;

class Solution {
public:
  int maxArea(vector<int>& height) {
    int max_area = 0,
      i = 0,
      j = height.size() - 1;

    while (i < j) {
      max_area = max(max_area, min(height[i], height[j]) * (j - i));
      height[i] > height[j] ? --j : ++i;
    }

    return max_area;
  }
};

int main() {
  vector<int> test{1, 2, 4, 3};
  Solution a;
  std::cout << a.maxArea(test) << std::endl;
}
