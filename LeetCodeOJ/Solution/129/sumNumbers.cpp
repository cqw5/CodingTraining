/*! Source: https://leetcode.com/problems/sum-root-to-leaf-numbers
 *! Author: qwchen
 *! Date  : 2017-4-30
 *  树的根节点到所有叶子结点的路径和
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
 *   先序遍历（深度优先），用一个值来记录路径的当前路径的值，当到达叶子结点时，累加到总和。
 * 时间复杂度：O(n)
 * 空间复杂度：O(logn), 递归栈的深度
 */
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if (root == nullptr) return 0;
        int totalSum = 0;
        int curSum = 0;
        preOrder(root, curSum, totalSum);
        return totalSum;
    }
    
    void preOrder(TreeNode* root, int &curSum, int &totalSum) {
        curSum = curSum * 10 + root->val;
        if (root->left == nullptr && root->right == nullptr) {
            totalSum += curSum;
            return;
        }
        if (root->left) {
            preOrder(root->left, curSum, totalSum);
            curSum /= 10;
        }
        if (root->right) {
            preOrder(root->right, curSum, totalSum);
            curSum /= 10;
        }
    }
};

