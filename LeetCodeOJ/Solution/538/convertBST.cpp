/*! Source: https://leetcode-cn.com/problems/convert-bst-to-greater-tree/
 *! Author: qwchen
 *! Date  : 2022-04-17
 *  把二叉搜索树转换为累加树（数中节点没有重复）
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
 *   树的中序遍历是一个非递减序列，如果树中节点无重复则中序遍历是一个递增序列。
 *   反向中序遍历即为一个递减序列。
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */
class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        inOrder(root);
        return root;
    }

private:
    int curSum = 0;
    void inOrder(TreeNode* root) {
        if (root) {
            inOrder(root->right);
            curSum += root->val;
            root->val = curSum;
            inOrder(root->left);
        }
    }
};
