/*! Author: qwchen
 *! Date  : 2017-01-01
 *! 字符串与数组: 2.2
 *! 题目描述：
 *    输入一个链表，输出该链表中倒数第k个结点。
 */

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};*/

/*
 * 思路：
 *   两个指针，快指针先走k步，慢指针再走，当快指针指向空时，慢指针就刚好指向倒数第k个结点
 *   注意链表长度小于k的情况
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */
class Solution {
public:
    ListNode* findKthToTail(ListNode* pListHead, unsigned int k) {
        if (pListHead == nullptr || k <= 0) return nullptr;
        ListNode dummp(0);
        dummp.next = pListHead;
        ListNode* pSlow = &dummp;
        ListNode* pFast = &dummp;
        for (int i = 0; i < k; i++) {
            pFast = pFast->next;
            if (pFast == nullptr) return nullptr;
        }
        for (; pFast != nullptr; pFast = pFast->next, pSlow = pSlow->next);
        return pSlow;
    }
};

