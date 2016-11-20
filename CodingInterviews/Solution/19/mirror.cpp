/*! Author: qwchen
 *! Date  : 2016-11-17
 *  19. 二叉树的镜像
 *  思路：先序遍历二叉树，对于每个结点，交换其左右子树的位置即可
 */


/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/

class Solution {
public:
    void Mirror(TreeNode *pRoot) {
        if (pRoot != nullptr) {
            TreeNode* temp = pRoot->left;
            pRoot->left = pRoot->right;
            pRoot->right = temp;
            Mirror(pRoot->left);
            Mirror(pRoot->right);
        }
    }
};