# -*- coding: utf-8 -*-
# 题目：数字以0123456789101112131415…的格式序列化到一个字符序列中。在这个序列中，第5位（从下标0开始计数）是5，第13位是1，第19位是4，等等。
#      请写一个函数，求任意第n位对应的数字。
#


# 思路：https://leetcode-cn.com/problems/shu-zi-xu-lie-zhong-mou-yi-wei-de-shu-zi-lcof/solution/mian-shi-ti-44-shu-zi-xu-lie-zhong-mou-yi-wei-de-6/
#     确定 n 所在 数字 的 位数 ，记为 digit；
#     确定 n 所在的 数字 ，记为 num；
#     确定 n 是 num 中的哪一数位，并返回结果。
class Solution(object):
    def findNthDigit(self, n):
        """
        :type n: int
        :rtype: int
        """
        digit, begin, scale = 1, 1, 9
        count = scale * begin * digit
        while n > count:
            n = n - count
            digit = digit + 1
            begin = begin * 10
            count = scale * begin * digit
        num = begin + (n-1) // digit
        num = str(num)
        res = int(num[(n-1) % digit])
        return res
