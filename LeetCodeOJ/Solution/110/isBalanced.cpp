/*! Source: https://leetcode.com/problems/balanced-binary-tree
 *! Author: qwchen
 *! Date  : 2017-03-26
 *  二叉平衡树
 *    空树是二叉平衡树
 */

/*
 * 思路：
 *   利用后序遍历来判断
 * 时间复杂度：O(n)
 * 空间复杂度：O(logn)，递归栈
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
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        bool balanced = true;
        height(root, balanced);
        return balanced;
    }
    
    int height(TreeNode* root, bool &balanced) {
        if (balanced == false) return 0;
        if (root == nullptr) return 0;
        int left = height(root->left, balanced);
        int right = height(root->right, balanced);
        if (left - right > 1 || right - left > 1) balanced = false;
        return max(left, right) + 1;
    }
};

