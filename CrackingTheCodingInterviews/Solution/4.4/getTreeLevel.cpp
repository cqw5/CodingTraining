/*! Author: qwchen
 *! Date  : 2017-01-07
 *! 树和图: 4.4 输出单层结点
 *！题目描述：
 *      对于一棵二叉树，请设计一个算法，创建含有某一深度上所有结点的链表。
 *      给定二叉树的根结点指针TreeNode* root，以及链表上结点的深度，请返回一个链表ListNode，代表该深度上所有结点的值，
 *      请按树上从左往右的顺序链接，保证深度不超过树的高度，树上结点的值为非负整数且不超过100000。
 */

/*
// 树节点
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/

/*
// 链表节点
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/

/*
 * 思路：
 *   对二叉树进行先序遍历，遍历到第dep层就把该层节点接到链表尾部
 *   先序遍历时，第dep层以下的节点不需要再遍历
 *   注意链表要传引用指针
 * 时间复杂度：O(n)
 * 空间复杂度：O(m) m为第dep的节点个数
 */
class TreeLevel {
public:
    ListNode* getTreeLevel(TreeNode* root, int dep) {
        ListNode dummp(0);
        ListNode* p = &dummp;
        dfs(root, dep, 1, p);
        return dummp.next;
    }


private:
    void dfs(TreeNode* root, int dep, int level, ListNode* &p) {
        if(root == nullptr) return;
        if(level == dep) {
            ListNode* q = new ListNode(root->val);
            p->next = q;
            p = p->next;
            return;
        }
        dfs(root->left, dep, level+1, p);
        dfs(root->right, dep, level+1, p);
    }
};

