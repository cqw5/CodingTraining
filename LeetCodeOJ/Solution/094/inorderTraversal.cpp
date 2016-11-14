/*! Source: https://leetcode.com/problems/binary-tree-inorder-traversal/
 *! Author: qwchen
 *! Date  : 2016-11-14
 * 二叉树的中序遍历
 * Solution1是递归解法，题目要求使用非递归解法，见Solution2
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

/*
 * 递归解法
 */
class Solution1 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorderSeq;
        inorder(root, inorderSeq);
        return inorderSeq;
    }
private:
    void inorder(TreeNode* root, vector<int>& inorderSeq){
        if (root != nullptr){
            inorder(root->left, inorderSeq);
            inorderSeq.push_back(root->val);
            inorder(root->right, inorderSeq);
        }
    }
};

/*
 * 迭代解法
 */
class Solution2 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorderSeq;
        stack<TreeNode*> s;
        TreeNode* p = root;
        while(p != nullptr || !s.empty()){
            while(p != nullptr){
                s.push(p);
                p = p->left;
            }
            if (!s.empty()){
                p = s.top();
                inorderSeq.push_back(p->val);
                p = p->right;
                s.pop();
            }
        }
        return inorderSeq;
    }
};

