/*! Source: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
 *! Author: qwchen
 *! Date  : 2016-11-04
 * Solution 为该文件最优的方案
 */

#include <iostream>

using namespace std;

/*
 * 单链表结点
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/*
 * 遍历链表一次
 * 用两个指针first和second，开始移动first指针，当first指针指到第n+1结点时，才移动second指针，
 * 最终当first指针指导NULL位置时，second刚好指到要删除结点的前一个结点
 * 时间复杂度：O(n)，访问结点个数L
 * 空间复杂度：O(1)
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);  // 创建头结点，简化链表操作
        dummy->next = head;
        ListNode* first = dummy;
        ListNode* second = dummy;
        for (int i = 1; i <= n + 1; i++){
            if (first){
                first = first->next;
            } else {
                return dummy->next; // 如果n比链表长度还要长，则直接返回
            }
        }
        while(first){
            first = first->next;
            second = second->next;
        }
        ListNode* deleteNode = second->next;
        second->next = second->next->next;
        delete deleteNode;
        return dummy->next;
    }
};

/*
 * 遍历链表两次
 * 第一次遍历寻找链表的长度L，则倒数第n个结点就是正数第L-n+1个结点，其前一个结点就为L-n
 * 第一次遍历就是找到要删除结点的前一个结点，就可以删除要删除的结点了
 * 时间复杂度：O(n)，访问结点个数2L-n
 * 空间复杂度：O(1)
 */
class Solution1 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* headNode = new ListNode(0);  // 创建头结点，简化链表操作
        headNode->next = head;
        ListNode* p = headNode->next;
        int lenOfList = 0;
        while(p){
            p = p->next;
            lenOfList++;
        }
        int m = lenOfList - n;  // m是倒数第n个结点的前一个结点的正数序号
        if (m < 0) return headNode->next;  // n比链表长度还要长，则直接返回
        p = headNode;
        while(m > 0){
            p = p->next;
            m--;
        }
        ListNode* deleteNode = p->next;
        p->next = p->next->next;
        delete deleteNode;
        return headNode->next;
    }
};


void testSolution(){
    ListNode* head = new ListNode(1);
    Solution solution;
    ListNode* newList = solution.removeNthFromEnd(head, 1);
    ListNode* p = newList;
    cout << "[";
    while(p){
        cout << p->val << " ";
        p = p->next;
    }
    cout << "]" << endl;
}

int main(){
    testSolution();
    return 0;
}