/*! Source: https://leetcode.com/problems/populating-next-right-pointers-in-each-node
 *! Author: qwchen
 *! Date  : 2017-4-30
 *  二叉树的水平指针(满二叉树)
 *  满二叉树：除了叶子节点之外的每一个节点都有左孩子和右孩子
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
 *   考虑满二叉树的特点
 *   如果每一层的第一个节点的左孩子存在，则该层不是最后一层
 *   通过当前层来为下一层连接。
 *     当前节点的左孩子的next指向当前节点的右孩子
 *     当前节点的右孩子的next指向下一个节点左孩子（如果下一个节点为null，就指向null）
 * 时间复杂度：O(n). 16ms. Your runtime beats 75.13 % of cpp submissions.
 * 空间复杂度：O(1).
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == nullptr) return;;
        TreeLinkNode* pre = root;
        while(pre->left) {
            TreeLinkNode* cur = pre;
            while(cur) {
                cur->left->next = cur->right;
                if(cur->next) cur->right->next = cur->next->left;
                else          cur->right->next = nullptr;
                cur = cur->next;
            }
            pre = pre->left;
        }
    }
};


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

