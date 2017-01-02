/*! Author: qwchen
 *! Date  : 2017-01-02
 *! 字符串与数组: 2.5
 *! 题目描述：
 *    有两个用链表表示的整数，每个结点包含一个数位。这些数位是反向存放的，也就是个位排在链表的首部。
 *    编写函数对这两个整数求和，并用链表形式返回结果。
 *    给定两个链表ListNode* A，ListNode* B，请返回A+B的结果(ListNode*)。
 *！测试样例：
 *    {1,2,3},{3,2,1}
 *    返回：{4,4,4}
 *！说明：
 *    下面Solution和Solution1的解法一样，只是Solution的编码更为简洁。
 */

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/

/*
 * 思路：
 *   注意到两数相加会产生进位，使用carry来保存进位。
 *   两个链表的长度可能不等。
 *   当两个链表都加完时，进位carry可能还不为0，还要进位。
 * 时间复杂度：O(m+n)
 * 空间复杂度：O(max(m, n))
 */
class Solution {
public:
    ListNode* plusAB(ListNode* a, ListNode* b) {
        if (a == nullptr && b == nullptr) return nullptr;
        ListNode* p = a;
        ListNode* q = b;
        ListNode c(0);     // 用链表c来保存a+b的结果
        ListNode* s = &c;
        int carry = 0;
        while (p != nullptr || q != nullptr || carry != 0) {
            int sum = carry;
            if (p != nullptr) {
                sum += p->val;
                p = p->next;
            }
            if (q != nullptr) {
                sum += q->val;
                q = q->next;
            }
            s->next = new ListNode(sum % 10);
            s = s->next;
            carry = sum / 10;
        }
        return c.next;
    }
};


class Solution1 {
public:
    ListNode* plusAB(ListNode* a, ListNode* b) {
        if (a == nullptr && b == nullptr) return nullptr;
        ListNode* p = a;
        ListNode* q = b;
        ListNode c(0);
        ListNode* s = &c;
        int carry = 0;
        while (p != nullptr && q != nullptr) {
            int sum = p->val + q->val + carry;
            ListNode* newNode = new ListNode(sum % 10);
            carry = sum / 10;
            s->next = newNode;
            s = s->next;
            p = p->next;
            q = q->next;
        }
        ListNode* r = p != nullptr? p: q;
        while (r != nullptr) {
            int sum = r->val + carry;
            ListNode* newNode = new ListNode(sum % 10);
            carry = sum / 10;
            s->next = newNode;
            s = s->next;
            r = r->next;
        }
        if (carry != 0) {
            ListNode* newNode = new ListNode(carry);
            s->next = newNode;
        }
        return c.next;
    }
};

