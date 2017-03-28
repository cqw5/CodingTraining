/*! Source: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree
 *! Author: qwchen
 *! Date  : 2017-03-27
 *  将排序数组转化为平衡二叉查找树
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
 *   找出数组的中间结点，作为根节点
 *   递归将中间结点左边的数组转化成二叉平衡树，作为根节点的左子树
 *   递归将中间结点右边的数组转化为二叉平衡树，作为根节点的右子树
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums, 0, nums.size()-1);
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums, int low, int high) {
        if (low > high) return nullptr;
        int mid = (low + high) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = sortedArrayToBST(nums, low, mid-1);
        root->right = sortedArrayToBST(nums, mid+1, high);
        return root;
    }
};

