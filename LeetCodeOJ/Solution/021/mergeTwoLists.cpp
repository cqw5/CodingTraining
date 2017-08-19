/*! Source: https://leetcode.com/problems/merge-two-sorted-lists/
 *! Author: qwchen
 *! Date  : 2016-11-04
 * Solution 为该文件最优的方案
 * test数据来自LeetCode，只用于测试是否语法错误，完整的测试见LeetCode。
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
 * 将两个有序链表合并
 * 注意链表为空的情况，另外使用头结点可以简化代码
 * 时间复杂度：O(m+n)
 * 空间复杂度：O(1)
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        ListNode* l3 = new ListNode(0);
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        ListNode* p3 = l3;
        while(p1 && p2){
            if (p1->val <= p2->val){
                p3->next = p1;
                p1 = p1->next;
            } else {
                p3->next = p2;
                p2 = p2->next;
            }
            p3 = p3->next;
        }
        if(p1){
            p3->next = p1;
        }
        if(p2){
            p3->next = p2;
        }
        return l3->next;
    }
};

/*
 * 递归写法
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;
        ListNode* l3;
        if(l1->val <= l2->val) {
            l3 = l1;
            l3->next = mergeTwoLists(l1->next, l2);
        }
        else {
            l3 = l2;
            l3->next = mergeTwoLists(l1, l2->next);
        }
        return l3;
    }
};

void testSolution(){
    ListNode* l1 = new ListNode(2); // [2, 7]
    ListNode* l2 = new ListNode(1); // [1, 6]
    l1->next = new ListNode(7);
    l2->next = new ListNode(6);
    Solution solution;
    ListNode* l3 = solution.mergeTwoLists(l1, l2);
    cout << "[";
    ListNode* p = l3;
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