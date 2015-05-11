#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  int singleNumber(vector<int>& nums) {
    int ans = 0;
    vector<int>::iterator it = nums.begin();
    for (; it != nums.end(); ++it) {
      ans ^= *it;
    }
    return ans;
  }
};
