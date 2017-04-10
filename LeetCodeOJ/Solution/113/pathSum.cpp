/*! Source: https://leetcode.com/problems/path-sum-ii
 *! Author: qwchen
 *! Date  : 2017-04-10
 *  路径和
 *  判断二叉树是否存在从根节点到叶子结点的路径和等于sum的路径，并保存该路径
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
 * 时间复杂度：O(n). 9ms. beats 78.02% of cpp submissions
 * 空间复杂度：O(logn). 递归栈，不算存放结果的数组
 */
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> paths;
        if (root == nullptr) return paths;
        int res = 0;
        vector<int> path;
        pathSum(root, sum, res, path, paths);
        return paths;
    }
    
    void pathSum(TreeNode* root, int sum, int& res, vector<int>& path, vector<vector<int>>& paths) {
        path.push_back(root->val);
        res += root->val;
        if (root->left == nullptr && root->right == nullptr) {
            if (res == sum) paths.push_back(path);
            return;
        }
        if (root->left) {
            pathSum(root->left, sum, res, path, paths);
            path.pop_back();
            res -= root->left->val;
        }
        if (root->right) {
            pathSum(root->right, sum, res, path, paths);
            path.pop_back();
            res -= root->right->val;
        }
    }
};

