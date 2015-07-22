#include <iostream>
#include <string>
#include <stack>

using std::stack;
using std::string;

class Solution {
public:
  bool isValid(string s) {
    stack<char> pool;

    for (auto x : s) {
      if (x == '[' || x == '(' || x == '{') {
        pool.push(x);
      } else if (!pool.empty() && (pool.top() == x-1 || pool.top() == x-2)) {
        pool.pop();
      } else {
        return false;
      }
    }

    return pool.empty();
  }
};

int main() {
  string test("()]");
  Solution a;
  std::cout << (a.isValid(test) ? "True" : "False") << std::endl;
}
