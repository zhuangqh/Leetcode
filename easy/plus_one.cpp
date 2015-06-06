#include <vector>
#include <deque>
class Solution {
public:
  std::vector<int> plusOne(std::vector<int>& digits) {
    std::deque<int> store(digits.begin(), digits.end());
    digits.resize(0);
    std::deque<int>::reverse_iterator it = store.rbegin();
    ++(*it);
    if (store.size() == 1 && *it == 10) {
      digits.push_back(1);
      digits.push_back(0);
      return digits;
    }
    for (it = ++store.rbegin(); it != store.rend(); ++it) {
      *it += *(it - 1) / 10;
      *(it - 1) %= 10;
      if (it == (--store.rend()) && *it >= 10) {
        *it %= 10;
        store.push_front(1);
        break;
      }
    }
    std::deque<int>::iterator itt = store.begin();
    for (; itt != store.end(); ++itt) {
      digits.push_back(*itt);
    }
    return digits;
  }
};
