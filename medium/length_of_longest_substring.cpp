class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int pos[256]; // appearance of char
        memset(pos, -1, sizeof(int)*256);
        int begin = 0; // begin of current substring
        int ans = 0;
        
        for (int cur = 0; cur < s.length(); ++cur) {
            if (pos[s[cur]] >= begin) {
                begin = pos[s[cur]] + 1;
            }
            if (cur - begin + 1 > ans) {
                ans = cur - begin + 1;
            }
            pos[s[cur]] = cur;
        }
        return ans;
    }
};
