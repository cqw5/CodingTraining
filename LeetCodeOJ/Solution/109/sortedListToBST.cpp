/*! Source: https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/
 *! Author: qwchen
 *! Date  : 2016-12-08
 * Solution 为该文件最优的方案
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
 *   找到链表的中间节点，将链表断开：(左->null, 中间->右)，将中间节点作为根节点，左边链表作为左子树，右边链表作为右子树，递归进行该过程。
 *   寻找链表的中间节点可以用两个指针，一个慢指针1次走一步，一个快指针1次走两步，当快指针的next为空或者next->next为空时，
 *   说明慢指针已经到达中间的结点的前一个结点，将其断开，并返回中间结点
 * 时间复杂度：O(nlogn)
 * 空间复杂度：O(1) 
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }
        ListNode* mid = getMid(&head);
        TreeNode* root = new TreeNode(mid->val);
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(mid->next);
        return root;
    }
    
private:
    // ListNode** head，以便可以修改传入的链表
    ListNode* getMid(ListNode** head) {
        ListNode dummp(0);
        dummp.next = *head;
        ListNode* pFast = &dummp;
        ListNode* pSlow = &dummp;
        ListNode* mid = nullptr;
        while(pFast->next != nullptr && pFast->next->next != nullptr) {
            pFast = pFast->next->next;
            pSlow = pSlow->next;
        }
        if (pSlow == &dummp) {
            mid = *head;
            *head = nullptr;
        }
        else {
            mid = pSlow->next;
            pSlow->next = nullptr;
        }
        return mid;
    }
};