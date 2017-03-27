/*! Author: qwchen
 *! Date  : 2016-11-8
 * 5：从尾到头打印链表
 *   递归解法比较简洁。但是有一个问题，当链表非常长的时候，
 *   就会导致函数调用的层级很深，从而可能导致函数调用栈的溢出。
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
/*
 * 思路：用一个栈先保存从头到尾保存链表，出栈时就是从尾到头打印链表
 * 时间复杂度：O(n)
 * 空间复杂度：O(n)
 */
class Solution1 {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
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

/*
 * 思路：递归解法
 * 时间复杂度：O(n)
 * 空间复杂度：O(n)
 */
class Solution2 {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> res;
        if (head == nullptr) return res;
        helper(head, res);
        return res;
    }

    void helper(ListNode* head, vector<int>& res) {
        if (head->next == nullptr) {
            res.push_back(head->val);
            return;
        }
        helper(head->next, res);
        res.push_back(head->val);
    }
};

void testSolution(){
    // 链表 1 -> 2 -> 3 -> 4 -> 5
    ListNode *p5 = new ListNode(5);
    ListNode *p4 = new ListNode(4, p5);
    ListNode *p3 = new ListNode(3, p4);
    ListNode *p2 = new ListNode(2, p3);
    ListNode *head = new ListNode(1, p2);
    Solution2 sol;
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

