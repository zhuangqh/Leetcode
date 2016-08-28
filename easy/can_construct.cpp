class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int count[256];
        memset(count, 0, sizeof(int)*256);
        for (int i = magazine.length() - 1; i >= 0; --i) {
            ++count[magazine[i]];
        }
        for (int i = ransomNote.length() - 1; i >= 0; --i) {
            --count[ransomNote[i]];
        }
        for (int i = 0; i < 256; ++i) {
            if (count[i] < 0) return false;
        }
        return true;
    }
};
