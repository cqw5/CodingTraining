/*! Source: https://leetcode.com/problems/sum-of-left-leaves
 *! Author: qwchen
 *! Date  : 2017-06-28
 *  二叉树中叶子中左叶子的数目
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
 *   先序遍历二叉树，注意根节点不算左叶子节点
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        if (root == nullptr) return sum;
        if (root->left != nullptr)  preOrder(root->left, root, sum);
        if (root->right != nullptr) preOrder(root->right, root, sum);
        return sum;
    }
    
    void preOrder(TreeNode* root, TreeNode* parent, int& sum) {
        if (root == nullptr) return;
        if (root->left == nullptr && root->right == nullptr) {
            if (root == parent->left) {
                sum += root->val;
            }
        }
        preOrder(root->left, root, sum);
        preOrder(root->right, root, sum);
    }
};

