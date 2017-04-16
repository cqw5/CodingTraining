/*! Source: https://leetcode.com/problems/recover-binary-search-tree
 *! Author: qwchen
 *! Date  : 2017-04-16
 *  恢复二叉查找树
 *  二叉查找树中有两个节点被错误交换了。在不改变树结构的情况下，找出这两个节点，并将其恢复为正确的二叉查找树。
 *  要求空间复杂度小于O(n)
 */


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
 * 思路：
 *   注意到二叉查找树的中序遍历是一个有序的数组，非递减
 *   如果有两个结点位置互换了，就是一个大的结点换到了前面，一个小的结点换到了后面。
 *   那么我们将二叉树进行中序遍历，遍历结果保存为一个数组，然后从数组中找出则两个位置就可以了。
 *   但是这样的空间复杂度为O(n)，不满足本题要求。
 *   
 *   为了将空间复杂度降到小于O(n)，就需要在进行中序遍历时就找出这两个位置，不需要保存中序遍历的结果。
 *   用一个pre指向上一个结点，p指向当前结点，正常的二叉查找树满足pre<p。
 *   注意到，错误放到前面的结点是一个值大的结点，错误放到后面的结点是一个值小的结点
 *   当第一次出现pre>p时，由于错误放到前面的结点是一个值大的结点，因此此时pre指向的就是错误的结点
 *   当第二次出现pre>p时，由于错误放到后面的结点是一个值小的结点，因此此时p指向的就是错误的结点
 * 时间复杂度：O(n). 22 ms. beats 90.53% of cpp submissions.
 * 空间复杂度：O(logn).递归栈
 */
class Solution {
public:
    TreeNode* first = nullptr;  // 指向第一个位置错误的结点
    TreeNode* second = nullptr; // 指向第二个位置错误的结点
    TreeNode* pre = new TreeNode(INT_MIN); // 给pre一个初始值
    bool flag = true; // true表示当前寻找的是第一个错误的结点，false表示当前寻找的是第二个错误的结点
    
    void recoverTree(TreeNode* root) {
        inOrder(root);
        if (first != nullptr && second != nullptr) {
            swap(first->val, second->val);
        }
    }
    
    void inOrder(TreeNode* root) {
        if (root) {
            inOrder(root->left);
            if (flag && pre->val > root->val) {
                first = pre;
                flag = false;
            }
            if (!flag && pre->val > root->val) {
                second = root;
            }
            pre = root;
            inOrder(root->right);
        } 
    }
};

