/*! Source: https://leetcode.com/problems/binary-tree-paths
 *! Author: qwchen
 *! Date  : 2017-04-24
 *  二叉树的路径
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
 *   深度优先搜索（先序遍历）。
 *   用一个path保存从根节点到当前结点的路径，遇到叶子结点，就把根节点到当前结点的路径保存到结果中
 * 时间复杂度：O(n)
 * 空间复杂度：O(logn * m)，logn为树的深度，m为树的叶子结点数
 */
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        vector<int> path;
        if (root == nullptr) return res;
        dfs(root, path, res);
        return res;
    }
    
    void dfs(TreeNode* root, vector<int> &path, vector<string> &res) {
        path.push_back(root->val);
        if (root->left == nullptr && root->right == nullptr) {
            string s = "";
            for (int i = 0; i < path.size() - 1; i++) {
                s += to_string(path[i]);
                s += "->";
            }
            s += to_string(path.back());
            res.push_back(s);
        }
        if (root->left != nullptr) {
            dfs(root->left, path, res);
            path.pop_back();
        }
        if (root->right != nullptr) {
            dfs(root->right, path, res);
            path.pop_back();
        }
    }
};

