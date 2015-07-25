#include <stack>
#include <string>
#include <iostream>
#include <map>

using std::map;
using std::stack;
using std::string;

class Solution {
public:
  int calculate(string s) {
    // infix expression to post expression
    stack<char> ops;
    string postfix;

    // set priority
    map<char, int> prior;
    prior['+'] = 0, prior['-'] = 0;
    prior['*'] = 1, prior['/'] = 1;
    prior['('] = 2;

    for (auto x : s) {
      if (x == ' ') continue;
      if (x >= '0' && x <= '9') {
        postfix += x;
        continue;
      } else if (x == ')') {

        while (ops.top() != '(') {  // handle a pair of ()
          postfix += ops.top();
          ops.pop();
        }
        ops.pop();
      } else if (ops.empty()) {  // stack of operators is empty
        ops.push(x);
      } else {  // stack of operators is not empty

        while (!ops.empty() && ops.top() != '('
               && prior[x] <= prior[ops.top()]) {
          postfix += ops.top();
          ops.pop();
        }
        ops.push(x);
      }
      postfix += ' ';
    }

    // the input is empty. pop the entire operators.
    while (!ops.empty()) {
      postfix += ops.top();
      ops.pop();
    }

    // compute postfix expression
    stack<int> nums;
    int sum = 0;

    for (auto x = postfix.begin(); x != postfix.end(); ++x) {
      if (*x == ' ') continue;
      if (*x >= '0' && *x <= '9') {
        while (*x >= '0' && *x <= '9') {
          sum = sum * 10 + (*x - '0');
          ++x;
        }
        --x;
        nums.push(sum);
        sum = 0;
      } else {
        int operand1, operand2;
        operand1 = nums.top();
        nums.pop();
        operand2 = nums.top();
        nums.pop();

        // compute
        if (*x == '+')
          nums.push(operand2 + operand1);
        else if (*x == '-')
          nums.push(operand2 - operand1);
        else if (*x == '*')
          nums.push(operand2 * operand1);
        else
          nums.push(operand2 / operand1);
      }
    }

    return nums.top();
  }
};

int main() {
  Solution a;
  string tmp = "0-2147483647";
  std::cout << a.calculate(tmp) << std::endl;
}
