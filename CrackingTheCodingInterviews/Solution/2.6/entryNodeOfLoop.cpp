/*! Author: qwchen
 *! Date  : 2017-01-02
 *! 字符串与数组: 2.6
 *！题目描述：
 *    一个链表中包含环，请找出该链表的环的入口结点。
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
    ListNode(int x, ListNode* theNext): val(x), next(theNext) {}
};

/*
 * 思路：
 *   设环的起始点距离链表起点的长度为k，环的长度为loopSize，两个指针fast和slow
 *   第一步，寻找环中相汇点。
 *     让fast每次走两步，slow每次走一步，同时从起点出发，那么当slow走k步到环的起点时，fast走了2k步（在环内走了k步），此时fast领先slow K步
 *     (K = k % loopSize)，并且fast再沿着环追赶slow，也就是说，反过来slow在fast前面loopSize-K步。
 *     由于每一次移动，fast比slow多走1步，因此只要经过loopSize-K次移动，fast就追上了slow，与slow相汇。此时slow又走了loopSize-K步，即此时slow和fast
 *     顺时针距离环的起点K步(k = K + M * loopSize)。
 *   第二步，寻找环的入口。
 *     另slow重新指向链表起点，fast还是指向上一步slow与fast的相汇点，同时都每次一步移动，最终fast和slow相汇点就是环的起点(k = K + M * loopSize)。
 */
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead) {
        if (pHead == nullptr) return nullptr;
        ListNode dummp(0);
        dummp.next = pHead;
        ListNode* pFast = &dummp;
        ListNode* pSlow = &dummp;
        while (pFast != nullptr && pFast->next != nullptr) {
            pSlow = pSlow->next;
            pFast = pFast->next->next;
            if (pSlow == pFast) break;
        }
        if (pFast == nullptr || pFast->next == nullptr) return nullptr;
        pSlow = &dummp;
        while (pSlow != pFast) {
            pSlow = pSlow->next;
            pFast = pFast->next;
        }
        return pFast;
    }
};

