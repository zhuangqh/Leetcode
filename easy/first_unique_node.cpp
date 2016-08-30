struct node {
    int appr;
    int idx;
    node() {
        this->appr = 0;
        this->idx = -1;
    }
};
class Solution {
public:
    int firstUniqChar(string s) {
        node record[26];
        
        for (int i = 0; i < s.length(); ++i) {
            ++record[s[i] - 'a'].appr;
            if (record[s[i] - 'a'].idx == -1) {
                record[s[i] - 'a'].idx = i;
            }
        }
        
        int ans = s.length();
        for (int i = 0; i < 26; ++i) {
            if (record[i].appr == 1) {
                if (record[i].idx < ans)
                    ans = record[i].idx;
            }
        }
        return ans == s.length() ? -1 : ans;
    }
};
