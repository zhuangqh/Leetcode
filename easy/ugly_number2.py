class Solution(object):
    def nthUglyNumber(self, n):
        """
        :type n: int
        :rtype: int
        """
        i2, i3, i5 = 0, 0, 0
        li = [1]
        while n > 1:
            n2, n3, n5 = 2*li[i2], 3*li[i3], 5*li[i5]
            m = min(n2, n3, n5)

            if m == n2:
                i2 += 1
            if m == n3:
                i3 += 1
            if m == n5:
                i5 += 1
            li.append(m)
            n -= 1

        return li[-1]
