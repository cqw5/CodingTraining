/*! Author: qwchen
 *! Date  : 2016-11-20
 *  27. 二叉搜索树与双向链表
 *  题目：输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的循环双向链表。要求不能创建任何新的节点，只能调整树中节点指针的指向。
 */ 

#include <iostream>

using namespace std;
/*
 * 思想：二叉搜索树的中序遍历为 递增序列 。将 二叉搜索树 转换成一个 “排序的循环双向链表” ，其中包含三个要素：
 *      排序链表： 节点应从小到大排序，因此应使用 中序遍历 “从小到大”访问树的节点。
 *      双向链表： 在构建相邻节点的引用关系时，设前驱节点 pre 和当前节点 cur，不仅应构建 pre.right = cur，也应构建 cur.left = pre。
 *      循环链表： 设链表头节点 head 和尾节点 tail，则应构建 head.left = tail 和 tail.right = head。
 */
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (root == NULL) return root;
        inOrder(root);
        head->left = pre;
        pre->right = head;
        return head;
    }
private:
    Node* pre = NULL;
    Node* head = NULL;
    void inOrder(Node* cur) {
        if (cur != NULL) {
            inOrder(cur->left);
            if (pre == NULL) head = cur;
            else pre->right = cur;
            cur->left = pre;
            pre = cur;
            inOrder(cur->right);
        }
    }
    
};


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x):val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode* left, TreeNode* right):val(x), left(left), right(right) {}
};

/*
 * 思想：后序遍历二叉树，递归的将当前结点的左子树和右子树分别表示为双向链表，让通过当前节点进行链接
 *       需要注意的是，结点的左子树和右子树可能同时为空，也可能有一个为空，也可能都不为空。
 */
class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree) {
        pair<TreeNode*, TreeNode*> list = treeToList(pRootOfTree);
        return list.first;
    }

private:
    // pair.first指向链表的首节点，pair.second指向链表的尾结点
    pair<TreeNode*, TreeNode*> treeToList(TreeNode* root) {
        if (root == nullptr) {
            return make_pair(nullptr, nullptr);
        }
        TreeNode* head = nullptr;
        TreeNode* tail = nullptr;
        pair<TreeNode*, TreeNode*> left = treeToList(root->left);
        pair<TreeNode*, TreeNode*> right = treeToList(root->right);
        if (left.first == nullptr && right.first == nullptr) {
            head = root;
            tail = root;
        }
        else if (left.first == nullptr) {
            root->right = right.first;
            right.first->left = root;
            head = root;
            tail = right.second;
        }
        else if (right.first == nullptr) {
            root->left = left.second;
            left.second->right = root;
            head = left.first;
            tail = root;
        }
        else {
            root->left = left.second;
            left.second->right = root;
            root->right = right.first;
            right.first->left = root;
            head = left.first;
            tail = right.second;
        }
        return make_pair(head, tail);
    }
};


void testSolution() {
    TreeNode* t4 = new TreeNode(4);
    TreeNode* t8 = new TreeNode(8);
    TreeNode* t6 = new TreeNode(6, t4, t8);
    TreeNode* t12 = new TreeNode(12);
    TreeNode* t16 = new TreeNode(16);
    TreeNode* t14 = new TreeNode(14, t12, t16);
    TreeNode* t10 = new TreeNode(10, t6, t14);
    Solution sol;
    TreeNode* list = sol.Convert(t10);
    TreeNode* p = list;
    while(p->right != nullptr) {
        cout << p->val << " ";
        p = p->right;
    }
    cout << p->val << endl;
    while(p != nullptr) {
        cout << p->val << " ";
        p = p->left;
    }
    cout << endl;
}

int main() {
    testSolution();
    return 0;
}

