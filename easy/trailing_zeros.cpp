// all zeros are created by 2 * 5.
// obviously, the number of 2 is always more than the number of 5
// so, the number of 5 multiplied is the anwser.

class Solution {
public:
  int trailingZeros(int n) {
    int zeros = 0;
    while (n /= 5) zeros += n;
    return zeros;
  }
};
