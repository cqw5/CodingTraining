# Author: qwchen
# Date  : 2016-11-8
# 31：连续子数组的最大和
# -*- coding:utf-8 -*-

class Solution:
    def FindGreatestSumOfSubArray(self, array):
        if (array is None) or (len(array) == 0):
            return 0
        maxSum = array[0]
        currentSum = 0
        for elem in array:
            if currentSum <= 0:
                currentSum = elem
            else:
                currentSum += elem
            if currentSum > maxSum:
                maxSum = currentSum
        return maxSum
    