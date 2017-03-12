/*! Source: https://leetcode.com/problems/palindrome-linked-list/?tab=Description
 *! Author: qwchen
 *! Date: 2017-03-12
 *  判断链表是否为回文
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
 *   将链表前半部分逆序，保存为另一个链表，然后逐一比较这两个链表对应的元素是否相同。
 *   因为链表长度未知，因此使用快指针（每次走两步）和慢指针（每次走一步），当快指针走到链表结尾时，慢指针刚好就走到链表中间。
 *   注意链表长度是奇数还是偶数。
 *     如果p是在p->next == nullptr退出，说明链表长度是偶数；
 *     如果是在p->next->next == nullptr退出，说明链表的长度是奇数
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode dummp1(0);
        ListNode dummp2(0);
        dummp1.next = head;
        ListNode *p = &dummp1;
        while (p->next != nullptr && p->next->next != nullptr) {
            p = p->next->next;
            ListNode* moveNode = dummp1.next;
            dummp1.next = moveNode->next;
            moveNode->next = dummp2.next;
            dummp2.next = moveNode;
        }
        ListNode *p1 = dummp1.next;
        ListNode *p2 = dummp2.next;
        if (p->next != nullptr) p1 = p1->next;  // 若链表长度为奇数，p1先走一步
        while (p1 != nullptr) {
            if (p1->val != p2->val) {
                return false;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        return true;
    }
};

