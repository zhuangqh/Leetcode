class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        table = {
            'I': 1,
            'V': 5,
            'X': 10,
            'L': 50,
            'C': 100,
            'D': 500,
            'M': 1000
        }
        ans = 0
        for index in range(len(s)):
            if index < len(s) - 1 and table[s[index]] < table[s[index+1]]:
                ans -= table[s[index]]
            else:
                ans += table[s[index]]

        return ans
