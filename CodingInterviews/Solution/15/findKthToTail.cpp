/*! Author: qwchen
 *! Date  : 2016-11-13
 * 15. 链表中倒数第k个结点
 * 思路：用两个指针p和q，p先出发走k步，然后q再出发，p与q相距k，当p走到NULL时，q刚好走到倒数第k个位置。
 *       此外还要考虑：1.链表为空； 2.k<=0； 3.k>链表长度，以确保代码的鲁棒
 * 时间复杂度：O(n)，只遍历链表一遍
 */

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x):val(x), next(NULL) {}
    ListNode(int x, ListNode* theNext):val(x), next(theNext){}
};

class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if (pListHead == NULL || k <= 0) return NULL; // 链表为空 或 k<=0 时
        ListNode dummy(0);
        dummy.next = pListHead;
        ListNode *p = &dummy;
        for (int i = 1; i <= k; i++){
            p = p->next;
            if (p == NULL){
                return NULL;
            }
        }
        ListNode *q = &dummy;
        while(p != NULL){
            p = p->next;
            q = q->next;
        }
        return q;
    }
};

void testSolution(){
    ListNode* p3 = new ListNode(3, NULL);
    ListNode* p2 = new ListNode(2, p3);
    ListNode* p1 = new ListNode(1, p2);
    ListNode* head = p1;
    for (ListNode* p = head; p != NULL; p=p->next){
        cout << p->val << " ";
    }
    cout << endl;
    Solution sol;
    cout << sol.FindKthToTail(head, 2)->val << endl;
}

int main(){
    testSolution();
    return 0;
}