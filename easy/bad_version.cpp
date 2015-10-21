// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

// The reason why not using 'mid = (low + high) / 2'
// is that if low and high are both very large,
// their sum will exceed integer limit

class Solution {
public:
  int firstBadVersion(int n) {
    int low = 1, high = n;

    while (low < high) {
      int mid = low + (high - low) / 2;

      if (isBadVersion(mid)) {
        high = mid;
      } else {
        low = mid + 1;
      }
    }

    return low;
  }
};
