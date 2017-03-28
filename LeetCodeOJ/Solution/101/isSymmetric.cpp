/*! Source: https://leetcode.com/problems/symmetric-tree
 *! Author: qwchen
 *! Date  : 2017-03-28
 *  二叉树的镜像
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
    bool isSymmetric(TreeNode* root) {
        return isSymmetric(root, root);
    }
    
    bool isSymmetric(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr && root2 == nullptr) return true;
        if (root1 == nullptr || root2 == nullptr) return false;
        return (root1->val == root2->val) 
               && isSymmetric(root1->left, root2->right) 
               && isSymmetric(root1->right, root2->left);
    }
};

