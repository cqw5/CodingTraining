/*! Source: https://leetcode.com/problems/unique-binary-search-trees-ii/
 *! Author: qwchen
 *! Date  : 2016-12-12
 * Solution 为该文件最优的方案
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
 *   对于[1:n]的数组，每一个数都可能成为根节点，由于构成的是二叉搜索树，那么根节点左边的数组会构成左子树、右边的数组会构成右子树
 *   对每个根节点来说，其每个左数组构成的左子树可以有多种形态，右数组构成的右子树也一样，根节点加上每一种左子树和每一种右子树的组合就会构成一种二叉搜索树
 *   递归进行这个过程。
 */
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> tree;
        if (n <= 0) return tree;
        return generateTree(1, n);
    }

private:
    vector<TreeNode*> generateTree(int low, int high) {
        vector<TreeNode*> tree;
        if (low > high) {
            tree.push_back(nullptr);
            return tree;
        }
        for (int i = low; i <= high; i++) {
            vector<TreeNode*> leftTreeArr = generateTree(low, i-1);
            vector<TreeNode*> rightTreeArr = generateTree(i+1, high);
            for (int j = 0; j < leftTreeArr.size(); j++) {
                for (int k = 0; k < rightTreeArr.size(); k++) {
                    TreeNode* root = new TreeNode(i);
                    root->left = leftTreeArr[j];
                    root->right = rightTreeArr[k];
                    tree.push_back(root);
                }
            }
        }
        return tree;
    }
};

