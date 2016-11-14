/*! Source: https://leetcode.com/problems/binary-tree-postorder-traversal/
 *! Author: qwchen
 *! Date  : 2016-11-14
 * 二叉树的后序遍历
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorderSeq;
        postorder(root, postorderSeq);
        return postorderSeq;
    }

private:
    void postorder(TreeNode* root, vector<int>& postorderSeq){
        if (root != nullptr){
            postorder(root->left, postorderSeq);
            postorder(root->right, postorderSeq);
            postorderSeq.push_back(root->val);
        }
    }
};

/*
 * 迭代解法
 */
class Solution2 {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorderSeq;
        stack<TreeNode*> s;
        TreeNode* p = root;
        TreeNode* pre = nullptr;
        while(p != nullptr || !s.empty()){
            while(p != nullptr){
                s.push(p);
                p = p->left;
            }
            if (!s.empty()){
                p = s.top();
                if (p->right == nullptr || p->right == pre){
                    postorderSeq.push_back(p->val);
                    pre = p;
                    s.pop();
                    p = NULL;
                }
                else {
                    p = p->right;
                }
            }
        }
        return postorderSeq;
    }
};