/*! Author: qwchen
 *! Date  : 2016-11-17
 * 18. 树的子结构
 * 特别说明：本题的题意假定空树不是任何树的子树。
 * 思路：先序遍历A树，寻找A树中那些与B树根节点相同的节点R，再判断以A树中R节点为根的子树是否包含B树
 * 
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
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
        if (pRoot2 == nullptr) {
            return false;
        }
        return preOrder(pRoot1, pRoot2);
    }

private:
    /*
     * 先序遍历A树，如果当前节点R与B树的根节点相同，并且以R为根的子树包含B树
     *                  或者R的左子树包含B树
     *                  或者R的右子树包含B树
     *                返回true
     *              否则，返回false
     */
    bool preOrder(TreeNode* pRoot1, TreeNode* pRoot2) {
        if (pRoot1) {
            if (pRoot1->val == pRoot2->val && sameTree(pRoot1, pRoot2) 
                || preOrder(pRoot1->left, pRoot2)
                || preOrder(pRoot1->right, pRoot2)) {
                return true;
            }
        }
        return false;
    }
    
    /*
     * 判断A树是否包含B树
     * 同时同步遍历A树和B树，树中一个节点：
     *     如果在B树为空，说明B树中以该节点为根的子树被A树包含，返回true
     *     如果在A树为空，A树不为空，说明B树中以该节点为根的子树没有被A树所包含，返回false
     *     如果A树和B树都不为空，那么如果A树中该节点等于B树中该节点，并且A树中该节点的左子树包含B树中该节点的左子树，
     *                               并且A树中该节点的右子树包含B树中该节点的右子树，返回ture；否则返回false
     */
    bool sameTree(TreeNode* pRoot1, TreeNode* pRoot2) {
        if (pRoot2 == nullptr) {
            return true;
        }
        if (pRoot1 == nullptr) {
            return false;
        }
        return pRoot1->val == pRoot2->val
            && sameTree(pRoot1->left, pRoot2->left)
            && sameTree(pRoot1->right, pRoot2->right);
    }
};