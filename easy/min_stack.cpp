#include <iostream>
#include <stack>
#include <climits>

using std::stack;

// copy from others
class MinStack {
public:
  stack<int> S;
  stack<int> S_min;
public:
  void push(int x) {
    S.push(x);
    if (x <= getMin())
      S_min.push(x);
  }
  void pop() {
    if (S.top() == getMin()) S_min.pop();
    S.pop();
  }
  int top() {
    return S.top();
  }
  int getMin() {
    if (S_min.empty()) return INT_MAX;
    return S_min.top();
  }
};
