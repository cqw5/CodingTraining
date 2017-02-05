/*! Source: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
 *! Author: qwchen
 *! Date  : 2017-02-05
 * 寻找二叉查找树中两个节点的最低公共祖先
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
 *   对于二叉查找树，公共祖先节点必定大于p而小于q，因此只需要寻找大于p且小于q的节点
 *   同时注意到，如果当前节点小于p，则公共祖先节点必定在当前节点的右子树，如果当前节点大于q，则公共祖先节点必定在当前节点的左子树
 *   因此，只需要从根节点沿着某一路径向下查找，就能找到公共祖先节点，不需要遍历整棵树
 * 时间复杂度：O(logN),N为树节点的数目
 * 空间复杂度：O(1)
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || !check(root, p) || !check(root, q)) return nullptr;
        if (p->val <= q->val) return lowestCommonAncestorHelp(root, p, q);
        else                  return lowestCommonAncestorHelp(root, q, p);
    }

private:
    bool check(TreeNode* root, TreeNode* p) {
        if (root == nullptr) return false;
        if (root == p) return true;
        return check(root->left, p) || check(root->right, p);
    }

    TreeNode* lowestCommonAncestorHelp(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root->val >= p->val && root->val <= q->val) return root;
        if (root->val < p->val) return lowestCommonAncestorHelp(root->right, p, q);
        else                    return lowestCommonAncestorHelp(root->left, p, q);
    }
};