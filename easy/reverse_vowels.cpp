class Solution {
public:
    string reverseVowels(string s) {
        int ptr1 = 0;
        int ptr2 = s.size() - 1;
        const char* vowels = "aeiouAEIOU";
        
        while (ptr1 < ptr2) {
            if (!getNextVowel1(ptr1, ptr2, s, vowels)) break;
            if (!getNextVowel2(ptr1, ptr2, s, vowels)) break;
            
            char tmp = s[ptr1];
            s[ptr1] = s[ptr2];
            s[ptr2] = tmp;
            ++ptr1;
            --ptr2;
        }
        return s;
    }
    bool getNextVowel1(int& ptr1, int ptr2, string& s, const char *vowels) {
        int tmp = ptr1;
        while (tmp < ptr2) {
            if (strchr(vowels, s[tmp])) {
                ptr1 = tmp;
                return true;
            }
            ++tmp;
        }
        return false;
    }
    bool getNextVowel2(int ptr1, int& ptr2, string& s, const char *vowels) {
        int tmp = ptr2;
        while (ptr1 < tmp) {
            if (strchr(vowels, s[tmp])) {
                ptr2 = tmp;
                return true;
            }
            tmp--;
        }
        return false;
    }
};
