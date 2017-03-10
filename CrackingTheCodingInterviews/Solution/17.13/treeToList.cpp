/*! Author: qwchen
 *! Date  : 2017-03-10
 *! 递归：17.13 树转链表
 *! 题目描述：
 *    有一个类似结点的数据结构TreeNode，包含了val属性和指向其它结点的指针。
 *    其可以用来表示二叉查找树(其中left指针表示左儿子，right指针表示右儿子)。
 *    请编写一个方法，将二叉查找树转换为一个链表，其中二叉查找树的数据结构用TreeNode实现，链表的数据结构用ListNode实现。
 *    给定二叉查找树的根结点指针root，请返回转换成的链表的头指针。
 */

/*
struct TreeNode {
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/

/*
 * 思路：
 *   将二叉查找树转化为有序链表，注意到二叉查找树中序遍历就是有序的
 *   将root的左子树和右子树分别转化为链表，然后通过当前结点进行连接
 * 时间复杂度：O(n)
 * 空间复杂度：O(n)
 */
class Converter {
public:
    ListNode* treeToList(TreeNode* root) {
        if (root == nullptr) return nullptr;
        pair<ListNode*, ListNode*> list = treeToListHelp(root);
        return list.first;
    }
    
    pair<ListNode*, ListNode*> treeToListHelp(TreeNode* root) {
        ListNode* front = nullptr;
        ListNode* tail = nullptr;
        if (root == nullptr) {
            return make_pair(front, tail);
        }
        pair<ListNode*, ListNode*> left = treeToListHelp(root->left);
        pair<ListNode*, ListNode*> right = treeToListHelp(root->right);
        ListNode* node = new ListNode(root->val);
        if (left.second == nullptr && right.first == nullptr) {
            front = node;
            tail = node;
        }
        else if (left.second == nullptr) {
            front = node;
            node->next = right.first;
            tail = right.second;
        }
        else if (right.first == nullptr) {
            front = left.first;
            left.second->next = node;
            tail = node;
        }
        else {
            front = left.first;
            left.second->next = node;
            node->next = right.first;
            tail = right.second;
        }
        return make_pair(front, tail);
    }
};


