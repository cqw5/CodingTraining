/*! Source: https://leetcode.com/problems/add-two-numbers/
 *! Author: qwchen
 *! Date  : 2016-10-31
 */

#include <iostream>

using namespace std;

// 单链表的结构体
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/*
 * 链表操作，使用头结点可以简化代码，只是多用了一个结点，不会增加空间复杂度
 * 该题目要注意输入的4种情况：
 *     - l1和l2长度相等，且不进位。l1 = [0, 1], l2 = [3, 4]
 *     - l1比l2长。                l1 = [1, 2, 3], l2 = [4, 5]
 *     - l2比l1长。                l1 = [1, 2], l2 = [3, 4, 5]
 *     - 最后一位会进位。          l1 = [9, 9], l2 = [1]
 * 时间复杂度：O(max(m, n))
 * 空间复杂度：O(max(m, n))
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l3 = new ListNode(0);  // 使用头结点来简化代码
        ListNode* currentNode = l3;
        ListNode* p = l1;
        ListNode* q = l2;
        int currentValue = 0;
        while(p != NULL && q != NULL){  // 合并l1和l2等长部分
            currentValue += p->val + q->val;
            currentNode->next = new ListNode(currentValue % 10); // 取个位数部分
            currentValue /= 10;  // 保留进位
            currentNode = currentNode->next;
            p = p->next;
            q = q->next;
        }
        while(p != NULL){  // 若l1比较长
            currentValue += p->val;
            currentNode->next = new ListNode(currentValue % 10);
            currentValue /= 10;
            currentNode = currentNode->next;
            p = p->next;
        }
        while(q != NULL){  // 若l2比较长
            currentValue += q->val;
            currentNode->next = new ListNode(currentValue % 10);
            currentValue /= 10;
            currentNode = currentNode->next;
            q = q->next;
        }
        if(currentValue != 0){  // 最后一步还有进位
            currentNode->next = new ListNode(currentValue);
        }
        return l3->next; // 去掉头结点
    }
};

int testSolution(){
    ListNode *l1 = NULL, *p = NULL;
    l1  = p = new ListNode(2);
    p->next = new ListNode(4);
    p = p->next;
    p->next = new ListNode(3);

    ListNode *l2 = NULL, *q = NULL;
    l2  = q = new ListNode(5);
    q->next = new ListNode(6);
    q = q->next;
    q->next = new ListNode(4);

    Solution solution;
    ListNode *l3 = solution.addTwoNumbers(l1, l2);
    ListNode *s = l3;
    while(l3 != NULL){
        cout << l3->val << " ";
        l3 = l3->next;
    }
    cout << endl;

}

int main(){
    testSolution();
    return 0;
}