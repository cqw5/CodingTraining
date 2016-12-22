/*! Source: https://leetcode.com/problems/reorder-list/
 *! Author: qwchen
 *! Date  : 2016-12-22
 *  链表重排序
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
 *   边界条件：链表长度小于3，不用重排序，直接返回
 *   1. 先将链表分为前后两半L1和L2：长度为偶数时，len(L1) == len(L2)；长度为奇数时，len(L1) == len(L2) + 1
 *   2. 将L2反序
 *   3. 交替合并L1和L2，合并到L1。
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr) return;
        // 先将链表分为前后两半L1和L2，最终pSlow指向L1最后一个结点，需要让pSlow->next == nullptr
        ListNode* pFast = head;
        ListNode* pSlow = head;
        while (pFast->next != nullptr && pFast->next->next != nullptr) {
            pSlow = pSlow->next;
            pFast = pFast->next->next;
        }
        ListNode* p = pSlow->next;
        ListNode* pNext = p->next;
        pSlow->next = nullptr;
        // 将L2逆序
        ListNode dummp(0);
        while (true) {
            p->next = dummp.next;
            dummp.next = p;
            p = pNext;
            if (p == nullptr) break;
            pNext = p->next;
        }
        // 交替合并L1和L2，合并到L1
        p = head;
        ListNode* q = dummp.next;
        while (q != nullptr) {
            dummp.next = q->next;
            q->next = p->next;
            p->next = q;
            p = p->next->next;
            q = dummp.next;
        }
    }
};

