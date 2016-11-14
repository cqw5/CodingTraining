/*! Source: https://leetcode.com/problems/minimum-depth-of-binary-tree/
 *! Author: qwchen
 *! Date  : 2016-11-14
 * 求二叉树的最小深度，求的是从根节点到最近的叶子节点的深度。
 * 应该考虑到，一个结点的左右子树一个为空一个不为空时，不能将空的子树作为最小深度。
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

class Solution1 {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr){ // 考虑当输入的树是空树的情况
            return 0;
        }
        if (root->left == nullptr && root->right == nullptr){ // 叶子节点
            return 1;
        }
        int leftHigh = INT_MAX;
        int rightHigh = INT_MAX;
        if (root->left != nullptr){ // 非空时才算
            leftHigh = minDepth(root->left);
        }
        if (root->right != nullptr){ // 非空时才算
            rightHigh = minDepth(root->right);
        }
        return min(leftHigh, rightHigh) + 1;
    }
};

class Solution2 {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr){
            return 0;
        }
        int leftHigh = minDepth(root->left);
        int rightHigh = minDepth(root->right);
        // 一个结点的左右子树一个为空一个不为空时，不能将空的子树作为最小深度
        return (leftHigh == 0 || rightHigh == 0)? leftHigh + rightHigh + 1 : min(leftHigh, rightHigh) + 1;
    }
};