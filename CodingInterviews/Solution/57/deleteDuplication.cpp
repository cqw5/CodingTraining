/*! Author: qwchen
 *! Date  : 2016-11-30
 *  57. 删除链表中重复的节点
 *  题目描述：
 *    在一个排序的链表中，存在重复的节点，请删除该链表中重复的节点，重复的节点不保留，返回链表头指针。 
 *    例如，链表1->2->3->3->4->4->5，处理后为 1->2->5
 */

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
    ListNode(int x, ListNode* theNext): val(x), next(theNext) {}
};

/*
 * 思路：
 *   用两个指针pre和p，p指向当前节点，pre指向p的前一个节点，用一个标记needDel标记当前节点是否该删除
 *   如果当前节点的下一个节点与当前节点相同，则删除下一个节点，并将needDel置为true以标记当前节点后续也应该删除
 *   如果当前节点的下一个节点与当前节点不同：
 *     如果needDel为true，说明当前节点应该删除，删除当前节点并将p指向下一个节点
 *     否则，pre和p都向前移动一位
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead) {
        if (pHead == nullptr) {
            return nullptr;
        }
        ListNode dummp(0);
        dummp.next = pHead;
        ListNode* pre = &dummp;
        ListNode* p = pre->next;
        bool needDel = false;
        while (p->next != nullptr) {
            if (p->val == p->next->val) {
                ListNode* deleteNode = p->next;
                p->next = deleteNode->next;
                delete deleteNode;
                needDel = true;
            }
            else {
                if (needDel) {
                    ListNode* deleteNode = p;
                    p = p->next;
                    pre->next = p;
                    delete deleteNode;
                    needDel = false;
                }
                else {
                    pre = p;
                    p = p->next;
                }
            }
        }
        if (needDel) {
            pre->next = p->next;
            delete p;
        }
        return dummp.next;
    }
};

void testSolution() {
    ListNode* p7 = new ListNode(5);
    ListNode* p6 = new ListNode(4, p7);
    ListNode* p5 = new ListNode(4, p6);
    ListNode* p4 = new ListNode(3, p5);
    ListNode* p3 = new ListNode(3, p4);
    ListNode* p2 = new ListNode(2, p3);
    ListNode* p1 = new ListNode(1, p2);
    Solution sol;
    ListNode* head = sol.deleteDuplication(p1);
    for (ListNode* p = head; p != nullptr; p = p->next) {
        cout << p->val << " ";
    }
    cout << endl;
}

int main() {
    testSolution();
    return 0;
}

