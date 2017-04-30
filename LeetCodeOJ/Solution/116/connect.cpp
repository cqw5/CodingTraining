/*! Source: https://leetcode.com/problems/populating-next-right-pointers-in-each-node
 *! Author: qwchen
 *! Date  : 2017-4-30
 *  二叉树的水平指针
 *  如：给定一个二叉树：
 *       1
 *      /  \
 *     2    3
 *    / \  / \
 *   4  5  6  7
 *  得到其水平指针：
 *       1 -> NULL
 *      /  \
 *     2 -> 3 -> NULL
 *    / \  / \
 *   4->5->6->7 -> NULL
 */


/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */

/*
 * 思路：
 *   利用二叉树的层次遍历，同时每一次结尾加上一个nullptr。
 *   通过让当前结点指向队列的头结点来完成链接。
 * 时间复杂度：O(n). 19 ms. beats 43.00 % of cpp submissions.
 * 空间复杂度：O(n).
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == nullptr) return;
        queue<TreeLinkNode*> q;
        q.push(root);
        q.push(nullptr);
        while (!q.empty()) {
            TreeLinkNode* p = q.front();
            q.pop();
            if (p == nullptr) {
                if (!q.empty()) { // 如果不是最后一层的最后一个nullptr指针
                    q.push(nullptr);
                }
                continue;
            }
            if (p->left)  q.push(p->left);
            if (p->right) q.push(p->right);
            p->next = q.front();
        }
    }
};

