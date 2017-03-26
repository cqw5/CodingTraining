/*! Source: https://leetcode.com/problems/validate-binary-search-tree
 *! Author: qwchen
 *! Date  : 2017-03-26
 *  二叉查找树
 *    空树是二叉查找树
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
 *   利用后序遍历来判断
 *   判断左子树的最大节点是否小于当前节点 和 右子树的最小节点是否大于当前节点，
 *     如一个不是，则这不可能是二叉查找树。
 *     否则，继续递归进行判断
 * 时间复杂度：O(n)
 * 空间复杂度：O(logn)，递归栈
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        bool valid = true;
        if (root == nullptr) return valid;
        postOrder(root, valid);
        return valid;
    }
    
    pair<int, int> postOrder(TreeNode* root, bool& valid) {
        pair<int, int> res(root->val, root->val);  // first存放以root为节点的子树的最小值，second存放最大值
        if (valid == false) return res;            // 如果在某一步已经判断为非二叉查找树了，那就不需要继续判断了
        if (root->left == nullptr && root->right == nullptr) return res;
        if (root->left) {
            pair<int, int> left = postOrder(root->left, valid);
            // 左子树的最大值是否小于当前节点
            if (left.second >= root->val) { 
                valid = false;
                return res;
            } 
            else {
                res.first = left.first;  // 将左子树的最小值作为以root为根节点的树的最小值
            }
        }
        if (root->right) {
            pair<int, int> right = postOrder(root->right, valid);
            // 右子树的最大值是否大于当前节点
            if (right.first <= root->val) {
                valid = false;
                return res;
            }
            else {
                res.second = right.second;  // 将右子树的最大值作为以root为根节点的树的最大值
            }
        }
        return res;
    }
};

