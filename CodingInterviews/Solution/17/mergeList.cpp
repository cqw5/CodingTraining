/*! Author: qwchen
 *! Date  : 2016-11-13
 * 17. 合并两个排序的链表
 * 思路：不断的比较两个链表的首节点，将其中较小的去下路加入到新的链表中；最终又一个链表会先变为NULL，此时将另一个非空的链表直接接入到合并的链表中
 *       需要注意，原始链表为空的情况
 * 时间复杂度: O(min(m, n))
 */

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x):val(x), next(NULL) {}
    ListNode(int x, ListNode* theNext):val(x), next(theNext){}
};

/*
 * 递归解法
 */
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        if (pHead1 == nullptr) return pHead2;
        if (pHead2 == nullptr) return pHead1;
        ListNode* p3;
        if (pHead1->val <= pHead2->val) {
            p3 = pHead1;
            p3->next = Merge(pHead1->next, pHead2);
        }
        else {
            p3 = pHead2;
            p3->next = Merge(pHead1, pHead2->next);
        }
        return p3;
    }
};

/*
 * 迭代解法
 */
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        if (pHead1 == NULL) return pHead2;
        if (pHead2 == NULL) return pHead1;
        ListNode* p1 = pHead1;
        ListNode* p2 = pHead2;
        ListNode dummy(0);
        ListNode* p3 = &dummy;
        while(p1 != NULL && p2 != NULL){
            if (p1->val <= p2->val){
                p3->next = p1;
                p1 = p1->next;
            } else {
                p3->next = p2;
                p2 = p2->next;
            }
            p3 = p3->next;
        }
        if (p1 != NULL) {
            p3->next = p1;
        }
        if (p2 != NULL) {
            p3->next = p2;
        }
        return dummy.next;
    }
};

void testSolution(){
    // list1 [1, 3, 5, 7]
    ListNode* p14 = new ListNode(7);
    ListNode* p13 = new ListNode(5, p14);
    ListNode* p12 = new ListNode(3, p13);
    ListNode* p11 = new ListNode(1, p12);
    ListNode* head1 = p11;
    // list2 [2, 4]
    ListNode* p22 = new ListNode(4);
    ListNode* p21 = new ListNode(2, p22);
    ListNode* head2 = p21;
    Solution sol;
    ListNode* p3 = sol.Merge(head1, head2);
    while (p3 != NULL){
        cout << p3->val << " ";
        p3 = p3->next;
    }
    cout << endl;
}

int main(){
    testSolution();
    return 0;
}