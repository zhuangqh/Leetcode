#include <iostream>
#include <queue>
#include <vector>

using std::vector;
using std::queue;

class Stack {
private:
  queue<int> data_;
public:
  // Push element x onto stack.
  void push(int x) {
    data_.push(x);
  }

  // Removes the element on top of the stack.
  void pop() {
    vector<int> container;

    while (data_.size() > 1) {
      container.push_back(data_.front());
      data_.pop();
    }
    data_.pop();
    for (auto it = container.begin();
         it != container.end(); ++it) {
      data_.push(*it);
    }
  }

  // Get the top element.
  int top() {
    queue<int> tmp(data_);

    while (tmp.size() > 1) {
      tmp.pop();
    }

    return tmp.front();
  }

  // Return whether the stack is empty.
  bool empty() {
    return data_.empty();
  }
};
