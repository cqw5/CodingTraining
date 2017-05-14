/*! Author: qwchen
 *! Date  : 2017-05-14
 *  二叉树中最大距离的两个节点
 *  思路：
 *    前面一道题中已经求出了二叉树中的最大距离，那么本题就是求出最大距离的左右两个端点
 *    前面寻找最大距离是进行后序遍历，找到的最大距离必然是树中以某一个节点为根节点的左右子树的最大深度和
 *    因此可以在寻找最大距离的同时，用一个遍历标记该根节点。
 *    然后求出以该根节点左子树中最深的孩子（可能有多个，求出一个即可），得到第一个结点
 *        求出以该根节点右子树中最深的孩子（可能有多个，求出一个即可），得到第二个结点
 *    注意，如果该根节点的左子树为空，就将该根节点作为第一个结点；同样若右子树为空，该根节点同样作为第二个节点
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

// 后序遍历寻找最长路径
int findLen(TreeNode* root, TreeNode* &maxNode, int& maxLen) {
    if (root == nullptr) return 0;
    int lenLeft = findLen(root->left, maxNode, maxLen);
    int lenRight = findLen(root->right, maxNode, maxLen);
    int curLen = 1 + lenLeft + lenRight;
    if (curLen > maxLen) {
        maxLen = curLen;
        maxNode = root;
    }
    return 1 + max(lenLeft, lenRight);
}

// 先序遍历寻找端点，最深的结点
void findNode(TreeNode* root, TreeNode* &p, int& maxDepth, int curDepth) {
    if (root == nullptr) return;
    if (curDepth > maxDepth) {
        p = root;
        maxDepth = curDepth;
    }
    findNode(root->left, p, maxDepth, curDepth+1);
    findNode(root->right, p, maxDepth, curDepth+1);
}

pair<TreeNode*, TreeNode*> findMaxLenNode() {
    // 先求最长路径的长度，找个最长路径中根节点
    int maxLen = 0;
    int maxNode = nullptr;
    findLen(root, maxNode, maxLen);
    // 寻找最长路径中的两个端点，注意端点可能是根节点，因此先初始化为根节点
    TreeNode* p = root;
    TreeNode* q = root;
    int maxDepth = 0;
    findNode(root->left, p, maxDepth, 1);
    maxDepth = 0;
    findNode(root->right, q, maxDepth, 1);
    return make_pair(p, q);
}

