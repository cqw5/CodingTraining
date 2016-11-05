/*! Source: https://leetcode.com/problems/swap-nodes-in-pairs/
 *! Author: qwchen
 *! Date  : 2016-11-04
 * Solution 为该文件最优的方案
 * test数据只用于测试是否语法错误，完整的测试见LeetCode。
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
 * 使用3个指针：p1指向要交换的两个元素之前的元素，p2和p3分别指向要交换的两个元素的第一个和第二个
 * 注意考虑当链表为空或者长度为1的情况，和链表长度是奇数或偶数的情况
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head; // 链表为空或者只有一个元素时，直接返回
        ListNode dummp(0);
        dummp.next = head;
        for(ListNode *p1 = &dummp, *p2 = p1->next, *p3 = p2->next; 
            p3 != nullptr;
            p1 = p2, p2 = p1->next, p3 = p2? p2->next: nullptr) { // p3 = p2? p2->next: nullptr; 考虑了链表长度为奇数或偶数的情况
            p1->next = p3;
            p2->next = p3->next;
            p3->next = p2;
            // 此时p2和p3交换了，p2指向第二个元素，p3指向第三个元素
        }
        return dummp.next;
    }
};


/*
 * 使用两个指针：p指向要交换的两个元素之前的元素，q指向要交换的两个元素的之后的元素
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */
class Solution2 {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode dummp(0);
        dummp.next = head;
        ListNode* p = &dummp;
        ListNode* q = NULL;
        if (p->next->next){
            q = p->next->next->next;
        }
        while(q){
            p->next->next->next = p->next;
            p->next = p->next->next;
            p->next->next->next = q;
            p = p->next->next;
            if(p->next->next){
                q = p->next->next->next;
            } else {
                q = NULL;
            }
        }
        if(p->next->next){
            p->next->next->next = p->next;
            p->next = p->next->next;
            p->next->next->next = q;
        }
        return dummp.next;
    }
};

void testSolution(){
    ListNode* head = new ListNode(1);
    ListNode* p = head;
    for (int i = 2; i <= 8; i++){
    	p->next = new ListNode(i);
    	p = p->next;
    }
    cout << "[";
    for (p = head; p != NULL; p = p->next){
    	cout << p->val << " ";
    }
    cout << "]" << endl;
    Solution sol;
    // Solution2 sol;
    ListNode* newLinkList = sol.swapPairs(head);
    cout << "[";
    for(p = newLinkList; p != NULL; p = p->next){
    	cout << p->val << " ";
    }
    cout << "]" << endl;
}

int main(){
    testSolution();
    return 0;
}