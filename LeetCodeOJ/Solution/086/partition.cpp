/*! Source: https://leetcode.com/problems/partition-list/
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

/*
 * 思路：
 *   用一个新的链表保存原链表中小于x的结点。遍历原链表一遍，不断降其中小于x的结点移除，追加到新的量表我尾部，最后将新链表的尾部链接到原链表。
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (head == nullptr) {
            return head;
        }
        ListNode dummp1(0);
        ListNode dummp2(0);
        dummp1.next = head;
        ListNode *p1 = &dummp1;
        ListNode *p2 = &dummp2;
        while (p1->next != nullptr) {
            if (p1->next->val < x) {
                ListNode* mvNode = p1->next;
                p1->next = p1->next->next;
                p2->next = mvNode;
                p2 = p2->next;
            }
            else {
                p1 = p1->next;
            }
        }
        p2->next = dummp1.next;
        return dummp2.next;
    }
};

