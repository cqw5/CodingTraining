/*! Source: https://leetcode.com/problems/linked-list-cycle
 *! Author: qwchen
 *! Date  : 2017-05-02
 *  判断链表是否存在环
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
 *   两个指针：快指针(每次走两步)和慢指针(每次走一步)。
 *   当遇到nullptr时，表示不存在环；如果快指针和慢指针重叠，表示存在环。
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode dummp(0);
        dummp.next = head;
        ListNode* pFast = &dummp;
        ListNode* pSlow = &dummp;
        while (pFast->next != nullptr && pFast->next->next != nullptr) {
            pFast = pFast->next->next;
            pSlow = pSlow->next;
            if (pFast == pSlow) break;
        }
        if (pFast->next == nullptr || pFast->next->next == nullptr) return false;
        else                  return true;
    }
};

