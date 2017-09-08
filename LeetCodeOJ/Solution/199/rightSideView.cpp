/*! Source: https://leetcode.com/problems/binary-tree-right-side-view
 *! Author: qwchen
 *! Date  : 2017-9-8
 *  二叉树的右视图
 *  给定一颗二叉树，假设你站在它的右边，返回你看点的节点
 *  如：
 *     [1]           <---
 *    /   \
 *   2    [3]        <---
 *    \     \
 *     5    [4]      <---
 *      \
 *      [6]          <---
 * 返回：[1,3,4,6]
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
 * 思路：
 *   本题就是要获得二叉树每一层最后一个节点，如果进行先序遍历，并且先右后左，就可以理解为求每一层第一个节点了。
 *   我们通过比较层号与结果数组的元素个数，当层号大于结果数组元素个数时，才存放当前节点
 * 时间复杂度：O(n)
 * 空间复杂度：O(logn)
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        int level = 1;
        preOrder(root, level, res);
        return res;
    }
    
    void preOrder(TreeNode* root, int level, vector<int>& res) {
        if(root == nullptr) return;
        if(level > res.size()) res.push_back(root->val);  // 关键
        preOrder(root->right, level+1, res);
        preOrder(root->left, level+1, res);
    }
};

