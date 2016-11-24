/*! Author: qwchen
 *! Date  : 2016-11-24
 *  39.2 平衡二叉树
 */

/*
 * 思路：借鉴求二叉树深度的过程
 *       对每个结点求其左子树和右子树的深度，如果左右子树的深度差大于1，只部分平衡二叉树
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */
class Solution {
public:
    bool IsBalanced(TreeNode* pRoot) {
        bool balanced = true;
        treeHigh(pRoot, balanced);
        return balanced;
    }

private:
    int treeHigh(TreeNode* pRoot, bool& balanced) {
        if (pRoot == nullptr) {
            return 0;
        }
        int left = treeHigh(pRoot->left, balanced);
        int right = treeHigh(pRoot->right, balanced);
        if (left - right < -1 || left - right > 1) {
            balanced = false;
        }
        return max(left, right) + 1;
    }
};