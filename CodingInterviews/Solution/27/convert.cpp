/*! Author: qwchen
 *! Date  : 2016-11-20
 *  27. 二叉搜索树与双向链表
 */ 

#include <iostream>

using namespace std;

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

