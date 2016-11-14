/*! Source: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
 *! Author: qwchen
 *! Date  : 2016-11-14
 * 寻找树中两个节点的最低公共祖先
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
 * 使用递归来求解
 * 递归的寻找p和q，找到p和q并将p和q往上传递(p或q以下的结点就不再查找，因为他们不是树p和q的祖先)
 * 有3种情况：
 *     1. p刚好是q的祖先，则p会不断往上传递。
 *     2. q刚好是p的祖先，则q会不断往上传递。
 *     3. 如果不是1或2中的情况，必定有且只有一个结点，其左子树和右子树分别可以追索到p和q或q和p
 * 时间复杂度：O(n), n为树中结点的个数
 * 空间复杂度：O(1)
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root == p || root == q){ // 递归终止的条件是找到p或q，返回p或q；如果没有找到，到达空节点，返回null
            return root;
        }
        TreeNode* left = lowestCommonAncestor(root->left, p, q);  
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left != nullptr && right != nullptr){
            return root;
        }
        else if (left != nullptr){
            return left;
        }
        else {
            return right;
        }
    }
};

