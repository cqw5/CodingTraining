/*! Source: https://leetcode.com/problems/insertion-sort-list/
 *! Author: qwchen
 *! Date  : 2016-12-11
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
 *   遍历链表，对链表中的每一个结点，将每一个结点插入到其前面适合的位置上。
 *   由于涉及到链表结点的删除和插入，因此需要用一个指针指向待操作的结点的前一个结点。
 *   注意到，当前结点的合适插入位置可能是链表头、其前方某一个位置、当前所在位置刚好就是最合适的位置
 * 时间复杂度：O(n^2)
 * 空间复杂度：O(1)
 */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        ListNode dummp(INT_MIN);
        dummp.next = head;
        ListNode* p1 = head;
        while(p1->next != nullptr) {
            ListNode* p2 = &dummp;
            while(true) {
                // 如果结点的前方找到合适的插入位置
                if (p2->val <= p1->next->val && p2->next->val > p1->next->val) {
                    ListNode* next = p1->next->next;
                    p1->next->next = p2->next;
                    p2->next = p1->next;
                    p1->next = next;
                    break;
                }
                // 当p2 == p1时，说明当前结点所在位置就是去正确的位置
                if (p2 == p1) {
                    p1 = p1->next;
                    break;
                }
                p2 = p2->next;
            }
        }
        return dummp.next;
    }
};

