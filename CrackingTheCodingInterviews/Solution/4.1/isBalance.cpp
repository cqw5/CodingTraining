/*! Author: qwchen
 *! Date  : 2017-01-07
 *! 树和图: 4.1 二叉树平衡检查
 *！题目描述：
 *      实现一个函数，检查二叉树是否平衡，平衡的定义如下，对于树中的任意一个结点，其两颗子树的高度差不超过1。
 *      给定指向树根结点的指针TreeNode* root，请返回一个bool，代表这棵树是否平衡。
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

/*
 * 思路：  
 *   判断树是否为二叉平衡树，需要判断每一个节点是否平衡（即左右子树高度差是否<=1）
 *   对树进行后续遍历即可求树的高度
 *   用高度-1表示以当前结点为根的子树不是平衡树，若出现一个结点，以其为根节点的子树不是平衡树，那么整棵树就不是平衡树
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */
class Balance {
public:
    bool isBalanced(TreeNode* root) {
        treeHigh(root);
        return balance;
    }

private:
    bool balance = true;
    int treeHigh(TreeNode* root) {
        if (root == nullptr) return 0;
        int left = treeHigh(root->left);
        int right = treeHigh(root->right);
        if (left - right > 1 || right - left > 1)  balance = false;
        return max(left, right) + 1;
    }
};

