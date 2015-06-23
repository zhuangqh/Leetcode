#include <iostream>
#include <string>
#include <set>
#include <queue>
#include <unordered_set>
using namespace std;
class Solution {
public:
  int ladderLength(string begin, string end, unordered_set<string>& dict) {
    if (begin.size() != end.size()) return 0;
    if (begin.empty() || end.empty()) return 0;

    queue<string> path;
    path.push(begin);
    int level = 1;
    int count = 1;  //count for the nodes in this level
    dict.erase(begin);
    while(dict.size() && !path.empty()) {
      string curword = path.front();
      path.pop();
      count--;
      for(int i = 0; i < curword.size(); i++) {
        string tmp = curword;
        for(char j='a'; j<='z'; j++) {
          if(tmp[i]==j) continue;
          tmp[i] = j;
          if(tmp==end) return level+1;
          if(dict.find(tmp) != dict.end()) path.push(tmp);
          dict.erase(tmp);
        }
      }
      if(count==0) {
        count = path.size();
        level++;
      }
    }
    return 0;

  }
};
