/*! Author: qwchen
 *! Date  : 2017-01-02
 *! 字符串与数组: 2.7
 *！题目描述：
 *    请编写一个函数，检查链表是否为回文。
 *    给定一个链表ListNode* pHead，请返回一个bool，代表链表是否为回文。
 *！测试样例：
 *    {1,2,3,2,1}
 *    返回：true
 *    {1,2,3,2,3}
 *    返回：false
 */

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/

/*
 * 思路：
 *   将链表前半部分逆序，保存为另一个链表，然后逐一比较这两个链表对应的元素是否相同。
 *   因为链表长度未知，因此使用快指针（每次走两步）和慢指针（每次走一步），当快指针走到链表结尾时，慢指针刚好就走到链表中间。
 *   注意链表长度是奇数还是偶数。
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */
class Solution {
public:
    bool isPalindrome(ListNode* pHead) {
        if (pHead == nullptr) return false;
        ListNode dummp1(0);
        dummp1.next = pHead;
        ListNode dummp2(0);
        ListNode* p = &dummp1;
        // 如果在p->next == nullptr退出，说明链表元素有偶数个
        // 如果在p->next->next == nullptr退出，说明链表元素有奇数个
        while (p->next != nullptr && p->next->next != nullptr) {
            p = p->next->next;
            ListNode* moveNode = dummp1.next;
            dummp1.next = moveNode->next;
            moveNode->next = dummp2.next;
            dummp2.next = moveNode;
        }
        if (p->next == nullptr) p = dummp1.next;
        else                    p = dummp1.next->next; // 若链表有奇数个元素，跳过中间元素
        ListNode* q = dummp2.next;
        // 逐一判断两个链表的对应元素是否相等
        while (p != nullptr) {
            if (p->val != q->val) return false;
            p = p->next;
            q = q->next;
        }
        return true;
    }
};

