/*! Author: qwchen
 *! Date  : 2017-01-02
 *! 字符串与数组: 2.3
 *! 题目描述：
 *    实现一个算法，删除单向链表中间的某个结点，假定你只能访问该结点。
 *    给定带删除的节点，请执行删除操作，若该节点为尾节点，返回false，否则返回true
 */

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/

/*
 * 思路：
 *   直接将后继结点的值复制到当前结点，然后删除后继结点即可。
 *   注意到如果删除结点是最后一个结点，该方法无解，因此直接返回false
 * 时间复杂度：O(1)
 * 空间复杂度：O(1)
 */
class Solution {
public:
    bool removeNode(ListNode* pNode) {
        if (pNode == nullptr || pNode->next == nullptr) return false;
        pNode->val = pNode->next->val;
        ListNode* delNode = pNode->next;
        delete delNode;
        return true;
    }
};

