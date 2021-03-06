/*! Author: qwchen
 *! Date  : 2016-11-13
 * 16. 反转链表
 * 思路：用3个指针p/q/s分别指向连续的3个结点，修改q的指针让其指向p；不断重复该过程，直到s指向NULL，次数q指向最后一个结点，再让q->next=p；返回q
 *       需要注意：1. 链表为空； 2. 链表只有一个结点
 * 时间复杂度：O(n)
 */

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x):val(x), next(NULL) {}
    ListNode(int x, ListNode* theNext):val(x), next(theNext){}
};

// 迭代解法
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if (pHead == NULL || pHead->next == NULL) return pHead; // 链表为NULL或者链表只有一个结点时，直接返回
        // p->q->s
        ListNode* p = pHead;
        ListNode* q = pHead->next;
        ListNode* s = pHead->next->next;
        pHead->next = NULL;  // 注意需要把原本的链表的头指针的next置为nullptr
        while(s != NULL){
            q->next = p;
            p = q;
            q = s;
            s = s->next;
        }
        q->next = p;
        return q;
    }
};

// 递归解法
class Solution2 {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if(pHead == nullptr) return nullptr;
        ListNode* q = reverse(pHead, pHead);
        q->next = nullptr;   // 注意最后一个节点的next要置为nullptr
        return pHead;
    }
    
    ListNode* reverse(ListNode* p, ListNode* &pHead) {
        if(p->next == nullptr) {
            pHead = p;
            return p;
        }
        ListNode* q = reverse(p->next, pHead);
        q->next = p;
        return p;
    }
};

void testSolution(){
    ListNode* p5 = new ListNode(5);
    ListNode* p4 = new ListNode(4, p5);
    ListNode* p3 = new ListNode(3, p4);
    ListNode* p2 = new ListNode(2, p3);
    ListNode* p1 = new ListNode(1, p2);
    ListNode* head = p1;
    ListNode* p = head;
    while(p != NULL){
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
    Solution2 sol;
    head = sol.ReverseList(head);
    p = head;
    while(p != NULL){
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
}

int main(){
    testSolution();
    return 0;
}