/*! Author: qwchen
 *! Date  : 2017-03-03
 *! 50. 树的最低公共祖先结点
 */

/*
 * 思路：
 *   定义两个列表，分别存储从根节点到p结点的路径 和 从根节点到q结点的路径
 *   使用先序遍历，可以获得这两个路径
 *   然后两个列表中最后一个相同的结点，最低共祖先结点
 * 时间复杂度：O(n)：主要是在寻找路径
 * 空间复杂度：O(logn): 递归栈和路径长度
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == nullptr || p == nullptr || q == nullptr) return nullptr;
    vector<TreeNode*> pathP;
    vector<TreeNode*> pathQ;
    preOrder(root, p, pathP);
    preOrder(root, q, pathQ);
    int i = 0;
    int n = min(pathP.size(), pathQ.size());
    for (; i < n; i++) {
        if (pathP[i] != pathQ[i]) break;
    }
    return pathP[i-1];
}

void preOrder(TreeNode* root, TreeNode* p, vector<TreeNode*> &path) {
    path.push_back(root);
    if (path.back() == p) return;
    if (root->left != nullptr) {
        preOrder(root->left, p, path);
        if (path.back() == p) return;
        path.pop_back();
    }
    if (root->right != nullptr) {
        preOrder(root->right, p, path);
        if (path.back() == p) return;
        path.pop_back();
    }
}
