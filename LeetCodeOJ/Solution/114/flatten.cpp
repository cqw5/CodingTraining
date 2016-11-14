/*! Source: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
 *! Author: qwchen
 *! Date  : 2016-11-14
 * 将二叉树转化成链表
 * 思想：递归的进行求解，将根节点root的左子树变成链表leftList，将根节点的右子树变成链表rightList，将leftList插在root和rightList之间。(注意要将root->left置为nullptr)
 *       - 递归的终止条件是，节点为空。
 *       - 递归过程是递归将左子树转化为链表leftList、右子树转化为链表rightList，返回链表的头尾指针leftList.head,leftList.tail,rightList.head,rightList.tail
 *       - 每一次递归后需要执行的操作是：将左子树链表leftList插入到根节点root与右子树链表rightList之间。注意需要考虑：
 *           - leftList和rightList都为空
 *           - leftList空，rightList非空
 *           - leftList非空，rightsit为空
 *           - leftList和rightList都不为空
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        flattenToList(root);
    }

private:
    /*
     * 将以root为根的子树转化为链表
     * Parament:
     *     root: 需要转化为链表的子树的根
     * Return:
     *     pair.first: 指向链表头的指针
     *     pair.second: 指向链表尾的指针
     */
    pair<TreeNode*, TreeNode*> flattenToList(TreeNode* root){
        // 空树返回空链表
        if (root == nullptr){
            return make_pair(nullptr, nullptr);
        }
        TreeNode* head = nullptr;  // 指向链表头的指针
        TreeNode* tail = nullptr;  // 指向链表尾的指针
        pair<TreeNode*, TreeNode*> leftList = flattenToList(root->left);    // 左子树转化为链表
        pair<TreeNode*, TreeNode*> rightList = flattenToList(root->right);  // 右子树转化为链表
        if (leftList.first == nullptr && rightList.first == nullptr){ // 左右子树都为空
            head = root;
            tail = root;
        }
        else if (leftList.first == nullptr){  // 左子树为空，但右子树不为空
            head = root;
            tail = rightList.second;
        }
        else if (rightList.first == nullptr){ // 左子树不为空，但右子树为空
            root->left = nullptr;
            root->right = leftList.first;
            head = root;
            tail = leftList.second;
        }
        else { // 左右子树都不为空
            root->left = nullptr;
            root->right = leftList.first;
            leftList.second->right = rightList.first;
            head = root;
            tail = rightList.second;
        }
        return make_pair(head, tail);
    }
};

