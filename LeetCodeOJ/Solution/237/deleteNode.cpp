/*! Source: https://leetcode.com/problems/delete-node-in-a-linked-list/?tab=Description
 *! Author: qwchen
 *! Date: 2017-03-12
 *  O(1)的时间复杂度删除链表的结点，保证待删除的结点存在且非尾结点
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
 * 思路：
 *   将当前结点的下一个结点的值赋给当前结点，然后删除当前结点的下一个结点。
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        ListNode* delNode = node->next;
        node->next = node->next->next;
        delete delNode;
    }
};

