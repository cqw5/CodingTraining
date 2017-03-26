/*! Source: https://leetcode.com/problems/add-two-numbers-ii
 *! Author: qwchen
 *! Date  : 2017-03-26
 *  两个数相加
 *    不允许翻转链表和修改链表
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
 *   递归，从两个链表的最后一个元素开始加起
 * 时间复杂度：O(m+n)
 * 空间复杂度：O(max(m,n))，递归栈的深度
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1 = length(l1);
        int len2 = length(l2);
        int carry = 0;
        ListNode* l3;
        if (len1 >= len2) {
            int diff = len1 - len2;
            l3 = add(l1, l2, 0, diff, carry);
        }
        else {
            int diff = len2 - len1;
            l3 = add(l2, l1, 0, diff, carry);
        }
        if (carry > 0) {
            ListNode* p = new ListNode(carry);
            p->next = l3;
            l3 = p;
        }
        return l3;
    }
    
    int length(ListNode* p) {
        int len = 0;
        while (p != nullptr) {
            len++;
            p =p->next;
        }
        return len;
    }
    
    ListNode* add(ListNode* lg, ListNode* st, int i, int diff, int &carry) {
        if (lg == nullptr) {
            carry = 0;
            return nullptr;
        }
        ListNode* p;
        // 长链表和短链表对应的部分
        if (i >= diff) {
            p = add(lg->next, st->next, i+1, diff, carry);
            carry += st->val;
            // carry += lg->val;
        }
        // 长链表比短链表长出的部分
        else {
            p = add(lg->next, st, i+1, diff, carry);
            // carry += lg->val;
        }
        carry += lg->val;
        ListNode* q = new ListNode(carry % 10);
        q->next = p;
        carry /= 10;
        return q;
    }
};


/*
 * 思路：
 *   使用两个栈来实现反向相加（这种方法会超出内存限制）
 * 时间复杂度：O(m+n)
 * 空间复杂度：O(m+n)
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        ListNode* p = l1;
        while (p != nullptr) s1.push(p->val);
        p = l2;
        while (p != nullptr) s2.push(p->val);
        ListNode dummp(0);
        int carry = 0;
        while (!s1.empty() || !s2.empty() || carry) {
            if (s1.empty()) {
                carry += s1.top();
                s1.pop();
            }
            if (s2.empty()) {
                carry += s2.top();
                s2.pop();
            }
            ListNode* q = new ListNode(carry % 10);
            q->next = dummp.next;
            dummp.next = q;
            carry /= 10;
        }
        return dummp.next;
    }
};

