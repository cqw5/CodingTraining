/*! Author: qwchen
 *! Date  : 2016-11-22
 *  37. 两个链表的第一个公共结点
 *  Solution是最佳解法
 */

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};*/

/*
 * 思路：
 *   遍历第一个链表，将链表每一个元素存放在一个hash表组织的set中；
 *   遍历第二个链表，对第一个链表中的每一个元素判断其是否在set中，如果在说明是重复元素，直接返回该结点
 * 时间复杂度：O(m+n)
 * 空间复杂度：O(m)或O(n)
 */
class Solution1 {
public:
    ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
        if (pHead1 == nullptr || pHead2 == nullptr) {
            return nullptr;
        }
        ListNode* p1 = pHead1;
        ListNode* p2 = pHead2;
        unordered_set<ListNode*> dict;
        while (p1 != nullptr) {
            dict.insert(p1);
            p1 = p1->next;
        }
        while (p2 != nullptr) {
            if (dict.find(p2) != dict.end()) {
                return p2;
            }
            p2 = p2->next;
        }
        return nullptr;
    }
};


/*
 * 思路：
 *   如果两个链表用公共结点，那么这两个链表从某一结点开始，他们的next指针都是指向同一个结点，基于这一规律：
 *   由于用栈可以实现链表从后向前遍历，可以使用两个栈分布存放两个链表，出栈顺序就是从后向前遍历链表
 *   不断出栈，直到遇到两个栈顶元素不同时，那么前一个出栈的结点就是两个链表的第一个公共结点
 * 时间复杂度：O(m+n)
 * 空间复杂度：O(m+n)
 */
class Solution2 {
public:
    ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
        if (pHead1 == nullptr || pHead2 == nullptr) {
            return nullptr;
        }
        stack<ListNode*> s1, s2;
        pushStack(pHead1, s1);
        pushStack(pHead2, s2);
        ListNode* p = nullptr;
        while (!s1.empty() && !s2.empty()) {
            if (s1.top() != s2.top()) {
                break;
            }
            else {
                p = s1.top();
                s1.pop();
                s2.pop();
            }
        }
        return p;
    }

private:
    void pushStack(ListNode* p, stack<ListNode*>& s) {
        while (p != nullptr) {
            s.push(p);
            p = p->next;
        }
    }

};

/*
 * 思路：
 *   如果两个链表用公共结点，那么这两个链表从某一结点开始，他们的next指针都是指向同一个结点，基于这一规律：
 *   分别求出两个链表的长度，计算其差值diff，用指针p1指向比较长的链表，p2指向比较短的链表
 *   让长链表的指针p1先走diff步，此时两个链表剩下的长度就一样了
 *   同时移动p1和p2指针，当他们指向第一个相同元素时，该元素就是第一个相同元素
 * 时间复杂度：O(m+n)
 * 空间复杂度：O(1)
 */
class Solution3 {
public:
    ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
        if (pHead1 == nullptr || pHead2 == nullptr) {
            return nullptr;
        }
        int len1 = lenOfList(pHead1);
        int len2 = lenOfList(pHead2);
        ListNode* pLong = nullptr;
        ListNode* pShort = nullptr;
        int lenDiff = 0;
        if (len1 >= len2) {
            pLong = pHead1;
            pShort = pHead2;
            lenDiff = len1 - len2;
        }
        else {
            pLong = pHead2;
            pShort = pHead1;
            lenDiff = len2 - len1;
        }
        while (lenDiff != 0) {
            pLong = pLong->next;
            lenDiff--;
        }
        while (pLong != nullptr && pShort != nullptr && pLong != pShort) {
            pLong = pLong->next;
            pShort = pShort->next;
        }
        return pLong;
    }
    
private:
    int lenOfList(ListNode* p) {
        int len = 0;
        while (p != nullptr) {
            len++;
            p = p->next;
        }
        return len;
    }
};

/* 
 * 思路:
 *     两个指针，第一个先遍历A，再遍历B；第二个先遍历B，再遍历A；如果有公共节点，一点会在公共节点处相遇。
 * /
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *A = headA, *B = headB;
        while (A != B) {
            A = A != nullptr ? A->next : headB;
            B = B != nullptr ? B->next : headA;
        }
        return A;
    }
};



