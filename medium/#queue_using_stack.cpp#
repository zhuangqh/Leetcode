#include <stack>
#include <vector>

using std::vector;
using std::stack;

class Queue {
private:
  stack<int> data_;
public:
  // Push element x to the back of queue.
  void push(int x) {
    data_.push(x);
  }

  // Removes the element from in front of queue.
  void pop(void) {
    vector<int> container;

    while (data_.size() > 1) {
      container.push_back(data_.top());
      data_.pop();
    }
    data_.pop();
    for (auto it = container.rbegin();
         it != container.rend(); ++it) {
      data_.push(*it);
    }
  }

  // Get the front element.
  int peek(void) {
    stack<int> tmp(data_);

    while (tmp.size() > 1) {
      tmp.pop();
    }

    return tmp.top();
  }

  // Return whether the queue is empty.
  bool empty(void) {
    return data_.empty();
  }
};
