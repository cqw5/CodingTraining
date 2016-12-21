/*! Source: https://leetcode.com/problems/remove-duplicates-from-sorted-list/
 *! Author: qwchen
 *! Date  : 2016-12-21
 *  删除链表中重复的结点
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
 *   从头到尾遍历链表，如果当前结点的下一个结点的值与当前结点相同，则删除下一个结点
 *   注意访问链表结点时应该判断链表结点是否为空，如p->next->val,应该先保证p->next不为空
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* p = head;
        while (p != nullptr && p->next != nullptr) {
            if (p->next->val == p->val) {
                ListNode* delNode = p->next;
                p->next = p->next->next;
                delete delNode;
            }
            else {
                p = p->next;
            }
        }
        return head;
    }
};

