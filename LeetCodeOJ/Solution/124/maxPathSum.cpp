/*! Source: https://leetcode.com/problems/binary-tree-maximum-path-sum/
 *! Author: qwchen
 *! Date  : 2016-11-16
 *  二叉树中的最大路径和。给定一棵二叉树，寻找一条路径使得路径和最大，路径可以在任一节点中开始和结束（路径和为两个节点之间守在路径上的节点权值之和）
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
 * 想法：如果每个节点都记录了以其为连接点和左右两条路径形成的最大路径的长度，那么从中找出最大的节点就可以了
 * 用一个变量记录当前寻找到的最大路径长度
 * 使用后序遍历的方法递归，计算每个以每个节点为连接点及其左右路径形成的最大长度，如果该最大长度大于当前记录的最大长度，更新记录的最大长度
 * 以某个节点开始往下的最大路径长度 = 该节点的值 + max(该节点的左边路径的长度, 该节点右边路径的长度) > 0 ? max(该节点的左边路径的长度, 该节点右边路径的长度): 0
 */
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int max_sum = INT_MIN;
        maxSum(root, max_sum);
        return max_sum;
    }

private:
    int maxSum(TreeNode* root, int& max_sum) {
        if (root == nullptr) {  // 空节点路径长度为0
            return 0;
        }
        // root节点连接的左边的最大路径，如果该路径 < 0，则置为0
        int left_sum = maxSum(root->left, max_sum);
        if (left_sum < 0) {
            left_sum = 0;
        }
        // root节点连接的右边的最大路径，如果该路径 < 0，则置为0
        int right_sum = maxSum(root->right, max_sum);
        if (right_sum < 0) {
            right_sum = 0;
        }
        // root节点 + root节点连接的左边的最大路径 + root节点连接的右边的最大路径 > 当前记录的最大路径的话，更新当前记录的最大路径
        int sum = root->val + left_sum + right_sum;
        if (sum > max_sum) {
            max_sum = sum;
        }
        // root不作为其父节点的左边路径或右边路径时，挑选其左右路径中最大的加入root节点 返回
        return root->val + max(left_sum, right_sum);
    }
};