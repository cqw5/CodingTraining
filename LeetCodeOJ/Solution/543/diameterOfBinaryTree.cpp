/*! Source: https://leetcode-cn.com/problems/diameter-of-binary-tree/
 *! Author: qwchen
 *! Date  : 2022-04-17
 *  二叉树的直径
 * 给定一棵二叉树，你需要计算它的直径长度。一棵二叉树的直径长度是任意两个结点路径长度中的最大值。这条路径可能穿过也可能不穿过根结点。
 * 注意：两结点之间的路径长度是以它们之间边的数目表示。
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

/*
 * 思路：
 *   此题与求树的高度类似
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        high(root);
        return maxLen;
    }

private:
    int maxLen = 0;
    int high(TreeNode* root) {
        if (root == nullptr) return 0;
        int leftHigh = high(root->left);
        int rightHigh = high(root->right);
        if (leftHigh + rightHigh > maxLen) {
            maxLen = leftHigh + rightHigh;
        }
        return max(leftHigh, rightHigh)+1;
    }
};


