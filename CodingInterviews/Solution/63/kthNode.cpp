/*! Author: qwchen
 *! Date  : 2016-12-02
 *  63. 二叉搜索树的第k个结点
 * 题目描述
 *   给定一颗二叉搜索树，请找出其中的第k大的结点。例如， 5 / \ 3 7 /\ /\ 2 4 6 8 中，按结点数值大小顺序第三个结点的值为4。
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
 * 思路：
 *   由于树是二叉排序树，对树进行中序遍历可以得到递增排序数组
 *   只需要对二叉排序树进行中序遍历，遍历到第k个结点就为待求的结点。使用一个计数器i来进行结点计数
 * 时间复杂度：O(k)
 * 空间复杂度：O(1)
 */
class Solution {
public:
    TreeNode* KthNode(TreeNode* pRoot, int k) {
        if (pRoot == nullptr || k <= 0) {
            return nullptr;
        }
        int i = 1;
        return inOrder(pRoot, i, k);
    }

private:
    TreeNode* inOrder(TreeNode* pRoot, int& i, int k) {
        if (pRoot == nullptr) {
            return nullptr;
        }
        TreeNode* left = inOrder(pRoot->left, i, k);
        if (left != nullptr) {
            return left;
        }
        if (i == k) {
            return pRoot;
        }
        else {
            i++;
        }
        TreeNode* right = inOrder(pRoot->right, i, k);
        if (right != nullptr) {
            return right;
        }
        return nullptr;
    }
};