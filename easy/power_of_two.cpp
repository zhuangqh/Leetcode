#include <iostream>

class Solution {
public:
    bool isPowerOfTwo(int n) {
        int count = 0;
        if (n <= 0) return false;
        for (int i = 0; i < 32; ++i) {
            if (n & 1)
                ++count;
            if (count >= 2) return false;

            n >>= 1;
        }
        return true;
    }
};

int main() {
    Solution a;
    for (int i = 0; i < 8; ++i) {
        std::cout << a.isPowerOfTwo(i) << std::endl;
    }
    return 0;
}
