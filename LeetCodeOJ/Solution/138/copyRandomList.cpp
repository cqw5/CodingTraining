/*! Source: https://leetcode.com/problems/copy-list-with-random-pointer
 *! Author: qwchen
 *! Date  : 2017-05-02
 *  复制复杂链表
 */

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
/*
 * 思路
 *   复制链表的每个结点，并连接在该结点后面。
 *   复制新节点的random指针。
 *   将复制的结点从原始链表中拆分出来，构成新的链表。
 * 时间复杂度：O(n). 59 ms. beats 34.91 % of cpp submissions.
 * 空间复杂度：O(n)
 */
class Solution {
public:
    RandomListNode* copyRandomList(RandomListNode *head) {
        if (head == nullptr) return nullptr;
        return split(random(copy(head)));
    }
    
    RandomListNode* copy(RandomListNode *head) {
        RandomListNode* p = head;
        while(p != nullptr) {
            RandomListNode* q = new RandomListNode(p->label);
            q->next = p->next;
            p->next = q;
            p = q->next;
        }
        return head;
    }
    
    RandomListNode* random(RandomListNode *head) {
        RandomListNode* p = head;
        while (p != nullptr) {
            if (p->random != nullptr) {
                p->next->random = p->random->next;
            }
            p = p->next->next;
        }
        return head;
    }
    
    RandomListNode* split(RandomListNode *head) {
        RandomListNode dummp(0);
        RandomListNode* p = head;
        RandomListNode* q = &dummp;
        while (p != nullptr) {
            q->next = p->next;
            q = q->next;
            p->next = q->next;
            p = p->next;
        }
        return dummp.next;
    }
};

