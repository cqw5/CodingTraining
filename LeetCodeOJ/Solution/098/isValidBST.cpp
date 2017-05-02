/*! Source: https://leetcode.com/problems/validate-binary-search-tree
 *! Author: qwchen
 *! Date  : 2017-03-26
 *  二叉查找树验证
 *    给定一颗二叉树，判断其是否为二叉查找树
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
 *   先序遍历
 *   二叉查找树满足：当前节点的值大于左子树的最大值，小于右子树最小值。
 *   反过来，左子树中每一个节点的值都小于当前节点，右子树中每一个节点的值都大于当前节点
 *   因此可以使用先序遍历，并传入当前子树应该满足的最小值和最大值
 * 时间复杂度：O(n). 9 ms. beats 50.57 % of cpp submissions.
 * 空间复杂度：O(logn)
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
    	// 其实使用INT_MIN和INT_MAX就可以了，但是test中存在值大于这个范围值数，因此换成long
        return valid(root, LONG_MIN, LONG_MAX);   
    }
    
    bool valid(TreeNode* root, long minVal, long maxVal) {
        if (root == nullptr) return true;
        if (root->val <= minVal || root->val >= maxVal) return false;
        return valid(root->left, minVal, root->val) && valid(root->right, root->val, maxVal);
    }
};

/*
 * 思路：
 *   中序遍历
 *   二叉查找树的中序遍历的一个单调递增的数组。
 *   对树进行中序遍历，用一个变量来保存前一个节点的值。必须满足前一个节点的值 < 当前节点的值
 * 时间复杂度：O(n). 13 ms. beats 21.95 % of cpp submissions.
 * 空间复杂度：O(logn)
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        long prev = LONG_MIN;
        return valid(root, prev);
    }
    
    bool valid(TreeNode* root, long& prev) {
        if (root == nullptr) return true;
        if (!valid(root->left, prev)) return false;
        if (prev >= root->val) return false;
        else                   prev = root->val;
        if (!valid(root->right, prev)) return false;
        return true;
    }
};

/*
 * 思路：
 *   后序遍历
 *   判断左子树的最大节点是否小于当前节点 和 右子树的最小节点是否大于当前节点，
 *     如一个不是，则这不可能是二叉查找树。
 *     否则，继续递归进行判断
 * 时间复杂度：O(n). 9 ms. beats 50.57 % of cpp submissions.
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

