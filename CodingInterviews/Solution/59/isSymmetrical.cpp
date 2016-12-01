/*! Author: qwchen
 *! Date  : 2016-12-01
 *  59. 对称的二叉树
 *  题目描述
 *    请实现一个函数，用来判断一颗二叉树是不是对称的。注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。
 */

/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/

/*
 * 分别对根节点的左子树和右子树进行先序遍历，独一判断对于结点是否相同。
 * 左子树使用常规的先序遍历方法
 * 对右子树进行先序遍历时，我们先访问根节点，再访问右孩子，最后访问左孩子
 */
class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot) {
        if (pRoot == nullptr) {
            return true;
        }
        return isSymmetrical(pRoot->left, pRoot->right);
    }

private:
    bool isSymmetrical(TreeNode* leftTree, TreeNode* rightTree) {
        if (leftTree == nullptr && rightTree == nullptr) {
            return true;
        }
        if (leftTree == nullptr || rightTree == nullptr) {
            return false;
        }
        if (leftTree->val != rightTree->val) {
            return false;
        }
        return isSymmetrical(leftTree->left, rightTree->right) && isSymmetrical(leftTree->right, rightTree->left);
    }
};

