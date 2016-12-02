# Author: qwchen
# Date  : 2016-12-02
# -*- coding:utf-8 -*-
# 63. 二叉搜索树的第k个结点
# 题目描述
#   给定一颗二叉搜索树，请找出其中的第k大的结点。例如， 5 / \ 3 7 /\ /\ 2 4 6 8 中，按结点数值大小顺序第三个结点的值为4。

class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def KthNode(self, pRoot, k):
        if (pRoot is None) or (k <= 0):
            return None;
        kth, i = self.inOrder(pRoot, 1, k)
        return kth
        
    def inOrder(self, pRoot, i, k):
        if pRoot is None:
            return None, i
        left, i = self.inOrder(pRoot.left, i, k)
        if left is not None:
            return left, i
        if i == k:
            return pRoot, i
        else:
            i += 1
        right, i = self.inOrder(pRoot.right, i, k)
        if right is not None:
            return right, i
        return None, i

    