#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution {
public:
  string getPermutation(int n, int k) {
    // fact
    int fact[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

    string dict(n, ' ');
    for (int i = 1; i <= n; ++i)
      dict[i-1] = i + '0';

    --k;

    string ans(n, ' ');
    for (int i = 0; i < n; ++i) {
      int select = k / fact[i];
      k %= fact[i];
      ans[i] = dict[select];
      dict.erase(next(dict.begin(), select));
    }

    return ans;
  }
};


int main() {
  Solution a;
  for (int i = 1; i <= 24; ++i) {
    cout << a.getPermutation(4, i) << endl;
    }

  return 0;
}
