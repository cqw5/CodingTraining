/*! Author: qwchen
 *! Date  : 2017-05-14
 *  二叉树中节点的最大距离
 *  思路：
 *    该题目是Leetcode中124题的变形
 *    计算二叉树中节点的最大距离，那么这两个节点有3种情况：(排除树为空)
 *    - 两个都是叶子结点
 *    - 两个都是根节点（此时树只有一个结点）
 *    - 一个是叶子结点，一个是根节点
 *    后续遍历二叉树，求每个以每个结点为根节点时，其所构成的子树的中节点的最大距离。
 *    以某个结点开始到叶子结点的最大距离=1+max(该节点左子树的最大深度, 该节点右子树的最大深度)
 *  时间复杂度：O(n)
 *  空间复杂度：O(logn). 递归栈的深度
 */

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* l, TreeNode* r): val(x), left(l), right(r) {}
};

int find(TreeNode* root, int& maxLen) {
    if (root == nullptr) return 0;
    int lenLeft = find(root->left, maxLen);   // 当前结点的左子树的最大深度
    int lenRight = find(root->right, maxLen); // 当前结点的右子树的最大深度
    int curLen = 1 + lenLeft + lenRight;      // 以当前结点为根节点的树中存在的最长距离
    if (curLen > maxLen) maxLen = curLen;     // 更新全局最长距离
    return 1 + max(lenLeft, lenRight);        // 以某个结点开始到叶子结点的最大距离=1+max(该节点左子树的最大深度, 该节点右子树的最大深度)
}

int findMaxLen(TreeNode* root) {
    int maxLen = 0;  // 标记最大距离
    find(root, maxLen);
    return maxLen;
}

