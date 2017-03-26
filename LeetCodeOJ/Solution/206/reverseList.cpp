/*! Source: https://leetcode.com/problems/reverse-linked-list
 *! Author: qwchen
 *! Date  : 2017-03-26
 *  反转链表
 */

/*
 * 思路：
 *   递归解法（迭代解法见《剑指offer》）
 *   注意要一个引用指针来跟踪新的头指针，原始的头指针head的next需要置为nullptr
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* newHead = head;
        head = reverse(head, newHead);
        head->next = nullptr;
        return newHead;
    }
    
    ListNode* reverse(ListNode* p, ListNode* &head) {
        if (p->next == nullptr) {
            head = p;
            return p;
        }
        ListNode* q = reverse(p->next, head);
        q->next = p;
        return p;
    }
};

