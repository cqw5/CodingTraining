/*! Source: https://leetcode.com/problems/binary-tree-inorder-traversal/
 *! Author: qwchen
 *! Date  : 2016-11-14
 * 求二叉树的最大深度（高度）
 * 下面Solution2只要一行代码就实现了，然而这种代码可读性不高，不推荐。
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
    int maxDepth(TreeNode* root) {
        if (root == nullptr){
            return 0;
        }
        int leftHigh = maxDepth(root->left);
        int rightHigh = maxDepth(root->right);
        return max(leftHigh, rightHigh) + 1;
    }
};

class Solution2 {
public:
    int maxDepth(TreeNode* root) {
        return root == nullptr? 0 : 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};

