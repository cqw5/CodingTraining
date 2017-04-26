/*! Source: https://leetcode.com/problems/reverse-linked-list-ii
 *! Author: qwchen
 *! Date  : 2017-04-26
 *  翻转链表II
 *    翻转链表第m到第n个元素之间的元素 
 *    如：Given 1->2->3->4->5->NULL, m = 2 and n = 4,
 *        return 1->4->3->2->5->NULL.
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
 *   借鉴常规的链表翻转（递归版本）的思路，只翻转链表的第m到n个元素
 *   需要4个指针，p指向第m-1个元素，newHead指向翻转片段翻转后新的头，tail指向翻转片段翻转后新的尾，next指向第n+1个元素
 *   移动p到m-1的位置，翻转m~n的片段，返回newHead,tail和next，然后重现连接链表
 * 时间复杂度：O(n). 3ms. beats 19.03 % of cpp submissions.
 * 空间复杂度：O(1)
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode dummp(0);
        dummp.next = head;
        ListNode* p = &dummp;
        for (int i = 1; i < m; i++) {
            p = p->next;
        }
        ListNode* newHead = nullptr;
        ListNode* next = nullptr;
        ListNode* tail = reverse(p->next, newHead, next, 1, n-m+1);
        p->next = newHead;
        tail->next = next;
        return dummp.next;
    }
    
    ListNode* reverse(ListNode* p, ListNode* &head, ListNode* &next, int i, int n) {
        if (i == n) {
            next = p->next;
            head = p;
            return p;
        }
        ListNode* q = reverse(p->next, head, next, i+1, n);
        q->next = p;
        return p;
    }
};

