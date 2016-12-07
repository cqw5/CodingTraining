/*! Source: https://leetcode.com/problems/rotate-list/
 *! Author: qwchen
 *! Date  : 2016-12-07
 * Solution 为该文件最优的方案
 * test数据只用于测试是否语法错误，完整的测试见LeetCode。
 */

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode* theNext) : val(x), next(theNext) {}
};

/*
 * 思路：
 *   求链表的长度，对让k对链表长度取模，结果k就会小于链表长度了
 *   当k == 0，就不用翻转了
 *   否则找到倒数第k个结点的前一个结点(正数第(lenOfList - k)个结点)
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || k < 1) {
            return head;
        }
        ListNode dummp(0);
        dummp.next = head;
        int lenOfList = 0;
        ListNode* p = &dummp;
        while(p->next != nullptr) {
            lenOfList++;
            p = p->next;
        }
        k = k % lenOfList;
        if (k > 0) {
            ListNode* q = &dummp;
            for (int i = 0; i < lenOfList - k; i++) {
                q = q->next;
            }
            p->next = head;
            head = q->next;
            q->next = nullptr;
        }
        return head;
    }
};


void testSolution() {
    ListNode* p5 = new ListNode(5);
    ListNode* p4 = new ListNode(4, p5);
    ListNode* p3 = new ListNode(3, p4);
    ListNode* p2 = new ListNode(2, p3);
    ListNode* head = new ListNode(1, p2);
    for (ListNode* p = head; p != nullptr; p=p->next) {
        cout << p->val << " ";
    }
    cout << endl;
    int k = 2;
    Solution sol;
    head = sol.rotateRight(head, k);
    for (ListNode* p = head; p != nullptr; p=p->next) {
        cout << p->val << " ";
    }
    cout << endl;
}

int main() {
    testSolution();
    return 0;
}

