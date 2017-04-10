/*! Source: https://leetcode.com/problems/remove-linked-list-elements
 *! Author: qwchen
 *! Date  : 2017-04-10
 *  删除链表元素
 *  删除链表中所有等于给定值的元素
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
 * 思路：迭代解法
 * 时间复杂度：O(n). 29 ms. beats 38.08% of cpp submissions.
 * 空间复杂度：O(1)
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummp(0);
        dummp.next = head;
        ListNode* pre = &dummp;
        ListNode* p = head;
        while (p != nullptr) {
            if (p->val == val) {
                pre->next = p->next;
                delete p;
                p = pre->next;
            }
            else {
                pre = p;
                p = p->next;
            }
        }
        return dummp.next;
    }
};

/*
 * 思路：递归解法
 * 时间复杂度：O(1). 26 ms. beats 72.37% of cpp submissions.
 * 空间复杂度：O(logn) 递归栈
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr) return nullptr;
        // 先处理当前结点之后的链表
        head->next = removeElements(head->next, val);
        // 再处理当前结点
        if (head->val == val) {
            ListNode* p = head;
            head = head->next;
            delete p;
        }
        return head;
    }
};

