/*! Source: https://leetcode.com/problems/binary-tree-preorder-traversal/
 *! Author: qwchen
 *! Date  : 2016-11-14
 * 二叉树的先序遍历
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorderSeq;
        preorder(root, preorderSeq);
        return preorderSeq;
    }
    
private:
    void preorder(TreeNode* root, vector<int>& preorderSeq){
        if (root != nullptr){
            preorderSeq.push_back(root->val);
            preorder(root->left, preorderSeq);
            preorder(root->right, preorderSeq);
        }
    }
};

/*
 * 迭代解法
 */
class Solution2 {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorderSeq;
        stack<TreeNode*> s;
        TreeNode* p = root;
        while(p != nullptr || !s.empty()){
            while(p != nullptr){
                preorderSeq.push_back(p->val);
                s.push(p);
                p = p->left;
            }
            if (!s.empty()){
                p = s.top();
                p = p->right;
                s.pop();
            }
        }
        return preorderSeq;
    }
};