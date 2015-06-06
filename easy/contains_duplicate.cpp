#include <iostream>
#include <vector>
#include <set>
class Solution {
public:
  bool containsDuplicate(std::vector<int>& nums) {
    std::set<int> ss;
    std::vector<int>::iterator vit;
    std::set<int>::iterator sit;
    for (vit = nums.begin(); vit != nums.end(); ++vit) {
      if (ss.find(*vit) == ss.end()) {
        ss.insert(*vit);
      } else {
        return true;
      }
    }
    return false;
  }
};
