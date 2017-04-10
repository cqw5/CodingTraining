/*! Source: https://leetcode.com/problems/path-sum
 *! Author: qwchen
 *! Date  : 2017-04-10
 *  路径和
 *  判断二叉树是否存在从根节点到叶子结点的路径和等于sum的路径
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
 *   换一个思路，从根节点到叶子结点遍历每一个结点时，让sum减去该结点的值，
 *   当遍历到叶子结点是，若叶子结点的值刚好等于sum，说明存在这样的路径。
 * 时间复杂度：O(n). beats 29.07% of cpp submissions.
 * 空间复杂度：O(logn). 递归栈
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == nullptr) return false;
        if (root->val == sum && root->left == nullptr && root->right == nullptr) return true;
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        int res = 0;
        if (root == nullptr) return false;
        return hasPath(root, sum, res);
    }
    
    bool hasPath(TreeNode* root, int sum, int& res) {
        res += root->val;
        if (root->left == nullptr && root->right == nullptr) {
            if (res == sum) return true;
            else            return false;
        }
        if (root->left) {
            if (hasPath(root->left, sum, res)) return true;
            else res -= root->left->val;
        }
        if (root->right) {
            if (hasPath(root->right, sum, res)) return true;
            else res -= root->right->val;
        }
        return false;
    }
};

