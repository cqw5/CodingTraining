/*! Author: qwchen
 *! Date  : 2016-11-8
 * 5：从尾到头打印链表
 * 思路：用一个栈先保存从头到尾保存链表，出栈时就是从尾到头打印链表
 * 时间复杂度：O(n)
 * 空间复杂度：O(n)
 */

#include <iostream>
#include <stack>
#include <vector>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x):val(x), next(NULL) {}
    ListNode(int x, ListNode* next):val(x), next(next){};
};

class Solution {
public:
    vector<int> printListFromTailToHead(struct ListNode* head) {
        vector<int> result;
        if (!head) return result;
        ListNode* p = head;
        stack<int> s;
        while(p != NULL){
            s.push(p->val);
            p = p->next;
        }
        while(!s.empty()){
            result.push_back(s.top());
            s.pop();
        }
        return result;
    }
};

void testSolution(){
    // 链表 1 -> 2 -> 3 -> 4 -> 5
    ListNode *p5 = new ListNode(5);
    ListNode *p4 = new ListNode(4, p5);
    ListNode *p3 = new ListNode(3, p4);
    ListNode *p2 = new ListNode(2, p3);
    ListNode *head = new ListNode(1, p2);
    Solution sol;
    vector<int> result = sol.printListFromTailToHead(head);
    for (int val: result){
        cout << val << " ";
    }
    cout << endl;
}

int main(){
    testSolution();
    return 0;
}