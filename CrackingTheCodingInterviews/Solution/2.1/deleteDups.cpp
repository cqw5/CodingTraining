/*! Author: qwchen
 *! Date  : 2017-01-01
 *! 字符串与数组: 2.1
 *! 题目描述：
 *    移除未排序链表的重复结点
 */
#include <iostream>
#include <unordered_set>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode* theNext): val(x), next(theNext) {}
};

/*
 * 思路：
 *   用一个hash表记录链表中的元素。
 *   遍历链表，如果当前元素不在hash表中，将该元素插入到hash表中；如果在hash表中，说明该元素重复出现了，删除该元素。
 * 时间复杂度：O(n)
 * 空间复杂度：O(n)
 */
class Solution {
public:
    ListNode* deleteDups(ListNode* head) {
        ListNode dummp(0);
        dummp.next = head;
        unordered_set<int> hashTable;
        for (ListNode* p = &dummp; p->next != nullptr; ) {
            if (hashTable.find(p->next->val) != hashTable.end()) {
                ListNode* delNode = p->next;
                p->next = p->next->next;
                delete delNode;
            }
            else {
                hashTable.insert(p->next->val);
                p = p->next;
            }
        }
        return dummp.next;
    }
};


void testSolution() {
    ListNode* p5 = new ListNode(3);
    ListNode* p4 = new ListNode(3, p5);
    ListNode* p3 = new ListNode(20, p4);
    ListNode* p2 = new ListNode(8, p3);
    ListNode* p1 = new ListNode(8, p2);
    ListNode* head = new ListNode(15, p1);
    for (ListNode* p = head; p != nullptr; p = p->next) {
        cout << p->val << " ";
    }
    cout << endl;
    Solution sol;
    ListNode* newHead = sol.deleteDups(head);
    for (ListNode* p = newHead; p != nullptr; p = p->next) {
        cout << p->val << " ";
    }
    cout << endl;
}

int main() {
    testSolution();
    return 0;
}
