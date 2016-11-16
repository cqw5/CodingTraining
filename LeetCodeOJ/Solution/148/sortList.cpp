/*! Source: https://leetcode.com/problems/sort-list/
 *! Author: qwchen
 *! Date  : 2016-11-16
 *  排序两个链表
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
 *  使用归并排序：链表的归并排序不需要辅助数组
 */
class Solution {
public:
    // 归并排序
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* mid = getMid(head);
        ListNode* head2 = mid->next;
        mid->next = nullptr;
        head = sortList(head);
        head2 = sortList(head2);
        return merge(head, head2);
    }

private:
    // 将链表分为两半，返回前半部分的最后一个结点
    // 用两个指针，一个慢指针一次走一步，一个快指针一次走两步，当快指针走到最后时，慢指针就刚好走到中间
    ListNode* getMid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    // 将有序两个链表合并
    ListNode* merge(ListNode* left, ListNode* right){
        ListNode dummp(0);
        ListNode* p = &dummp;
        while (left != nullptr && right != nullptr) {
            if (left->val <= right->val) {
                p->next = left;
                left = left->next;
            }
            else {
                p->next = right;
                right = right->next;
            }
            p = p->next;
        }
        if (left != nullptr) {
            p->next = left;
        }
        if (right != nullptr) {
            p->next = right;
        }
        return dummp.next;
    }
};