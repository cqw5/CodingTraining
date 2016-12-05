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
        list_str = []
        self.Serialize2(list_str, root)  # 利用Python复杂数据类型默认传引用的特点
        return ','.join(list_str)
                
    def Serialize2(self, list_str, root):
        if root is None:
            return list_str.append('#')
        list_str.append(str(root.val))
        self.Serialize2(list_str, root.left)
        self.Serialize2(list_str, root.right)
    
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

        