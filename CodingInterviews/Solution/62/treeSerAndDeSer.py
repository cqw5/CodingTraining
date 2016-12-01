# Author: qwchen
# Date  : 2016-12-01
# -*- coding:utf-8 -*-
#
# 62. 序列化二叉树
# 题目描述
# 请实现两个函数，分别用来序列化和反序列化二叉树

class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def Serialize(self, root):
        if root is None:
            return None
        list_str = self.Serialize2(root)
        return ','.join(list_str)
                
    def Serialize2(self, root):
        if root is None:
            return ['#'];
        list_str = [str(root.val)]
        list_str.extend(self.Serialize2(root.left))
        list_str.extend(self.Serialize2(root.right))
        return list_str
    
    def Deserialize(self, s):
        if s is None:
            return None;
        s = s.split(',')
        root, i = self.Deserialize2(s, 0)
        return root
        
    def Deserialize2(self, s, i):
        if i >= len(s) or s[i] == '#':
            return None, i+1
        root = TreeNode(int(s[i]))
        i += 1
        root.left, i = self.Deserialize2(s, i)
        root.right, i = self.Deserialize2(s, i)
        return root, i

        