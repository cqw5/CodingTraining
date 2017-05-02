/*! Source: https://leetcode.com/problems/linked-list-cycle-ii
 *! Author: qwchen
 *! Date  : 2017-05-02
 *  链表中环的入口结点
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
 *   见"CrackingTheCodingInterviews"的"链表中环的入口结点"
 * 时间复杂度：O(n). 13 ms. beats 27.50 % of cpp submissions.
 * 空间复杂度：O(1)
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode dummp(0);
        dummp.next = head;
        ListNode* pFast = &dummp;
        ListNode* pSlow = &dummp;
        while (pFast->next != nullptr && pFast->next->next != nullptr) {
            pFast = pFast->next->next;
            pSlow = pSlow->next;
            if (pFast == pSlow) break;
        }
        if (pFast->next == nullptr || pFast->next->next == nullptr) return nullptr;
        pSlow = &dummp;
        while (pSlow != pFast) {
            pSlow = pSlow->next;
            pFast = pFast->next;
        }
        return pFast;
    }
};

