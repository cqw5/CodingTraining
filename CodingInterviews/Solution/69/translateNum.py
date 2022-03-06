# -*- coding: utf-8 -*-
# 题目：给定一个数字，我们按照如下规则把它翻译为字符串：0 翻译成 “a” ，1 翻译成 “b”，……，11 翻译成 “l”，……，25 翻译成 “z”。一个数字可能有多个翻译。
#      请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法。
#      https://leetcode-cn.com/problems/ba-shu-zi-fan-yi-cheng-zi-fu-chuan-lcof/


# 思路：https://leetcode-cn.com/problems/ba-shu-zi-fan-yi-cheng-zi-fu-chuan-lcof/solution/mian-shi-ti-46-ba-shu-zi-fan-yi-cheng-zi-fu-chua-6/
class Solution(object):
    def translateNum(self, num):
        """
        :type num: int
        :rtype: int
        """
        num = str(num)
        if len(num) <= 1:
            return 1
        dp = [0] * len(num)
        dp[0] = 1
        dp[1] = 2 if self.isNum(num[0], num[1]) else 1
        for i in range(2, len(num)):
            if self.isNum(num[i-1], num[i]):
                dp[i] = dp[i-1] + dp[i-2]
            else:
                dp[i] = dp[i-1]
        return dp[-1]

    def isNum(self, a, b):
        c = int(a+b) 
        if c >= 10 and c <= 25:
            return True
        else:
            return False
