/*! Author: qwchen
 *! Date  : 2016-11-12
 * 13.在O(1)时间删除链表结点
 * 思路：如果给定要删除的结点，并不需要从头开始遍历找到结点的前一个结点。我们可以把当前要删除的结点的下一个结点的内容复制到当前结点，
 *       然后把问题转化为删除当前结点的下一个结点。(O(1))
 *       另外还需要注意几种情况：
 *       1.链表为空或者待删除的结点为空，直接返回就可以了。(O(1))
 *       2.待删除的结点是首节点，这时需要修改链表指针。(O(1))
 *       3.待删除的结点是尾结点，即该结点的next指针为空，就需要从头到尾进行遍历了。(O(n))
 * 总的时间复杂度：((n-1)O(1) + O(n)) / n = O(1)
 */

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int theVal):val(theVal),next(NULL){}
    ListNode(int theVal, ListNode* theNext):val(theVal),next(theNext){}
};

class Solution{
public:
    // ListNode** head 是指向指针的指针，这样才能修改head指针，如果是ListNode* head，只能修改head指针所指向的结点
    void deleteNode(ListNode** head, ListNode* deleteNode){
        if (*head == NULL || deleteNode == NULL) return;
        if (*head == deleteNode){
            *head = (*head)->next;
            delete deleteNode;
            deleteNode = NULL;
            return;
        }
        if (deleteNode->next == NULL){
            ListNode* p = *head;
            while(p->next != deleteNode) p = p->next;
            p->next = NULL;
            delete deleteNode;
            deleteNode = NULL;
            return;
        }
        ListNode* p = deleteNode;
        deleteNode = deleteNode->next;
        p->val = deleteNode->val;
        p->next = deleteNode->next;
        delete deleteNode;
        deleteNode = NULL;
    }
};


void testSolution(){
    ListNode* p5 = new ListNode(5);
    ListNode* p4 = new ListNode(4, p5);
    ListNode* p3 = new ListNode(3, p4);
    ListNode* p2 = new ListNode(2, p3);
    ListNode* p1 = new ListNode(1, p2);
    ListNode* p0 = new ListNode(0, p1);
    ListNode* head = p0;
    ListNode* p = head;
    while(p != NULL){
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
    Solution sol;
    sol.deleteNode(&head, p0); // 注意是&head，不是head
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
