/*! Source: https://leetcode.com/problems/intersection-of-two-linked-lists/
 *! Author: qwchen
 *! Date  : 2016-12-12
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
 *   求两个链表的长度差k
 *   用两个指针分别指向长链表和短链表，让指向长链表的指针先走k步
 * 时间复杂度：O(m+n)
 * 空间复杂度：O(1)
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) return nullptr;
        ListNode dummpA(0);
        ListNode dummpB(0);
        dummpA.next = headA;
        dummpB.next = headB;
        int lenA = 0, lenB = 0;
        for (ListNode* p = &dummpA; p != nullptr; p = p->next) {
            lenA++;
        }
        for (ListNode* p = &dummpB; p != nullptr; p = p->next) {
            lenB++;
        }
        ListNode* p = &dummpA;
        ListNode* q = &dummpB;
        if (lenA > lenB) {
            for (int i = 0; i < lenA - lenB; i++) {
                p = p->next;
            }
        }
        else {
            for (int i = 0; i < lenB - lenA; i++) {
                q = q->next;
            }
        }
        while (p != nullptr && q != nullptr) {
            if (p == q) {
                return p;
            }
            p = p->next;
            q = q->next;
        }
        return nullptr;
    }
};

