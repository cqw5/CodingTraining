/*! Source: https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii
 *! Author: qwchen
 *! Date  : 2017-03-26
 *  删除链表中重复的结点II
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode dummp(0);
        dummp.next = head;
        ListNode* pre = &dummp;
        ListNode* p = head;
        while (p != nullptr) {
            bool flag = false;
            // 访问p->next->val，注意要先判断p->next是否为nullptr
            while (p->next != nullptr && p->next->val == p->val) {
                flag = true;
                ListNode* delNode = p->next;
                p->next = p->next->next;
                delete delNode;
            }
            if (flag) {
                pre->next = p->next;
                delete p;
                p = pre->next;
            }
            else {
                pre = p;
                p = p->next;
            }
        }
        return dummp.next;
    }
};

