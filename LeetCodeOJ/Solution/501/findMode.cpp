/*! Source: https://leetcode-cn.com/problems/find-mode-in-binary-search-tree/
 *! Author: qwchen
 *! Date  : 2022-04-17
 *  二叉搜索树中的众数
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

/*
 * 思路：
 *   树的中序遍历是一个非递减数组。可以对树进行中序遍历：
 *   - 当当前元素与上一个元素相同时，计数+1。
 *   - 当当前元素与上一个元素不同时，开始统计上一个元素的计数器，看看出现多少次。
 *   - 终止时还需要考虑最后一组重复元素需要独立处理。
 * 时间复杂度：O(n)，执行用时：12 ms, 在所有 C++ 提交中击败了 92.03% 的用户
 * 空间复杂度：O(1)，内存消耗：23.3 MB, 在所有 C++ 提交中击败了 85.93% 的用户
 */
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        inOrder(root);
        if (curCount == maxCount) {
            modeList.push_back(curVal);
        } else if (curCount > maxCount) {
            modeList = {curVal};
        }
        return modeList;
    }
private:
    vector<int> modeList;
    int curVal = 0;
    int curCount = 0;
    int maxCount = 0;
    void inOrder(TreeNode* root) {
        if (root) {
            inOrder(root->left);
            if (root->val == curVal) {
                curCount++;
            } else {
                if (curCount == maxCount) {
                    modeList.push_back(curVal);
                } else if (curCount > maxCount){
                    modeList = {curVal};
                    maxCount = curCount;
                }
                curVal = root->val;
                curCount = 1;
            }
            inOrder(root->right);
        }
    }
};


