/*! Author: qwchen
 *! Date  : 2017-01-02
 *! 字符串与数组: 2.4
 *! 题目描述：
 *    编写代码，以给定值x为基准将链表分割成两部分，所有小于x的结点排在大于或等于x的结点之前。
 *    给定一个链表的头指针 ListNode* pHead，请返回重新排列后的链表的头指针。注意：分割以后保持原来的数据顺序不变。
 */

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/

/*
 * 思路：
 *   将链表拆分成两两个，一个所有元素都小于x，一个所有元素都大于等于x，然后将这两个链表合并
 *   具体是，遍历原始链表，将原始链表中每一个小于x的结点到一个新的链表中，
 *   最后原始链表中所有元素都大于等于x，而新的链表中所有元素都小于x，合并这两个链表即可。
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */
class Partition {
public:
    ListNode* partition(ListNode* pHead, int x) {
        if (pHead == nullptr || pHead->next == nullptr) return pHead;
        ListNode headGreater(0);
        headGreater.next = pHead;
        ListNode headLess(0);
        ListNode* pGreater = &headGreater;
        ListNode* pLess = &headLess;
        while (pGreater->next != nullptr) {
            if (pGreater->next->val < x) {
                pLess->next = pGreater->next;
                pLess = pLess->next;
                pGreater->next = pLess->next;
            }
            else {
                pGreater = pGreater->next;
            }
        }
        pLess->next = headGreater.next;
        return headLess.next;
    }
};

