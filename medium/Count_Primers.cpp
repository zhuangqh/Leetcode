#include <iostream>
#include <cstring>
using namespace std;
class Solution {
public:
  int countPrimes(int n) {
    //Eratosthenes
    int count = 0;
    bool *isnprime = new bool[n];
    memset(isnprime, false, sizeof(isnprime));
    for (int i = 2; ; ++i) {
      if (i * i >= n && !isnprime[i]) break;
      for (int j = 2; j * i < n; ++j) {
        isnprime[j*i] = true;
      }
    }
    for (int i = 2; i < n; ++i) {
      if (!isnprime[i]) count++;
    }
    return count;
  }
};
//test code
int main() {
  Solution a;
  cout << a.countPrimes(5) << endl;
  return 0;
}
