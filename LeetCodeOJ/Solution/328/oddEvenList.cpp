/*! Source: https://leetcode.com/problems/copy-list-with-random-pointer
 *! Author: qwchen
 *! Date  : 2017-05-02
 *  奇数偶数链表
 *    将链表按照奇数下标和偶数下标拆分，分成奇数链表和偶数链表，然后将偶数链表连接在奇数链表后面。
 *    主要是奇数下标和偶数下标，不是奇数值和偶数值
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
 *   遍历链表，分别构建一个奇数链表和偶数链表来接收链表的奇数下标结点和偶数下标结点；
 *   然后将奇数链表的末尾连接上偶数链表，然后将偶数链表的末尾置空
 * 时间复杂度：O(n). 15 ms. beats 96.87 % of cpp submissions.
 * 空间复杂度；O(1)
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode odd(0);   // 奇数链表
        ListNode even(0);  // 偶数链表
        ListNode* p = head;
        ListNode* pOdd = &odd;    
        ListNode* pEven = &even;  
        while (p != nullptr){
            pOdd->next = p;
            pOdd = pOdd->next;
            p = p->next;
            if (p != nullptr) {
                pEven->next = p;
                pEven = pEven->next;
                p = p->next;
            }
        }
        pOdd->next = even.next;
        pEven->next = nullptr; // 注意要将偶数链表的末尾置空
        return odd.next;
    }
};

