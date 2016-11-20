/*! Author: qwchen
 *! Date  : 2016-11-19
 *  26. 复杂链表的复制
 */

#include <iostream>
#include <unordered_map>

using namespace std;

/*
 * 复杂链表的节点
 */
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};

/*
 * 思路1：
 *     第一步：遍历一次原始链表，复制每一个节点，并设置next指针，random指针先全部置为null。
 *     第二步：寻找每个节点random指针，由于每个节点的random指针可能指向其前面的节点，也可能指向其后面的节点，因此寻找从头到位进行寻找。
 * 时间复杂度：O(n^2)
 * 空间复杂度：O(1)
 */
class Solution1 {
public:
    RandomListNode* Clone(RandomListNode* pHead) {
        RandomListNode* p = pHead;
        RandomListNode dummy(0);    // 复杂后的链表加上一个头节点，简化操作
        RandomListNode* q = &dummy;
        // 第一步
        while (p != nullptr) {
            q->next = new RandomListNode(p->label);
            p = p->next;
            q = q->next;
        }
        // 第二步
        p = pHead;
        q = dummy.next;
        while (p != nullptr) {
            RandomListNode* ps = pHead;
            RandomListNode* qs = dummy.next;
            while (ps != p->random) {
                ps = ps->next;
                qs = qs->next;
            }
            q->random = qs;
            p = p->next;
            q = q->next;
        }
        return dummy.next;
    }
};

/*
 * 思路2：对思路1进行改进，以空间换时间
 *     第一步：遍历一次原链表，复制每一个节点，并设置next指针，random指针先全部置为null；同时用hash表表示原始链表的一个节点到复制链表的一个节点的映射
 *     第二步：再遍历一次原链表，此时原链表当前节点hash对应的复制节点的random指针指向 原链表当前节点的random指针指向的节点hash对应的复制节点。
 * 时间复杂度：O(n)
 * 空间复杂度：O(n)
 */
class Solution2 {
public:
    RandomListNode* Clone(RandomListNode* pHead) {
        RandomListNode* p = pHead;
        RandomListNode dummy(0);
        RandomListNode* q = &dummy;
        unordered_map<RandomListNode*, RandomListNode*> src2copy;
        while (p != nullptr) {
            q->next = new RandomListNode(p->label);
            q = q->next;
            src2copy[p] = q;
            p = p->next;
        }
        p = pHead;
        q = dummy.next;
        while (p != nullptr) {
            src2copy[p]->random = src2copy[p->random];
            p = p->next;
        }
        return dummy.next;
    }
};


/*
 * 思路3：只需要遍历3次链表
 *     第一次：遍历链表，对每个节点创建一个复制节点，并将节点的复制节点连接在其后面
 *     第二次：设置复制节点的random指针。由于每个节点的复制节点都接在该节点后面，因此每个节点的复制节点的random指针指向该节点的random指针的想一个节点
 *     第三次：当前的链表是原节点和复制节点相间的，遍历一次链表，将偶数位置的节点拆出来构成复制节点
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */
class Solution3 {
public:
    RandomListNode* Clone(RandomListNode* pHead) {
        cloneNode(pHead);
        randomPoint(pHead);
        return splitList(pHead);
    }

private:
    void cloneNode(RandomListNode* pHead) {
        RandomListNode* p = pHead;
        while (p != nullptr) {
            RandomListNode* q = new RandomListNode(p->label);
            q->next = p->next;
            p->next = q;
            p = q->next;
        }
    }
    
    void randomPoint(RandomListNode* pHead) {
        RandomListNode* p = pHead;
        while (p != nullptr) {
            //p->next->random = p->random->next;
            if (p->random != nullptr) {
                p->next->random = p->random->next;
            }
            p = p->next->next;
        }
    }
    
    RandomListNode* splitList(RandomListNode* pHead) {
        RandomListNode* p = pHead;
        RandomListNode dummp(0);
        RandomListNode* q = &dummp;
        while (p != nullptr) {
            q->next = p->next;
            p = p->next->next;
            q = q->next;
        }
        return dummp.next;
    }
};


void testSolution(){
    // {1,2,3,4,5,3,5,#,2,#}
    RandomListNode* p1 = new RandomListNode(1);
    RandomListNode* p2 = new RandomListNode(2);
    RandomListNode* p3 = new RandomListNode(3);
    RandomListNode* p4 = new RandomListNode(4);
    RandomListNode* p5 = new RandomListNode(5);
    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p5;
    p1->random = p3;
    p2->random = p5;
    p3->random = nullptr;
    p4->random = p2;
    p5->random = nullptr;
    Solution3 sol;
    RandomListNode* p = sol.Clone(p1);
    while (p != nullptr) {
        if (p->random != nullptr) {
            cout << p->label << " " << p->random->label << endl;
        } else {
            cout << p->label << " NULL" << endl;
        }
        
        p = p->next;
    }
}

int main(){
    testSolution();
    return 0;
}

