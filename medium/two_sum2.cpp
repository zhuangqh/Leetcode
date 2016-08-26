#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    int prev = 0;
    int post = numbers.size() - 1;
    int sum = 0;

    while (prev < post && (sum = numbers[prev] + numbers[post]) != target) {
      if (sum > target) --post;
      if (sum < target) ++prev;
    }

    return vector<int>{prev + 1, post + 1};
  }
};

int main() {
  vector<int> a = {0, 0, 0, 2, 3, 4, 9, 9, 9};
  Solution b;
  vector<int> ans = b.twoSum(a, 7);
  cout << ans[0] << " " << ans[1] << endl;
}
