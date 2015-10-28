/**
 * @Author: zhuangqh
 * @Email: zhuangqhc@gmail.com
 * @Create on: 2015-10-28 22:31:19
 */

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <set>

using namespace std;

class Solution {
public:
  bool wordPattern(string pattern, string str) {
    map<char, string> mp;
    set<string> keyStr;
    istringstream input(str);

    string curStr;
    for (int i = 0; i < pattern.size(); ++i) {
      input >> curStr;
      if (mp.find(pattern[i]) == mp.end()) {
        if (keyStr.find(curStr) != keyStr.end())
          return false;

        mp[pattern[i]] = curStr;
        keyStr.insert(curStr);
      } else if (mp[pattern[i]] != curStr) {
        return false;
      }
    }

    // extra str left
    if (input >> curStr) return false;
    return true;
  }
};