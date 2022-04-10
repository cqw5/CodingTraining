/*! Author: qwchen
 *! Date  : 2017-02-06
 *! 树和图: 4.8 判断小树(m个结点)是否为大树(n个结点)的子树
 */

/*
 * 思路1：特点：空间换时间
 *   分别用字符串表示大树和小树的先序遍历和中序遍历，注意空结点也要表示（如用“#”表示）
 *   若大树的先序遍历包含小树的先序遍历，且大树的中序遍历包含小树的中序遍历，则大树包含小树
 * 时间复杂度：O(n+m)
 * 空间复杂度：O(n+m)
 */

/*
 * 思路2：
 *   先序遍历大树，若遇到与小树树根相同的结点，则调用比较函数，判断大树中以当前结点为根的子树是否与小树相同
 * 时间复杂度：O(n+km),k为小树的树根在大树中出现的次数
 * 空间复杂度：O(logn + logm)，递归栈
 */
class Solution {
public:
    bool containsTree(TreeNode* t1, TreeNode* t2) {
        if (t2 == nullptr) return true;  // 小树t2是空，一定是大树t1的子树
        return subTree(t1, t2);
    }

private:
    bool subTree(TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr) return false;  // 大树t1是空，则找不到子树
        if (t1->val == t2->val && matchTree(t1, t2)) return true;  // 以当前结点为根的子树是否与小树相同
        return subTree(t1->left, t2) || subTree(t1->right, t2);    // 判断左右子树是否包含小树
    }

    bool matchTree(TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr && t2 == nullptr) return true;  // 两者都为空
        if (t1 == nullptr || t2 == nullptr) return false; // 两者之一不为空
        if (t1->val != t2->val) return false;             // 结点数据不匹配
        return matchTree(t1->left, t2->left) && matchTree(t1->right, t2->right); // 递归判断子树是否相同
    }
};

class Solution {
public:
    bool checkSubTree(TreeNode* t1, TreeNode* t2) {
        if (t2 == nullptr) return true;
        if (t1 == nullptr) return false;
        return (t1->val == t2->val && preOrder(t1, t2))
                || checkSubTree(t1->left, t2)
                || checkSubTree(t1->right, t2);
    }

private:
    bool preOrder(TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr && t2 == nullptr) return true;
        if (t1 == nullptr || t2 == nullptr) return false;
        return t1->val == t2->val 
                && preOrder(t1->left, t2->left)
                && preOrder(t1->right, t2->right); 
    }
};

