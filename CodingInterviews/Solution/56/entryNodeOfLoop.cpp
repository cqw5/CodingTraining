/*! Author: qwchen
 *! Date  : 2016-11-30
 *  56. 链表中环的入口结点
 *  题目描述
 *  一个链表中包含环，请找出该链表的环的入口结点。
 *  注意，该题虽然这么说，但还是要判断链表是否不存在环
 *  Solution比Solution更简单
 */

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
    ListNode(int x, ListNode* theNext): val(x), next(theNext) {}
};

/*
 * 思路：
 *   设环的起始点距离链表起点的长度为a，环的长度为b+c，两个指针fast和slow
 *   第一步，寻找环中相汇点。
 *     让fast每次走两步，slow每次走一步，同时从起点出发，那么当slow走a步到达环的起点，再走b步与fast相遇，则slow走的步数为a+b，
 *     此时fast走了 a+b+n*(b+c)
 *     由于fast每次走两步，slow每次走一步，那有 a+b+n*(b+c) = 2(a+b)，推导出 a = (n-1)*(+c) + c，也就是a = c
 *   第二步，寻找环的入口。
 *     另slow重新指向链表起点，fast还是指向上一步slow与fast的相汇点，同时都每次一步移动，最终fast和slow相汇点就是环的起点（这时刚好走了c步）。
 */
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead) {
        if (pHead == nullptr) return nullptr;
        ListNode dummp(0);
        dummp.next = pHead;
        ListNode* pFast = &dummp;
        ListNode* pSlow = &dummp;
        while (pFast != nullptr && pFast->next != nullptr) {
            pSlow = pSlow->next;
            pFast = pFast->next->next;
            if (pSlow == pFast) break;
        }
        if (pFast == nullptr || pFast->next == nullptr) return nullptr;
        pSlow = &dummp;
        while (pSlow != pFast) {
            pSlow = pSlow->next;
            pFast = pFast->next;
        }
        return pFast;
    }
};


/*
 * 思路：
 *     如果知道环的长度len，那么我们只需要设一个快指针和一个慢指针，快指针先走len步，然后慢指针再走，当快指针和慢指针重合时，该结点就是环的入口
 *     现在问题转化为求环的长度？
 *     同样设一个快指针和一个慢指针，快指针一次走两步，慢指针一次走一步，如果存在环，那么快指针最终会追到慢指针，并且在环内追上。
 *     注意链表不存在环的情况，需要每一步都判断当前指针是否为空，若空则一定不存在环，返回null
 * 时间复杂度：O(n)? 在环内，快指针和慢指针走到重合可能要循环多次。 
 * 空间复杂度：O(1)
 */
class Solution1 {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead) {
        if (pHead == nullptr) {
            return nullptr;
        }
        ListNode dummp(0);
        dummp.next = pHead;
        int len = lenOfLoop(&dummp);
        if (len == 0) {   // 链表长度为0，一定不存在环
            return nullptr;
        }
        ListNode* pFast = &dummp;
        ListNode* pSlow = &dummp;
        for (int i = 0; i < len; i++) {
            pFast = pFast->next;
        }
        while(pSlow != pFast) {
            pSlow = pSlow->next;
            pFast = pFast->next;
        }
        return pSlow;
    }

private:
	/*
	 * 求链表环的长度
	 * 如果指针指向空，说明不存在环，返回长度0
	 */
    int lenOfLoop(ListNode* pHead) {
        int len = 0;
        ListNode* pSlow = pHead->next;  // 慢指针，每次走1步
        if (pSlow == nullptr) {
            return 0;
        }
        ListNode* pFast = pHead->next->next;  // 快指针，每次走两步
        if (pFast == nullptr) {
            return 0;
        }
        while(pFast != pSlow) {
            pSlow = pSlow->next;
            pFast = pFast->next;
            if (pFast == nullptr || pFast->next == nullptr) {
                return 0;
            }
            pFast = pFast->next; 
        }
        len++;
        pSlow = pSlow->next;
        while (pSlow != pFast) {
            pSlow = pSlow->next;
            len++;
        }
        return len;
    }
};


void testSolution() {
    ListNode* p5 = new ListNode(5);
    ListNode* p4 = new ListNode(4, p5);
    ListNode* p3 = new ListNode(3, p4);
    ListNode* p2 = new ListNode(2, p3);
    ListNode* p1 = new ListNode(1, p2);
    ListNode* head = new ListNode(0, p1);
    p5->next = p2;
    Solution sol;
    ListNode* entryNodeOfLoop = sol.EntryNodeOfLoop(head);
    cout << entryNodeOfLoop->val << endl;
}

int main() {
    testSolution();
    return 0;
}

